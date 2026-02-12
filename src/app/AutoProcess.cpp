#include <QElapsedTimer>         // 用於簡單逾時計時
#include <QThread>               // 用於 msleep（讓輪詢不會佔滿 CPU）
#include <QMessageBox>          // 顯示錯誤訊息對話框
#include <QMediaPlayer>         //載入音檔所需
#include <QAudioOutput>         //載入音檔所需
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDate>
#include <qdir.h>
#include <qregularexpression.h>

#include "ConnectDevice.h"
#include "Automation.h"
#include "PowerCheck.h"

using namespace std;

const double Proportion = 0.94;
const int dacAddto = 20;

void readValueInFile(const QString& filePath, vector<double> sdac, vector<double> power);
QString vecToQString(const vector<double>& v);

AutoP::AutoP(QObject* parent, MeterDevice* meter, LaserDriver* laser, Simulation* simulation)
    : QObject(parent)     // 建構子初始化列表
    , meter_(meter)
    , laser_(laser)
    , Simulation_(simulation)
    , currentStatus(STOPPED)
    , program(0)
    , filelog(new QFile("log.txt"))
    , log(new QTextStream)
    , regex1("PD_protection:\\s*(\\d+(?:\\.\\d+)?)")
    , regex2("PD_Value \\s*(\\d+(?:\\.\\d+)?)")         // PD_Value:
    , regex3("Output_PD_protection:\\s*(\\d+(?:\\.\\d+)?)")
    , regex4("PD2_Value \\s*(\\d+(?:\\.\\d+)?)")        // PD2_Value:

{
    Ld_fit.m = 0;
    Ld_fit.l = 0;
    Laser_fit.m = 0;
    Laser_fit.l = 0;

    countPD = 0;


}

AutoP:: ~AutoP()
    {}

void AutoP::AutoPinit() {
    processTimer = new QTimer(this);
    processTimer->setSingleShot(false);
    PDTimer = new QTimer(this);
    PDTimer->setSingleShot(false);

    connect(processTimer, &QTimer::timeout, this, &AutoP::processStep);
    connect(PDTimer, &QTimer::timeout, this, [this]() {
        if (currentStatus == PAUSED) {PDTimer->stop(); return;}
        if (currentStatus == STOPPED || currentStatus == ERRO) {PDTimer->stop(); return;}
        countPD ++;
        sendcommand("RPD");          // 量測PD值
        if(countPD == 5){
            countPD = 0;
            PDTimer->stop();
        }
    });
    connect(this, &AutoP::PDerror, this, [=]() {
        emit errorSignal("ERROR","PD_value異常");
        if(PDvalueCheckOpen) errorProcess();
    });
}

void AutoP::initialization() {
    if(isInit == true) {emit statusText("已初始化"); return ;}
    isInit = true;
    qDebug() << "進入程序";
    emit statusText("初始化程序");
    program = 0;
    //dacSet = 0;
    //dacRrange = 0;
    //dacAdd = 0;

    sendcommand("DCD");
    sendcommand("DOPD");
    sendcommand("poweron");
    sendcommand("DLE");
    sendcommand("DEC");
    sendcommand("DMOD");
    sendcommand("EMON");
    emit statusText("初始化程序完成");
}

void AutoP::startProcess1() {
    if (currentStatus == RUNNING || currentStatus == PAUSED) {
        emit statusText("需等待程序完成或終止");
        return;
    }
    if(isInit == false) {emit statusText("尚未初始化"); return ;}
    qDebug() << "初始化程序1";
    program = 1;
    dacSet = 0;
    qDebug() << "設定vecter size";
    setValue.clear();
    measured.clear();

    currentStatus = RUNNING;
    emit statusText("開始程序LD Test");
    qDebug() << "開始程序1" << "\n"<< "開始計時器";
    processTimer->start(loop_msWait);  // 立即啟動定時執行

    processStep();
}

void AutoP::startProcess2() {
    if (currentStatus == RUNNING || currentStatus == PAUSED) {
        emit statusText("需等待程序完成或終止");
        return;
    }
    if(isInit == false) {emit statusText("尚未初始化"); return ;}
    qDebug() << "初始化程序2";
    program = 2;
    dacSet = 0;

    qDebug() << "設定vecter size";
    setValue.clear();
    measured.clear();

    currentStatus = RUNNING;
    emit statusText("開始程序Laser Test");
    qDebug() << "開始程序2" << "\n"<< "開始計時器";
    processTimer->start(loop_msWait);  // 立即啟動定時執行

    processStep();
}

void AutoP::startProcess3() {
    if (currentStatus == RUNNING || currentStatus == PAUSED) {
        emit statusText("需等待程序完成或終止");
        return;
    }
    if(isInit == false) {emit statusText("尚未初始化"); return ;}
    qDebug() << "初始化程序3";
    program = 3;
    dcSet = 0;

    qDebug() << "設定vecter size";
    setValue.clear();
    measured.clear();
    //PD2.resize(10*5);
    PD1.clear();
    PD2.clear();

    currentStatus = RUNNING;
    emit statusText("開始程序PD Test");
    qDebug() << "開始程序3" << "\n"<< "開始計時器";
    processTimer->start(loop_msWait);  // 立即啟動定時執行

    processStep();
}

void AutoP::processStep() {
    if (currentStatus == STOPPED) {
        qDebug() << "程式即將完成";
        endFitting();
        finishProcess();
        return;
    }

    if(currentStatus == ERRO) {
        qDebug() << "程序發生問題";
        return;
    }

    if (currentStatus == PAUSED) {  // 保持 timer 運作但不做事情
        QTimer::singleShot(100, this, &AutoP::processStep);
        qDebug() << "程序暫停等待恢復";
        return;
    }
    if (PausetoRun == true) { PausetoRun = false; powerLoop(); return ;} // 暫停到恢復時，不執行 power check

    //量測上一次loop所設定的power數值
    qDebug() << "meter量測開始";
    double powerLimit = powerLaserLimit;
    LinearFitResult fit = Laser_fit;
    // 依程式決定紀錄方式
    switch (program) {
    case 1:
        powerLimit = powerPDLimit;
        fit = Ld_fit;
        break;
    case 2:

        break;
    case 3:
        qDebug() << "PD保護檢測中...";
        //if(PD_valueOpen && dacSet >= 0) protectionCheck();
        if(dacSet >= 0) protectionCheck();

        break;
    default:
        errorProcess();
        return ;
    }
    // 取得meter的值
    double takepower;
    if(Simulation_->isSimulation == true) {
        PowerCheck powerCheck;
        if (fit.m != 0) {
            powerCheck.m = fit.m;
            powerCheck.l = fit.l;
        }
        takepower = powerCheck.predictLinear(dacSet);}
    else takepower = takeMeterPower();            // 取得meter值
    if(takepower  == -10) {
        errorProcess();
        emit errorSignal("ERROR","無法解析功率回覆");
        playmusicWithWarning("無法解析功率回覆");
    }
    if(takepower >= powerLimit) {
        qDebug() << "takepower 大於 powerLimit";
        currentStatus = STOPPED;
    }
    if(takepower >= powerLimit*Proportion) {
        qDebug() << "takepower 大於 powerLimit*Proportion";
        dacAdd = dacAddto;
    }
    qDebug() << QString("目前dacDdd為: %1").arg(dacAdd);

    // 檢測開始
    qDebug() << "檢測meter結果是否符合預期";
    if ((program != 3) && measureCheckOpen && !measureCheck(takepower, dacSet, fit)) {
        errorProcess();
        emit errorSignal("ERROR",QString("Power set %1時功率未達標").arg(dacSet));
        playmusicWithWarning(QString("Power set %1時功率未達標").arg(dacSet));
        qDebug() << QString("Power set %1時功率未達標").arg(dacSet);
    }

    pushData(takepower);

    powerLoop();  // 執行一次你的步驟
}

void AutoP::pushData(double data) {
    // 儲存量測的資料
    qDebug() << "將數據儲存....";
    int set = dacSet;
    if(program == 3) set = dcSet;
    setValue.push_back(set);
    measured.push_back(data);
}

void AutoP::endFitting() {
    // 將量測結果做擬和
    testFit = linearFit(setValue, measured);
    if(program == 2) {
        resultFit1 = fitting(measured,setValue);
    }
    if(program == 3) {
        vector<double> x = pdAverageVector(PD1);
        resultFit1 = fitting(measured, x);
        x = pdAverageVector(PD2);
        resultFit2 = fitting(measured, x);
    }
}


void AutoP::finishProcess() {
    processTimer->stop();
    isInit = false;
    powerOff();
    emit processFinished();
    emit statusText("程序已完成");
}

void AutoP::pauseProcess() {
    processTimer->stop();
    currentStatus = PAUSED;
    isInit = false;
    progStack = program;
    powerOff();
    emit statusText("程序已暫停");
}

void AutoP::resumeProcess() {
    if (currentStatus == PAUSED) {
        dacSet -= dacAdd;           // 恢復時，從上次的DAC開始
        program = progStack;
        PausetoRun = true;
        currentStatus = RUNNING;
        emit statusText("程序已恢復執行");
    }
}

void AutoP::stopProcess() {
    processTimer->stop();   // 立即停止，不等待 ms_wait
    currentStatus = STOPPED;
    isInit = false;
    powerOff();
    emit statusText("程序已停止");
}

void AutoP::errorProcess() {
    processTimer->stop();
    currentStatus = ERRO;
    isInit = false;
    powerOff();
    emit statusText("程序發生錯誤");
}

void AutoP::powerOff() {
    QTimer::singleShot(100, this, [this]() {
        sendcommand("sdac10");
        QTimer::singleShot(100, this, [this]() {
            sendcommand("sdac20");
            QTimer::singleShot(100, this, [this]() {
                sendcommand("sdac30");
                QTimer::singleShot(100, this, [this]() {
                    sendcommand("poweroff");
                });
            });
        });
    });
    isInit = false;
}

void AutoP::powerLoop() {
    qDebug() << "進入迴圈";
    if (currentStatus == PAUSED) return;
    if (currentStatus == STOPPED || currentStatus == ERRO) return;
    switch (program) {
    case 3:
        dcSet += 10;
        if(dcSet > 100) {
            dcSet = 0;
            currentStatus = STOPPED;
        }else{
            sendcommand(QString("SDC%1 ").arg(dcSet));     //設定雷射功率
        }
        break;
    default:
        dacSet += dacAdd;
        if (dacSet > dacRrange) {                                                      //超過範圍跳出迴圈
            dacSet = 0;
            currentStatus = STOPPED;
        }else{
            sendcommand(QString("SDAC1%1 ").arg(dacSet));     //設定雷射功率
        }
        break;
    }
    qDebug() << "離開迴圈";
    return ;
}

void AutoP::sendcommand(const QString& command) {
    if(Simulation_->isSimulation) {emit addCommandtoLog(command); return;}
    laser_->sendAndWait(command);
}

double AutoP::takeMeterPower() {
    //if(dacSet == 0 && dcSet == 0) return 0;
    QByteArray ans;                                                         // 用於儲存回覆
    if(!meter_) {qDebug() << "meter未連線"; return 0;}
    if(!meter_->sendAndRead("*OUTPM:", ans)) {qDebug() << "送出讀功率指令失敗"; return -10;}
    double p = 0.0;                                                         // 用於接收轉換後的瓦特值
    if (meter_->parseFloatAnswer(ans, p)) {                                 // 解析成功
        emit powerDoub("PW",QString::number(p, 'f', 3));                // 對外通報新的功率數值
        qDebug() << "目前Power:" << p;
        return p;

    } else {                                                                // 解析失敗（字串不是浮點數）
        qDebug() << QString("無法解析功率回覆：%1").arg(QString::fromLatin1(ans));
        return -10;
    }
}

bool AutoP::measureCheck(double measured, double setvalue,LinearFitResult fit) const {
    PowerCheck powerCheck;
    if (fit.m != 0) {
        powerCheck.m = fit.m;
        powerCheck.l = fit.l;
    }
    double tol;
    if(setvalue < tol_divide) {tol = low_tol; }else tol = high_tol;
    if(setvalue < 120) return true;
    switch (program) {
    case 1:
        return powerCheck.isLDPowerNormal(measured, setvalue, tol);     //功率未達標則return false
    case 2:
        return powerCheck.isLaserPowerNormal(measured, setvalue, tol);     //功率未達標則return false
    default:
        return false;
    }
}

bool AutoP::protectionCheck() {
    // 防呆：確保 laser_ 與 PDTimer 已初始化
    if (!laser_) {
        qCritical() << "laser_ 尚未初始化，無法啟動保護檢查";
        return false;
    }
    if (!PDTimer) {
        qCritical() << "PDTimer 尚未初始化";
        return false;
    }

    // 若已存在連線，先斷開
    if (protectionConnection_) {
        disconnect(protectionConnection_);
        protectionConnection_ = {};
    }

    // 建立新的具名連線
    protectionConnection_ = connect(laser_, &LaserDriver::serialRead, this, [this](const QString& rawLine) {
        QString line = rawLine.trimmed();
        if (line.isEmpty()) return;

        qDebug() << "PD_check接收到：" << line;
        //qDebug() << "Line (hex):" << line.toUtf8().toHex();
        //qDebug() << "Line (text):" << line;
        const auto match1 = regex1.match(line.trimmed());
        const auto match2 = regex2.match(line.trimmed());
        const auto match3 = regex3.match(line.trimmed());
        const auto match4 = regex4.match(line.trimmed());

        //const auto matchLaser = regex2.match(line.trimmed());
        //const auto matchBack  = regex4.match(line.trimmed());

        if (match1.hasMatch() && !(match3.hasMatch())) {
            pendingPD_protection = match1.captured(1).toInt();
            qDebug() << "暫存 PD_protection" << *pendingPD_protection;
        }

        if (match2.hasMatch()) {
            int backPower = match2.captured(1).toInt();
            if (pendingPD_protection) {
                if (backPower > (*pendingPD_protection-100) && backPower < (*pendingPD_protection+100)){
                    PD1.push_back(backPower);
                    qDebug() << "配對成功：" << *pendingPD_protection << "<->" << backPower;
                    pendingPD_protection.reset();
                }else{ emit PDerror();}
            } else {
                qDebug() << "PD_Value 出現，但尚未有 PD_protection 暫存";
            }
        }

        if (match3.hasMatch()) {
            pendingOutput_PD_protection = match3.captured(1).toInt();
            qDebug() << "暫存 Output_PD_protection" << *pendingOutput_PD_protection;
        }

        if (match4.hasMatch()) {
            int backPower = match4.captured(1).toInt();
            if (pendingOutput_PD_protection) {
                if (backPower > (*pendingOutput_PD_protection-100) && backPower < (*pendingOutput_PD_protection+100)){
                    PD2.push_back(backPower);
                    qDebug() << "配對成功：" << *pendingOutput_PD_protection << "<->" << backPower;
                    pendingOutput_PD_protection.reset();
                }else{ emit PDerror();}
            } else {
                qDebug() << "PD2_Value 出現，但尚未有 Output_PD_protection 暫存";
            }
        }
    });

    // 啟動定時器
    PDTimer->start(loop_msWait/7);
    return true;
}

LinearFitResult AutoP::fitting(vector<double>& x, vector<double>& y) {
    LinearFitResult L;
    vector<double> m;
    if(x.empty() || y.empty()) return L;
    for(int i = 0; i < x.size(); ++i) {
        m.push_back(x[i]/x[x.size()-1]*1000);
    }
    if(program == 3) { L = linearFit(y,m); }else{ L = linearFit(m,y);}
    return L;
}

vector<double> AutoP::pdAverageVector(vector<int>& x) {
    vector<double> PD;
    int groupSize = 5;
    for(int i = 0; i + groupSize - 1 < x.size(); i += groupSize) {
        int pd = 0;
        for (int j = 0; j < groupSize; ++j) {
            pd += x[i+j];
        }
        double avg = static_cast<double>(pd) / groupSize;
        qDebug() << QString("PD %1平均值: %2").arg(i/5).arg(avg);
        PD.push_back(avg);
    }
    return PD;
}

QString AutoP::vecToQString(const vector<double>& x, const vector<double>& y) const
{
    QString result;
    for (int i = 0; i < x.size(); ++i) {
        qDebug() << x[i] <<" " << y[i] << "\n";
        result += QString::number(x[i]) + "\t" + QString::number(y[i]) + "\n";
    }
    return result;
}

QString AutoP::PDvecToQString(const vector<int>& x) const
{
    QString result;
    int groupSize = 5;

    for (int i = 0; i + groupSize - 1 < x.size(); i += groupSize) {
        QString xGroup;
        for (int j = 0; j < groupSize; ++j) {
            xGroup += QString::number(x[i + j]) + (j < groupSize - 1 ? " " : "");
        }
        result += xGroup + "\n";
    }

    return result;
}

void AutoP::playmusicWithWarning(const QString &msg) {
    // 建立音效播放器與音訊輸出
    QMediaPlayer* player = new QMediaPlayer(this);
    QAudioOutput* audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // 設定音效檔案（支援 MP3、WAV 等）
    player->setSource(QUrl::fromLocalFile(errorMusic));
    audioOutput->setVolume(0.8);

    // 播放音效
    player->play();
    player->setLoops(QMediaPlayer::Infinite);

    // 顯示警告視窗（阻塞式）
    QMessageBox msgBox;
    msgBox.setWindowTitle("programError");
    msgBox.setText(msg);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();

    // 使用者關閉視窗後，停止音效並釋放資源
    player->stop();
    player->deleteLater();
    audioOutput->deleteLater();
}

LoggerObject::LoggerObject(QObject* parent)
        : QObject(parent)
    {
        // 取得今天日期並建立檔名
        //QString dateStr = QDate::currentDate().toString("yyyyMMdd");
        QString dateStr = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
        QString fileName = QString("log_%1.txt").arg(dateStr);

        // 建立 log 資料夾
        QDir dir;
        if (!dir.exists("log")) {
            dir.mkpath("log"); // 建立 log 資料夾
        }
        // 建立 QFile 並開啟
        logFile = new QFile("log/"+fileName, this);
        if (!logFile->open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "無法開啟 log 檔案:" << logFile->errorString();
            return;
        }

        // 建立 QTextStream 並命名為 log
        log = new QTextStream(logFile);
        log->setEncoding(QStringConverter::Utf8);  //Qt6設訂編碼的方式

        // 寫入初始訊息
        *log << "Log 建立於 " << QDate::currentDate().toString("yyyy/MM/dd") << "\n";
    }

LoggerObject::~LoggerObject() {
    if (log) {
        delete log;
        log = nullptr;
    }

    if (logFile && logFile->isOpen()) {
        logFile->close();
    }
}

void LoggerObject::writeLog(const QString& message) {
    if (log) {
        *log << message << "\n";
        log->flush();
    }
}

void readValueInFile(const QString& filePath, vector<double> sdac, vector<double> power) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "無法開啟檔案:" << file.errorString();
        return;
    }
    //明天處理**********************************
    //vector<double> sdac(50);
    //vector<double> power(50);
    QTextStream in(&file);
    QRegularExpression regex1("DAC1:\\s*(\\d+(?:\\.\\d+)?)"); // 支援整數與小數
    QRegularExpression regex2("PW:\\s*(\\d+(?:\\.\\d+)?)"); // 支援整數與小數
    int lineNumber = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();

        lineNumber++;
        QRegularExpressionMatch match1 = regex1.match(line);
        QRegularExpressionMatch match2 = regex1.match(line);
        if (match1.hasMatch()) {
            QString numberStr = match1.captured(1); // 擷取第一個括號群組
            double dac = numberStr.toDouble();
            sdac.push_back(dac);   // 加入到尾端
            qDebug() << "找到 DAC1 的值：" << dac;
        }
        if (match1.hasMatch()) {
            QString numberStr = match2.captured(1); // 擷取第一個括號群組
            double pw = numberStr.toDouble();
            if(pw != 0) sdac.push_back(pw);   // 加入到尾端
            qDebug() << "找到 PW 的值：" << pw;
        }

        //double result = value*0.75;
        //qDebug() << result;
        //還未完成待寫完
    }

    file.close();
}





