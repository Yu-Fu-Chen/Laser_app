#include "MainWindow.h"                                             // 對應標頭
#include "src/Gui/ui_MainWindow.h"

#include <QMessageBox>                                              // 顯示錯誤訊息對話框
#include <QFileDialog>                                              // 檔案另存對話框
#include <QFile>                                                    // 檔案 I/O 物件
#include <QTextCursor>                                              // 操作 QTextEdit 游標（若需要）
#include <QElapsedTimer>
#include <QTimer>
#include <QThread>
#include <QSettings>
#include <QCloseEvent>
#include <QShortcut>
#include <QWidget>
#include <QtConcurrent>

MainWindow::MainWindow(QWidget* parent)                             // 建構子，初始化 UI 與訊號連接
    : QMainWindow(parent)                                           // 呼叫父類別建構子
    , ui(new Ui::MainWindow)                                        // 建立 UI 類別實例（由 .ui 生成）
    , Simulation_ (new Simulation(this))
    , sock_(new QTcpSocket(this))                                   // 建立 TCP Socket，設置父物件便於自動釋放
    , autoPThread(nullptr)
    , laser_(new LaserDriver(this))
    , Laser_meter_(new MeterDevice(this))
    , Thor_meter_(new ThorLABS_MeterDevice(this))
    , autoP_(new AutoP(this, Laser_meter_, laser_, Simulation_))

{
    ui->setupUi(this);    // 依 .ui 佈局建立所有元件並連接至 ui 成員
    baseSize_ = this->size();                 // 記錄初始窗口大小
    baseFontPointSize_ = this->font().pointSizeF(); // 記錄初始字體大小
    applyAdaptiveSpacing();  // 依螢幕比例調整一次 layout 間距
    setWindowTitle("LaserGUI (Qt Designer)");                      // 設定視窗標題

    // 建立自動化程序執行緒
    //autoPThread = new QThread(this);
    //autoP_->moveToThread(autoPThread);

    initWindowsUi();
    initLaser();
    initLaserMDevice();
    initThorMDevice();
    initAutoP();

}


MainWindow::~MainWindow() {                                           // 解構子：收尾資源
    if (sock_->isOpen()) sock_->close();                              // 若 TCP 還開著則關閉

    if (autoPThread->isRunning()) {
        autoPThread ->quit();
        autoPThread ->wait();
    }

    if(scanWatcher->isRunning()) {          // 若還在掃描ThorLabs_Meter，取消或等待它 (Watcher 會自動處理部分，但最好確保)
        scanWatcher->waitForFinished();
    }
    delete autoP_;
    delete laser_;
    delete Laser_meter_;
    delete Thor_meter_;
    delete ui;                                                        // 刪除 UI 物件（會遞迴刪其子元件）
}

void MainWindow::initWindowsUi() {
    ui->stackedWidget->setCurrentIndex(currentPage);
    // Enginerring Mode Login
    connect(ui->actionEngineering, &QAction::triggered, this, [this]() {
        openLogin();
    });
    // Working Mode
    connect(ui->actionworking, &QAction::triggered, this, [this]() {
        if(!login_) return ;
        login_->setlogin(false);
        setEnginerring(false);
    });

    // Action相關

    connect(ui->actionSetting, &QAction::triggered, this, [this]() {                                // setting
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->actionSimulation, &QAction::triggered, this, &MainWindow::openSimulation);      // simulation

    connect(ui->actionStress_Testing, &QAction::triggered, this, &MainWindow::openStressTest);      // Stress_Testing
    //QShortcut *shortcut = new QShortcut(QKeySequence("Shift+P"), this);
    //shortcut->setContext(Qt::ApplicationShortcut);
    connect(ui->actionSwitchPage, &QAction::triggered, this, [this]() {
        int page = (currentPage + 1) % 3;
        switchPage(page);
    });

    //(工具列)
    connect(ui->actSaveLog, &QAction::triggered, this, &MainWindow::saveLogToFile);   // 存檔
    connect(ui->actClearLog,&QAction::triggered, this, &MainWindow::clearLog);        // 清除

    //初始化設定
    refreshSConnect();                                          // 啟動時列舉一次可用的序列埠清單

    ui->sbTcpPort->setRange(1, 65535);                             // 設定 TCP Port 合法範圍
    ui->sbTcpPort->setValue(5000);                                 // 預設 TCP Port 5000
    ui->leTcpHost->setText("127.0.0.1");                           // 預設 Host 為本機


    // Baudrate 預設清單
    const QList<qint32> bauds = {9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600}; // 常見鮑率
    for (auto b : bauds) ui->cbBaud->addItem(QString::number(b), b); // 每個項目的 userData 存實際數值
    ui->cbBaud->setCurrentText("115200");                          // 預設 115200

    // Parity 選項
    ui->cbParity->addItem("None", QSerialPort::NoParity);          // 無同位元
    ui->cbParity->addItem("Even", QSerialPort::EvenParity);        // 偶數同位元
    ui->cbParity->addItem("Odd",  QSerialPort::OddParity);         // 奇數同位元
    ui->cbParity->addItem("Mark", QSerialPort::MarkParity);        // Mark
    ui->cbParity->addItem("Space",QSerialPort::SpaceParity);       // Space

    // Data bits 選項
    ui->cbDataBits->addItem("5", QSerialPort::Data5);              // 5 bits
    ui->cbDataBits->addItem("6", QSerialPort::Data6);              // 6 bits
    ui->cbDataBits->addItem("7", QSerialPort::Data7);              // 7 bits
    ui->cbDataBits->addItem("8", QSerialPort::Data8);              // 8 bits（常用）
    ui->cbDataBits->setCurrentText("8");                            // 預設 8 bits

    // Stop bits 選項
    ui->cbStopBits->addItem("1", QSerialPort::OneStop);            // 1 stop bit
#ifdef Q_OS_WIN                                                     // Windows 另有 1.5 停止位
    ui->cbStopBits->addItem("1.5", QSerialPort::OneAndHalfStop);   // 1.5 stop bits（僅 Windows 支援）
#endif
    ui->cbStopBits->addItem("2", QSerialPort::TwoStop);            // 2 stop bits

    // 切換連線頁面時的觸發事件
    connect(ui->tabChange, &QTabWidget::currentChanged, this, &MainWindow::refreshSConnect);
    connect(ui->tabConSwitch, &QTabWidget::currentChanged, this, &MainWindow::refreshSConnect);

    // 連線相關按鈕與事件
    connect(ui->btnLConnect, &QPushButton::clicked, this, &MainWindow::onConnectClicked); // Connect/Disconnect 按鈕

    // SDC or SDAC功率控制
    ui->cb_SDCorSDAC->addItem(QString("SDAC"));
    ui->cb_SDCorSDAC->addItem(QString("SDC"));
    ui->cb_SDCorSDAC->setCurrentIndex(0);
    changSDCorSDAC(ui->cb_SDCorSDAC->currentIndex());           // 設定範圍（60~950）
    connect(ui->cb_SDCorSDAC, &QComboBox::currentIndexChanged, this, [this](int index) {
        changSDCorSDAC(index);
    });
    QObject::connect(ui->sL1, &QSlider::valueChanged, ui->spL1, &QSpinBox::setValue); // 滑桿 -> 數值框 同步
    QObject::connect(ui->spL1, QOverload<int>::of(&QSpinBox::valueChanged), ui->sL1, &QSlider::setValue); // 數值框 -> 滑桿 同步

    //PD相關按鈕設定
    ui->spL_PD->setRange(dacinit, dacRang);                               // 數值框範圍
    ui->spL_PD->setSingleStep(10);                                        // 單步進
    ui->spL_PD->setValue(150);                                            // 預設值150
    ui->cbPDx->addItem("SDAC1");
    ui->cbPDx->addItem("SDAC2");
    ui->cbPDx->addItem("SDAC3");
    LaserDriver Laser;
    ui->dspDT->setRange(Laser.intervalMs, 5000);

    // 指令與雷射控制事件綁定
    connect(ui->btnPowerOn,  &QPushButton::clicked, this, [=]() {sendCommand("poweron");});  // Power ON
    connect(ui->btnPowerOff, &QPushButton::clicked, this, [=]() {sendCommand("poweroff");}); // Power OFF
    connect(ui->btnDCD,  &QPushButton::clicked, this, [=]() {sendCommand("DCD");});
    connect(ui->btnDOPD,  &QPushButton::clicked, this, [=]() {sendCommand("DOPD");});
    connect(ui->btnEMON,  &QPushButton::clicked, this, [=]() {sendCommand("EMON");});
    connect(ui->btnDLE,  &QPushButton::clicked, this, [=]() {sendCommand("DLE");});
    connect(ui->btnDEC,  &QPushButton::clicked, this, [=]() {sendCommand("DEC");});
    connect(ui->btnDMOD,  &QPushButton::clicked, this, [=]() {sendCommand("DMOD");});
    connect(ui->btnABN,  &QPushButton::clicked, this, [=]() {
        if(!laser_) return ;
        if(ui->btnABN->text() == tr("ABN")) {
            sendCommand("DEABC");
            sendCommand("ABN");
            ui->btnABN->setText(tr("ABF"));
        }else {
            sendCommand("ABF");
            ui->btnABN->setText(tr("ABN"));
        }
    });

    connect(ui->btnRPD, &QPushButton::clicked, this, [=]() {            // DP按鈕事件
        if(!laser_) return ;
        QString s = ui ->cbPDx->currentText();
        int v = ui->spL_PD->value();
        double wt = ui->dspDT->value();
        QTimer::singleShot(0, this, [=]() {
            sendCommand(s + QString("%1").arg(v));
            QTimer::singleShot(wt, this, [=]() {
                sendCommand("RPD");
                sendCommand("poweroff");
            });
        });
    });

    connect(ui->sL1, &QSlider::sliderReleased, this, [=]() {                                    // L1 改變後送出
        int v = ui->sL1->value();
        QString s = ui->cb_selectSDAC->currentText() + QString::number(v);
        MainWindow::sendCommand(s); });
    connect(ui->spL1, &QSpinBox::editingFinished, this, [=]() {
        int v = ui->spL1->value();
        QString s = ui->cb_selectSDAC->currentText() + QString::number(v);
        MainWindow::sendCommand(s); });


    connect(ui->btnSendCmd, &QPushButton::clicked, this, &MainWindow::sendArbitrary);             // 送出自訂命令按鈕
    connect(ui->leCmd, &QLineEdit::returnPressed, this, &MainWindow::sendArbitrary);              // Enter 送出自訂命令

    // TCP/Serial I/O 訊號
    connect(sock_,   &QTcpSocket::connected,    this, &MainWindow::onSocketConnected);    // TCP 連線成功
    connect(sock_,   &QTcpSocket::disconnected, this, &MainWindow::onSocketDisconnected); // TCP 斷線
    connect(sock_,   &QTcpSocket::readyRead,    this, &MainWindow::onSocketReadyRead);    // TCP 可讀
    connect(sock_,   &QTcpSocket::errorOccurred,this, &MainWindow::onErrorOccurred);      // TCP 錯誤

    // Laser_Meter 相關設定
    ui->cbWaveLen->addItem("Default");        // 預設
    ui->cbWaveLen->addItem("YAG");
    ui->cbWaveLen->addItem("LD");
    ui->cbWaveLen->addItem("VAS");

    // Laser_Meter 按鈕事件
    connect(ui->btn_LASERPOINT, &QPushButton::clicked, this, &MainWindow::onMConnectClicked); // 連接「Connect」按鈕到對應槽
    connect(ui->btnMSend, &QPushButton::clicked, this, &MainWindow::onbtnMSendClicked);   // Meter送出命令
    connect(ui->cbWaveLen, &QComboBox::currentTextChanged, this, [this](QString s) {        // 處理Wave設定); // Meter送出命令
        onMSWaveSelect(s);
    });
    connect(ui->btnMZero, &QPushButton::clicked, this, [=]() {Laser_meter_->sendCommand("ZERO");});

    // Thorlabs_Meter相關
    // 初始化 Watcher
    scanWatcher = new QFutureWatcher<QList<ThorLABS_MeterDevice::DeviceInfo>>(this);
    connect(scanWatcher, &QFutureWatcher<QList<ThorLABS_MeterDevice::DeviceInfo>>::finished,
            this, &MainWindow::onScanFinished);
    // 預設按鈕狀態
    ui->btn_ThorlabMeter->setEnabled(false);
    connect(ui->btn_ThorLabsMeterScan, &QPushButton::clicked, this, &MainWindow::onbtnScanClicked);
    connect(ui->btn_ThorlabMeter, &QPushButton::clicked, this, &MainWindow::onbtnThorMConnectCclicked);
    connect(ui->cbB_ThorlabMeter,&QComboBox::activated, this, [=]() {
        ui->frame_ThorlabMet->setFrameShape(QFrame::Box);   // 設定邊框形狀
        ui->frame_ThorlabMet->setFrameShadow(QFrame::Raised);
        QString s = ui->cbB_ThorlabMeter->currentText();
        ui->lbl_ThoDeviceIfo->setText(s); // 文字置中
    });
    connect(&MmeasureTimer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);

    // 視窗自動化程序部分
    // Parameter 儲存相關
    loadSettings("500W Laser");     // 載入設定

    ui->cbLaser_model->addItem("500W Laser");
    ui->cbLaser_model->addItem("1000W Laser");
    ui->cbLaser_model->addItem("5000W Laser");
    ui->cb_model->addItem("500W Laser");
    ui->cb_model->addItem("1000W Laser");
    ui->cb_model->addItem("5000W Laser");

    lineValidator(ui->lineLDfit_a, -100, 100, 4);
    lineValidator(ui->lineLDfit_b, -100, 100, 4);
    lineValidator(ui->lineLaser_fit_a, -100, 100, 4);
    lineValidator(ui->lineLaser_fit_b, -100, 100, 4);
    lineValidator(ui->lineLow_tol, 0, 1, 2);
    lineValidator(ui->lineHigh_tol, 0, 1, 2);
    lineValidator(ui->lineDAC_add, 0, 100);
    lineValidator(ui->lineDAC_range, dacinit, dacRang);
    lineValidator(ui->lineFit_dvide, dacinit, dacRang);

    // Function 相關
    ui->ckb_Fitting->setCheckState(Qt::Checked);
    ui->ckb_PD_value->setCheckState(Qt::Checked);
    connect(ui->ckb_Fitting, &QCheckBox::checkStateChanged, this, [=]() {
        if(ui->ckb_Fitting->checkState() == Qt::Checked) autoP_->measureCheckOpen = true;
        else autoP_->measureCheckOpen = false;
    });
    connect(ui->ckb_PD_value, &QCheckBox::checkStateChanged, this, [=]() {
        if(ui->ckb_PD_value->checkState() == Qt::Checked) autoP_->PDvalueCheckOpen = true;
        else autoP_->PDvalueCheckOpen = false;
    });

    // 依照選定 model 套用設定檔
    connect(ui->cbLaser_model, &QComboBox::currentIndexChanged, this, [=]() {
        QString selectedText = ui->cbLaser_model->currentText();
        loadSettings(selectedText);
    });
    connect(ui->btnParameter_save, &QPushButton::clicked, this, [=]() {
        QString selectedText = ui->cbLaser_model->currentText();
        saveSettings(selectedText);
    });

    connect(ui->btnParameter_enter, &QPushButton::clicked, this, [=]() {
        autoP_->dacAdd = ui->lineDAC_add->text().toInt();
        autoP_->dacRrange = ui->lineDAC_range->text().toInt();
        autoP_->Ld_fit.m = ui->lineLDfit_a->text().toDouble();
        autoP_->Ld_fit.l = ui->lineLDfit_b->text().toDouble();
        autoP_->Laser_fit.m = ui->lineLaser_fit_a->text().toDouble();
        autoP_->Laser_fit.l = ui->lineLaser_fit_b->text().toDouble();
        autoP_->tol_divide = ui->lineFit_dvide->text().toDouble();
        autoP_->low_tol = ui->lineLow_tol->text().toDouble();
        autoP_->high_tol = ui->lineHigh_tol->text().toDouble();
    });

    connect(ui->btnPInit, &QPushButton::clicked, this, [this]() {          // 初始化程序
        if(!laser_ && !Simulation_->isSimulation) {
            QMessageBox::warning(this, tr("Error"), tr("Device not connected."));      // 提示未連線
            return;
        }
        autoP_->initialization();
        selectedProgram = "Not selected";
        ui->lblSelect->setText(selectedProgram);
        qDebug() << "未選擇程式";
    });

    connect(ui->btnPRC1, &QPushButton::clicked, this, [&]() {
        selectedProgram = "LD Test";
        ui->lblSelect->setText(selectedProgram);
        qDebug() << "LD Test";
    });
    connect(ui->btnPRC2, &QPushButton::clicked, this, [&]() {
        selectedProgram = "Laser Test";
        ui->lblSelect->setText(selectedProgram);
        qDebug() << "Laser Test";
    });
    connect(ui->btnPRC3, &QPushButton::clicked, this, [&]() {
        selectedProgram = "PD Test";
        ui->lblSelect->setText(selectedProgram);
        qDebug() << "PD Test";
    });

    // Start 按鈕動作
    connect(ui->btnPStart, &QPushButton::clicked, this, [=]() {
        if (ui->btnLConnect->text() == tr("Connect")) {                                 //如果未連線
            QMessageBox::warning(this, tr("Serial Error"), tr("Not connected."));      // 提示未連線
            return;            // 中止
        }
        ui->teLog->clear();
        if (selectedProgram == "LD Test") {
            ui->teLog->append("LD Test started");
            autoP_->startProcess1();
        } else if (selectedProgram == "Laser Test") {
            ui->teLog->append("Laser Test started");
            autoP_->startProcess2();
        } else if (selectedProgram == "PD Test") {
            ui->teLog->append("PD Test started");
            autoP_->startProcess3();
        }else {
            showMessageBox(QMessageBox::Warning,
                           tr("Program Error"),
                           tr("Please select program."));
        }
    });

    connect(ui->btnPStop, &QPushButton::clicked, this, [=]() {
        if (ui->btnLConnect->text() == tr("Connect")) {                                 //如果未連線
            showMessageBox(QMessageBox::Warning,
                           tr("Serial Error"),
                           tr("Not connected.."));                                     // 提示未連線
            return ;            // 中止
        }
        if(autoP_->currentStatus == autoP_->STOPPED || autoP_->currentStatus == autoP_->ERRO) {
            showMessageBox(QMessageBox::Warning,
                           tr("Program Error"),
                           tr("Program Is Not Active"));
            return ;
        }
        if(ui->btnPStop->text() == tr("Stop")) {
            autoP_->pauseProcess();
            ui->lblStatusAuto->setText("狀態：已暫停");
            ui->btnPStop->setText(tr("Resume"));
        }else{
            autoP_->resumeProcess();
            ui->lblStatusAuto->setText("狀態：已恢復執行");
            ui->btnPStop->setText(tr("Stop"));
        }
    });

    connect(ui->btnPEStop, &QPushButton::clicked, this, [=](){
        if (ui->btnLConnect->text() == tr("Connect")) {                                 //如果未連線
            QMessageBox::warning(this, tr("Error Message"), tr("Not connected."));      // 提示未連線
            return;            // 中止
        }
        if(autoP_->currentStatus == autoP_->STOPPED || autoP_->currentStatus == autoP_->ERRO) {
            showMessageBox(QMessageBox::Warning,
                           tr("Program Error"),
                           tr("Program Is Not Active"));
            return ;
        }
        autoP_->stopProcess();
    });

    connect(ui->cb_model, &QComboBox::currentIndexChanged, this, [=]() {
        QSettings settings("config.ini", QSettings::IniFormat);
        QString selectedText = ui->cb_model->currentText();
        settings.beginGroup(selectedText+"/Fit");
        autoP_->dacAdd = settings.value("DAC_add", "").toInt();
        autoP_->dacRrange = settings.value("DAC_range", "").toInt();
        autoP_->Ld_fit.m = settings.value("LD_a", "").toDouble();
        autoP_->Ld_fit.l = settings.value("LD_b", "").toDouble();
        autoP_->Laser_fit.m = settings.value("Laser_a", "").toDouble();
        autoP_->Laser_fit.l = settings.value("Laser_b", "").toDouble();
        autoP_->tol_divide = settings.value("Fit_dvide", "").toDouble();
        autoP_->low_tol = settings.value("Low_tol", "").toDouble();
        autoP_->high_tol = settings.value("High_tol", "").toDouble();

    });
}

void MainWindow::loadSettings(QString model) {
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.beginGroup(model+"/Fit");
    ui->lineDAC_add->setText(settings.value("DAC_add", "").toString());
    ui->lineDAC_range->setText(settings.value("DAC_range", "").toString());
    ui->lineLDfit_a->setText(settings.value("LD_a", "").toString());
    ui->lineLDfit_b->setText(settings.value("LD_b", "").toString());
    ui->lineLaser_fit_a->setText(settings.value("Laser_a", "").toString());
    ui->lineLaser_fit_b->setText(settings.value("Laser_b", "").toString());
    ui->lineFit_dvide->setText(settings.value("Fit_dvide", "").toString());
    ui->lineLow_tol->setText(settings.value("Low_tol", "").toString());
    ui->lineHigh_tol->setText(settings.value("High_tol", "").toString());
}

void MainWindow::saveSettings(QString model) {
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.beginGroup(model+"/Fit");
    settings.setValue("DAC_add", ui->lineDAC_add->text());
    settings.setValue("DAC_range", ui->lineDAC_range->text());
    settings.setValue("LD_a", ui->lineLDfit_a->text());
    settings.setValue("LD_b", ui->lineLDfit_b->text());
    settings.setValue("Laser_a", ui->lineLaser_fit_a->text());
    settings.setValue("Laser_b", ui->lineLaser_fit_b->text());
    settings.setValue("Fit_dvide", ui->lineFit_dvide->text());
    settings.setValue("Low_tol", ui->lineLow_tol->text());
    settings.setValue("High_tol", ui->lineHigh_tol->text());
}

void MainWindow::closeEvent(QCloseEvent *event) {
    saveSettings();  // 關閉視窗前儲存設定
    QMainWindow::closeEvent(event);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    updateUiScale();
    applyAdaptiveSpacing();
}

void MainWindow::updateUiScale()
{
    if (baseSize_.width() <= 0 || baseSize_.height() <= 0)
        return;

    qreal sx = qreal(width())  / baseSize_.width();
    qreal sy = qreal(height()) / baseSize_.height();
    qreal scale = std::min(sx, sy);  // 取較小的比例，避免拉太扁

    QFont f = this->font();
    f.setPointSizeF(baseFontPointSize_ * scale);
    this->setFont(f); // 設到 MainWindow，會傳到子元件
}

void MainWindow::applyAdaptiveSpacing()
{
    // 取得主要螢幕比例
    QScreen* screen = QGuiApplication::primaryScreen();
    if (!screen)
        return;

    const QSize sz = screen->availableGeometry().size();
    if (sz.height() == 0)
        return;

    qreal ratio = qreal(sz.width()) / sz.height(); // >1.7 約 16:9，>2.0 約 21:9

    int margin = 8;
    int spacing = 8;

    if (ratio > 2.0) {
        // 超寬螢幕（21:9 等）：左右空間比較大，間距可以稍微放大
        margin = 12;
        spacing = 14;
    } else if (ratio > 1.7) {
        // 一般 16:9 螢幕
        margin = 10;
        spacing = 10;
    } else {
        // 比較偏正方或 4:3：間距略縮小一點
        margin = 6;
        spacing = 6;
    }

    // 根 layout 名稱請依你實際 .ui 為準：
    // - 如果你用的是我給的 MainWindow_scaled.ui，root 叫 horizontalLayout_root
    // - 如果你用的是原始專案，可能叫 horizontalLayout_11
    // 下面示範同時處理兩種情況（有誰就調誰）：
    if (auto root = findChild<QHBoxLayout*>("horizontalLayout_root")) {
        root->setSpacing(spacing);
        root->setContentsMargins(margin, margin, margin, margin);
    }
    if (auto root2 = findChild<QHBoxLayout*>("horizontalLayout_11")) {
        root2->setSpacing(spacing);
        root2->setContentsMargins(margin, margin, margin, margin);
    }
}

void MainWindow::lineValidator(QLineEdit* ui,double min, double max,int f) {
    QDoubleValidator *validator = new QDoubleValidator(min, max, f, this);
    //validator->setNotation(QDoubleValidator::StandardNotation);
    connect(ui, &QLineEdit::editingFinished, this, [=]() {
        QString text = ui->text();
        bool ok = false;
        double value = text.toDouble(&ok);
        int pos = 0;
        qDebug() << "Editing finished:" << ui->objectName() << " value=" << ui->text();
        qDebug() << "State=" << validator->validate(text, pos);
        if (!ok || value < validator->bottom() || value > validator->top()) {
            showMessageBox(QMessageBox::Warning, "Error",
                           "輸入範圍錯誤", QString("輸入值範圍 (%1 ~ %2)").arg(min).arg(max));
            QTimer::singleShot(0, this, [ui]() {
                ui->setFocus();
                ui->selectAll();
            });

            return;    // 關鍵：避免後面 event 連鎖觸發
        }
    });
}

void MainWindow::lineValidator(QLineEdit* ui,int min, int max) {
    QIntValidator *validator = new QIntValidator(min, max, this);
    connect(ui, &QLineEdit::editingFinished, this, [=]() {
        QString text = ui->text();
        bool ok = false;
        double value = text.toInt(&ok);
        int pos = 0;
        qDebug() << "Editing finished:" << ui->objectName() << " value=" << ui->text();
        qDebug() << "State=" << validator->validate(text, pos);
        if (!ok || value < validator->bottom() || value > validator->top()) {
            showMessageBox(QMessageBox::Warning, "Error",
                           "輸入範圍錯誤", QString("輸入值範圍 (%1 ~ %2)").arg(min).arg(max));
            QTimer::singleShot(0, this, [ui]() {
                ui->setFocus();
                ui->selectAll();
            });


            return;    // 關鍵：避免後面 event 連鎖觸發
        }
    });
}

void MainWindow::openSimulation() {

    if (!Simulation_) {
        Simulation_ = new Simulation(this);
        //Simulation_->setAttribute(Qt::WA_DeleteOnClose);  // 關閉時自動 delete

        // 關掉視窗時把指標設回 nullptr，之後可以再開
        /*
        connect(Simulation_, &QObject::destroyed, this, [this]() {
            Simulation_ = nullptr;
        });*/
    }

    Simulation_->resize(320, 480);                                             // 設定主視窗初始大小
    Simulation_->show();
    Simulation_->raise();
    Simulation_->activateWindow();
}

void MainWindow::openLogin() {

    if (!login_) {
        login_ = new Login(this);
        connect(login_, &Login::loginFinsh, this, [=](bool ok){
            qDebug() << QString("isEnginerring = %1").arg(ok);
            setEnginerring(ok);
        });
        //Simulation_->setAttribute(Qt::WA_DeleteOnClose);  // 關閉時自動 delete

        // 關掉視窗時把指標設回 nullptr，之後可以再開
        /*
        connect(Simulation_, &QObject::destroyed, this, [this]() {
            Simulation_ = nullptr;
        });*/
    }

    login_->resize(460, 320);                                             // 設定主視窗初始大小
    login_->show();
    login_->raise();
    login_->activateWindow();
}

void MainWindow::openStressTest() {

    if (!Stress_) {
        Stress_ = new StressTesting(this, autoP_, laser_);
        connect(Stress_, &StressTesting::abnormal_msg, this, [=](QString msg){
            qDebug() << QString("抓到異常-> %1").arg(msg);
            appendLog(msg, false);
        });
    }

    Stress_->resize(460, 320);                                             // 設定主視窗初始大小
    Stress_->show();
    Stress_->raise();
    Stress_->activateWindow();
}

void MainWindow::setEnginerring(bool ok) {
    isEnginerring = ok ? true:false;
    switchPage(currentPage);
}

void MainWindow::switchPage(int page) {
    if(isEnginerring == true) {
        currentPage = page;
        ui->stackedWidget->setCurrentIndex(currentPage);
    }else {currentPage = 0; ui->stackedWidget->setCurrentIndex(currentPage);}
}

MainWindow::Mode MainWindow::currentMode() const {                    // 取得目前模式（由 Tab 決定）
    return ui->tabConSwitch->currentIndex() == 0 ? Mode::TCP : Mode::Serial; // Tab 0=TCP, 1=Serial
}

void MainWindow::refreshSConnect() {                               // 重新列舉可用序列埠
    ui->cbPort->clear();                                              // 先清空清單
    const auto ports = QSerialPortInfo::availablePorts();             // 取得所有可用序列埠資訊
    for (const auto& p : ports) {                                     // 逐一加入下拉選單
        ui->cbPort->addItem(p.portName());                            // 使用純粹的埠名（例如 COM3、ttyUSB0）
    }
}

void MainWindow::onConnectClicked() {                                 // Connect/Disconnect 按鈕事件

    const bool wantConnect = (ui->btnLConnect->text() == tr("Connect")); // 依按鈕文字判斷使用者是要連線或斷線

    if (currentMode() == Mode::TCP) {                                 // 若為 TCP 模式
        if (wantConnect) {                                            // 使用者想連線
            sock_->abort();                                           // 先中止任何既有連線
            sock_->connectToHost(ui->leTcpHost->text(),               // 讀取 Host 輸入框
                                 static_cast<quint16>(ui->sbTcpPort->value())); // 讀取 Port 數值
            ui->statusbar->showMessage(tr("Connecting TCP..."));     // 顯示正在連線
        } else {                                                      // 使用者想斷線
            sock_->disconnectFromHost();                              // 斷開 TCP
        }
    } else {                                                          // Serial 模式
        if (wantConnect) {                                            // 使用者想開啟序列埠
            QString PortName = ui->cbPort->currentText();          // 設定埠名
            int BaudRate = ui->cbBaud->currentData().toInt();  // 設定鮑率（取 userData）
            int Parity = ui->cbParity->currentData().toInt(); // 同位元
            int DataBits= ui->cbDataBits->currentData().toInt(); // 資料位
            int StopBits = ui->cbStopBits->currentData().toInt(); // 停止位
            if (!laser_->onConnectserial(PortName, BaudRate, Parity, DataBits, StopBits)) {                   // 嘗試開啟讀寫
                QMessageBox::critical(this, tr("Serial Error"), serial_->errorString()); // 失敗則顯示錯誤
                setConnected(false);                                      // 更新 UI 為未連線
                ui->statusbar->showMessage(tr("Serial opened fail"));     // 狀態列提示
                if(laser_) delete laser_;
                return;                                                   // 中止函式
            }
            setConnected(true);
        } else {                                                      // 使用者想關閉序列埠
            setConnected(false);                                      // UI 改為未連線
        }
    }
}

void MainWindow::onSocketConnected() {                                // TCP 成功連線的回呼
    setConnected(true);                                               // 更新 UI 為已連線
    ui->statusbar->showMessage(tr("TCP connected"));                 // 狀態列提示
    ui->labConStatus->setText(tr("Connected : Host ") + sock_->peerName() + QString(" Port %1").arg(sock_->peerPort()));
}

void MainWindow::onSocketDisconnected() {                             // TCP 斷線的回呼
    setConnected(false);                                              // 更新 UI 為未連線
    ui->statusbar->showMessage(tr("TCP disconnected"));              // 狀態列提示
    ui->labConStatus->setText(tr("Not connect"));
}

void MainWindow::onErrorOccurred(QAbstractSocket::SocketError) {      // TCP 錯誤回呼
showMessageBox(QMessageBox::Critical, tr("Sock Error"), sock_->errorString());  // 顯示錯誤內容
    setConnected(false);                                              // 更新 UI 為未連線
}

void MainWindow::onSocketReadyRead() {                                // TCP 有資料可讀
    rxBuf_.append(sock_->readAll());                                  // 讀取所有可用位元資料累加到緩衝
    while (true) {                                                    // 以迴圈處理可能一次到多行
        int idx = rxBuf_.indexOf('\n');                              // 尋找換行符號位置
        if (idx < 0) break;                                           // 找不到換行則暫停解析，等待更多資料
        QByteArray line = rxBuf_.left(idx);                           // 取出一行（不含換行）
        rxBuf_.remove(0, idx + 1);                                    // 從緩衝移除已處理的部分
        appendLog(QString::fromUtf8(line), /*isTx=*/false);           // 以 RX 形式加入日誌
    }
}

void MainWindow::changSDCorSDAC(int index){
    if(index == 0) {

        auto setupPower = [this](QSlider* s, QSpinBox* sp, QComboBox* cb) {                 // Lambda：同時設定 Slider 與 SpinBox
            s->setRange(dacinit, dacRang);                                      // 滑桿範圍
            s->setSingleStep(10);                                        // 單步進
            s->setPageStep(50);                                          // Page 步進
            sp->setRange(dacinit, dacRang);                                     // 數值框範圍
            sp->setSingleStep(10);                                       // 單步進
            s->setValue(dacinit);                                        // 預設值 0
            cb->clear();
            cb->addItem(QString("SDAC1"));
            cb->addItem(QString("SDAC2"));
            cb->addItem(QString("SDAC3"));
        };
        setupPower(ui->sL1, ui->spL1, ui->cb_selectSDAC);                  // 設定 L1 控制

    }else {
        auto setupPower = [this](QSlider* s, QSpinBox* sp, QComboBox* cb) {                 // Lambda：同時設定 Slider 與 SpinBox
            s->setRange(0, 100);                                      // 滑桿範圍
            s->setSingleStep(5);                                        // 單步進
            s->setPageStep(10);                                          // Page 步進
            sp->setRange(0, 100);                                     // 數值框範圍
            sp->setSingleStep(5);                                       // 單步進
            s->setValue(0);                                            // 預設值 0
            cb->clear();
            cb->addItem(QString("SDC"));
        };
        setupPower(ui->sL1, ui->spL1, ui->cb_selectSDAC);                  // 設定 L1 控制
    }
}

void MainWindow::showMessageBox(QMessageBox::Icon icon,
                                       const QString &title,
                                       const QString &text,
                                       const QString &infoText)
{
    QMessageBox msg(this);
    msg.setIcon(icon);
    msg.setWindowTitle(title);
    msg.setText(text);
    if (!infoText.isEmpty())
        msg.setInformativeText(infoText);

    // 統一在這裡調整所有 QLabel 的對齊
    const auto labels = msg.findChildren<QLabel*>();
    for (QLabel *lab : labels) {
        lab->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    msg.exec();
}

bool MainWindow::sendCommand(const QString& command) {
    if (!laser_) {                                  //如果未連線
        QMessageBox::warning(this, tr("Error Message"), tr("Not connected.")); // 提示未連線
        return false;            // 中止
    }
    appendLog(command, /*isTx=*/true);
    if(command == "powerOff") autoP_->powerOff();
    else laser_->sendAndWait(command);
    qDebug() << QString("ui 處理command: %1").arg(command);
    return true;
}

void MainWindow::sendArbitrary() {                                   // 傳送命令輸入框內的字串
    const QString cmd = ui->leCmd->text().trimmed();                  // 取出輸入並去除前後空白
    if (cmd.isEmpty()) return;                                        // 空字串則不動作
    ui->leCmd->clear();                                               // 清空輸入框
    if (cmd=="help"){
        ui->teLog->append(
            "EABx:      Enable Channel x \r\n"
            "ALLEAB:    Enable All Channels \r\n"
            "DABx:      Disable Channel x \r\n"
            "ALLDAB:    Disable All Channels\r\n"
            "LIMITx:    Set DAC Limit of Channel x\r\n"
            "ALLLIMIT:  Set DAC Limit of ALL Channel \r\n"
            "SDACx:     Set DAC Value of Channel x \r\n"
            "ALLSDAC:   Set DAC Value of All Channel \r\n"
            "RDACx:     Read DAC Value of Channel x \r\n"
            "ALLRDAC:   Read DAC Value of All Channel \r\n"
            "RPD:       Read PD value\r\n"
            "SPD:       Set Current PD Value as PD protection value\r\n"
            "RSTPD:     Reset PD protection value to zero\r\n"
            "ETP:       Enable Temperature Protection \r\n"
            "DTP:       Disable Temperature Protection\r\n"
            "RCT:       Read Current Thermistor value\r\n"
            "AutoRCTON: Enable RCT Auto mode\r\n"
            "AutoRCTOFF:Disable RCT Auto mode\r\n"
            "RERR:      Reset Errors -> Resets any resettable errors\r\n"
            );
        return;
    }
    sendCommand(cmd);                                     // 加上協定結尾後傳送
    //ui->leCmd->clear();                                               // 清空輸入框
}


void MainWindow::appendLog(const QString& line, bool isTx) {          // 新增一行到日誌視窗
    const QString ts = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz"); // 製作時間戳
    if (ui->cbHexView->isChecked() && !isTx) {                        // 若勾選十六進位顯示且為 RX
        QByteArray raw = line.toUtf8();                                // 取得原始位元資料（UTF-8 轉換）
        QString hex;                                                   // 準備十六進位字串
        hex.reserve(raw.size()*3);                                     // 預留容量加速

        for (unsigned char c : raw) hex += QString::asprintf("%02X ", c); // 逐位元轉為 2 位十六進位
        ui->teLog->append(QString("[%1] %2: %3").arg(ts, isTx?"TX":"RX", hex.trimmed())); // 顯示 RX: HEX
    } else {                                                           // 否則一般文字顯示
        ui->teLog->append(QString("[%1] %2: %3").arg(ts, isTx?"TX":"RX", line));         // 顯示 TX/RX: 內容
    }
}

void MainWindow::setConnected(bool ok) {                               // 更新連線狀態到 UI
    ui->btnLConnect->setText(ok ? tr("Disconnect") : tr("Connect")); // 切換按鈕文字
    ui->lbStatus->setText(ok ? tr("Connected") : tr("Disconnected")); // 切換狀態標示
    ui->labConStatus->setText(QString("連線狀態: %1").arg(ok == true ? "connect" : "disconnect"));
}

void MainWindow::saveLogToFile() {                                     // 將日誌內容存成文字檔
    const QString fn = QFileDialog::getSaveFileName(this, tr("Save Log"), "LaserGUI_log.txt", tr("Text Files (*.txt)")); // 儲存檔案對話框
    if (fn.isEmpty()) return;                                          // 使用者取消則返回
    QFile f(fn);                                                       // 建立檔案物件
    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) { // 以純文字覆寫模式開啟
        QMessageBox::warning(this, tr("Save failed"), f.errorString()); // 開啟失敗提示
        return;                                                        // 中止
    }
    f.write(ui->teLog->toPlainText().toUtf8());                        // 寫入目前日誌的純文字內容
    f.close();                                                         // 關閉檔案
}

void MainWindow::clearLog() {                                          // 清除日誌視窗
    ui->teLog->clear();                                                // 清空 QTextEdit
}

void MainWindow::initLaser() {
    connect(laser_, &LaserDriver::serialRead, this, [=](QString line) {          // Serial 可讀
        appendLog(line, /*isTx=*/false);           // 以 RX 形式加入日誌
    });

    connect(laser_, &LaserDriver::SerialError, this, [=](QString msg) {                   // Serial 錯誤
        showMessageBox(QMessageBox::Critical, tr("Serial Error"), msg);            // 顯示錯誤
        setConnected(false);                                                              // 更新 UI 為未連線
        ui->labConStatus->setText(tr("Not connect"));
    });
}

void MainWindow::initLaserMDevice() {

    // 連接 Laser_Meter 的事件到 UI 更新槽
    connect(Laser_meter_, &MeterDevice::powerUpdated, this, &MainWindow::onMPowerUpdated);
    connect(Laser_meter_, &MeterDevice::statusText, this, &MainWindow::onMStatusText);
    connect(Laser_meter_, &MeterDevice::errorText, this, &MainWindow::onMErrorText);
    connect(Laser_meter_, &MeterDevice::stringReceived, this, [this](QString text){
        ui->teLog->append("回覆(文字): " + text);
    });

    connect(Laser_meter_, &MeterDevice::intReceived, this, [this](int val){
        ui->teLog->append("回覆(整數): " + QString::number(val));
    });

    connect(Laser_meter_, &MeterDevice::floatReceived, this, [this](float val){
        ui->teLog->append("回覆(浮點): " + QString::number(val));
    });
}

void MainWindow::onMConnectClicked() {
    if (ui->btn_LASERPOINT->text() != "Connect") {
        setMConnected(false);
        return ;
    }
    const int index = ui->spn_LASERPOINT->value(); // 讀取 SpinBox 的裝置索引
    if (Laser_meter_->isOpen()) {                         // 若已開啟
        ui->lblStatusMeter_1->setText("狀態：已連線");      // 更新狀態
        ui->lblStatusMeter_2->setText("狀態：已連線");
        ui->lblStatusMeter_3->setText("狀態：已連線");
        return;                                    // 不重複開啟
    }
    if (!Laser_meter_->open(index)) {                     // 嘗試開啟第 index 台
        ui->lblStatusMeter_1->setText("狀態：連線失敗");    // 顯示失敗
        ui->lblStatusMeter_2->setText("狀態：連線失敗");
        ui->lblStatusMeter_3->setText("狀態：連線失敗");
        return;                                    // 中止
    }
    if (!Laser_meter_->initializeDConnect()) {            // 初始化連線，設定baud rate、data bits、stop bits、flow control等
        ui->lblStatusMeter_1->setText("狀態：初始化失敗");  // 顯示失敗
        ui->lblStatusMeter_2->setText("狀態：初始化失敗");  // 顯示失敗
        ui->lblStatusMeter_3->setText("狀態：初始化失敗");  // 顯示失敗
        return;                                    // 中止
    }
    if (!Laser_meter_->initializeForPower()) {            // 初始化為功率模式
        ui->lblStatusMeter_1->setText("狀態：初始化功率模式失敗");  // 顯示失敗
        ui->lblStatusMeter_2->setText("狀態：初始化功率模式失敗");
        ui->lblStatusMeter_3->setText("狀態：初始化功率模式失敗");
        return;                                    // 中止
    }
    setMConnected(true);
    delay(30);
    Laser_meter_->sendCommand("HEADN");
    delay(30);
    Laser_meter_->sendCommand("SERNU");
}

void MainWindow::setMConnected(bool ok){
    ui->btn_LASERPOINT->setText(ok ? tr("Disconnect") : tr("Connect"));
    if(ok) {
        setMStarted(true);
        ui->lblStatusMeter_1->setText("狀態：已連線，待開始量測"); // 更新狀態
        ui->lblStatusMeter_2->setText("狀態：已連線，待開始量測");
        ui->lblStatusMeter_3->setText("狀態：已連線，待開始量測");

    }
    else{
        setMStarted(false);
        Laser_meter_->stopPolling();
        Laser_meter_->close();
        ui->lblStatusMeter_1->setText("狀態：已關閉連線");      // 更新狀態
        ui->lblStatusMeter_2->setText("狀態：已關閉連線");
        ui->lblStatusMeter_3->setText("狀態：已關閉連線");
    }
}

void MainWindow::onMSWaveSelect(const QString s) {         // 處理Wave設定
    if (s == "CO2") {Laser_meter_->sendCommand("SETLAM 1"); return ;}
    if (s == "Erb") {Laser_meter_->sendCommand("SETLAM 2"); return ;}
    if (s == "YAG") {Laser_meter_->sendCommand("SETLAM 3"); return ;}
    if (s == "LD")  {Laser_meter_->sendCommand("SETLAM 4"); return ;}
    if (s == "VIS") {Laser_meter_->sendCommand("SETLAM 5"); return ;}
    if (s == "EXC") {Laser_meter_->sendCommand("SETLAM 6"); return ;}
    if (s == "UCF") {Laser_meter_->sendCommand("SETLAM 7"); return ;}
    Laser_meter_->sendCommand("SETLAM 3");
    return ;
}

void MainWindow::setMStarted(bool ok) {                               // 更新開始狀態到 UI
    int interval = ui->spn_LaserMInterval->value();
    if(ok) Laser_meter_->startPolling(interval);                 // 開始輪詢
    else {
        Laser_meter_->stopPolling();                           // 停止輪詢
        ui->lblPower->setText("--.-");
        ui->lblPower_2->setText("--.-");
    }
}

void MainWindow::onMPowerUpdated(double w) {         // 收到功率更新
    // 如需換單位（例如 mW）可在此乘 1000 並改變 lblUnit
    ui->lblPower->setText(QString::number(w, 'f', 2)); // 顯示到小數第 3 位
    ui->lblPower_2->setText(QString::number(w, 'f', 2));
    ui->lblPower_3->setText(QString::number(w, 'f', 2));
}

void MainWindow::onMStatusText(const QString& s) {   // 一般狀態
    ui->lblStatusMeter_1->setText("狀態：" + s);           // 顯示於狀態標籤
    ui->lblStatusMeter_2->setText("狀態：" + s);
    ui->lblStatusMeter_3->setText("狀態：" + s);
}

void MainWindow::onMErrorText(const QString& s) {    // 錯誤狀態
    ui->lblStatusMeter_1->setText("錯誤：" + s);           // 顯示於狀態標籤
    ui->lblStatusMeter_2->setText("錯誤：" + s);
    ui->lblStatusMeter_3->setText("錯誤：" + s);
}

// 按鈕: 傳送指令
void MainWindow::onbtnMSendClicked() {
    QString cmd = ui->lineEdit_command->text();
    QMetaObject::invokeMethod(Laser_meter_, "sendCommand", Qt::QueuedConnection,
                              Q_ARG(QString, cmd));
}

void MainWindow::initThorMDevice() {

    connect(Thor_meter_,&ThorLABS_MeterDevice::update_measPower, this, [=](double pw){
        ui->lbl_measPower->setText(QString::number(pw, 'f', 2));
        ui->lbl_measPower_2->setText(QString::number(pw, 'f', 2));
    });
}

void MainWindow::onbtnScanClicked()     // 掃描按鈕按下
{
    // 鎖定 UI 防止重複點擊
    ui->btn_ThorLabsMeterScan->setEnabled(false);
    ui->cbB_ThorlabMeter->clear();
    ui->cbB_ThorlabMeter->addItem("Scanning...");
    ui->btn_ThorlabMeter->setEnabled(false);

    // 啟動非同步掃描
    // 注意：這裡不傳 this 進去 lambda，只呼叫 Thor_meter_ 的函式
    // 如果 Thor_meter_ 是 thread-safe 的話
    QFuture<QList<ThorLABS_MeterDevice::DeviceInfo>> future = QtConcurrent::run([this](){
        return Thor_meter_->scan_instruments();
    });

    scanWatcher->setFuture(future);
}

void MainWindow::onScanFinished()
{
    ui->cbB_ThorlabMeter->clear();
    ui->btn_ThorLabsMeterScan->setEnabled(true); // 解鎖掃描按鈕

    // 取得結果
    QList<ThorLABS_MeterDevice::DeviceInfo> devices = scanWatcher->result();

    // --- 優化點 1: 如果沒裝置，鎖死連線按鈕並離開 ---
    if (devices.isEmpty()) {
        ui->cbB_ThorlabMeter->addItem("No devices found");
        ui->btn_ThorlabMeter->setEnabled(false); // 確保連線按鈕無法按下
        return;
    }

    for (const auto &dev : devices) {
        // --- 優化點 2: 顯示文字微調 ---
        // 如果是 Available 顯示 "Free"，否則顯示 "Busy/Lock" 比較中性
        QString statusStr = dev.isAvailable ? "Free" : "Busy/Lock";

        QString displayText = QString("%1 (S/N:%2) [%3]")
                                  .arg(dev.model)
                                  .arg(dev.serialNumber)
                                  .arg(statusStr);

        // 將 resourceString 藏在 UserRole 中 (這步你寫得很對)
        ui->cbB_ThorlabMeter->addItem(displayText, QVariant(dev.resourceString));
    }

    // 有裝置就開啟連線按鈕，讓使用者嘗試連線
    ui->btn_ThorlabMeter->setEnabled(true);

    // 自動選取第一個項目 (預設行為，但寫出來比較安心)
    if(ui->cbB_ThorlabMeter->count() > 0) {
        ui->cbB_ThorlabMeter->setCurrentIndex(0);
    }
}

void MainWindow::onbtnThorMConnectCclicked()
{
    // 如果已經連線 -> 執行斷線
    if (Thor_meter_) {

        // 停止定時器 (必須先做)
        MmeasureTimer.stop();

        // 斷線
        Thor_meter_->disconnectThorLabsMeter();

        // 更新 UI
        ui->btn_ThorlabMeter->setText("Connect");
        ui->lb_ThorlabMeter->setText("Disconnected");
        ui->cbB_ThorlabMeter->setEnabled(true);
    }
    // 如果沒連線 -> 執行連線
    else {
        QString rsrcString = ui->cbB_ThorlabMeter->currentData().toString();
        if (rsrcString.isEmpty()) return;

        // 連線 (不用傳 handle 了，類別自己會存)
        ViStatus err = Thor_meter_->connectThorLabsMeter(rsrcString);

        if (err == VI_SUCCESS) {
            // 更新 UI
            ui->btn_ThorlabMeter->setText("Disconnect");
            ui->lb_ThorlabMeter->setText("Connected");
            ui->cbB_ThorlabMeter->setEnabled(false);

            initThorMDevice();
            // 啟動定時器 (現在不用擔心指標錯誤了)
            MmeasureTimer.start(500);
        } else {
            // 顯示錯誤...
        }
    }
}

void MainWindow::onTimerTimeout()   // Timer 的 Slot
{
    // 這裡只需要呼叫 update，不用傳參數
    Thor_meter_->updatePowerReading();
}

void MainWindow::initAutoP() {

    autoP_->AutoPinit();
    autoP_->dacAdd = ui->lineDAC_add->text().toInt();
    autoP_->dacRrange = ui->lineDAC_range->text().toInt();
    autoP_->Ld_fit.m = ui->lineLDfit_a->text().toDouble();
    autoP_->Ld_fit.l = ui->lineLDfit_b->text().toDouble();
    autoP_->Laser_fit.m = ui->lineLaser_fit_a->text().toDouble();
    autoP_->Laser_fit.l = ui->lineLaser_fit_b->text().toDouble();
    autoP_->tol_divide = ui->lineFit_dvide->text().toDouble();
    autoP_->low_tol = ui->lineLow_tol->text().toDouble();
    autoP_->high_tol = ui->lineHigh_tol->text().toDouble();
    autoP_->measureCheckOpen = (ui->ckb_Fitting->checkState() == Qt::Checked ? true : false);
    autoP_->PDvalueCheckOpen = (ui->ckb_PD_value->checkState() == Qt::Checked ? true : false);

    connect(autoP_, &AutoP::processFinished, this, [this]() {
        // 狀態改變後表示程序結束
        LoggerObject* logObject = new LoggerObject(this);
        QTimer::singleShot(1000, this, [=]() {
            logObject->writeLog(ui->teLog->toPlainText());
            logObject->writeLog("量測數據:dac | power(W)\n" + autoP_->vecToQString(autoP_->setValue,autoP_->measured));
            logObject->writeLog("檢測用擬和結果:" + QString("y = %1x + %2")
                                                        .arg(autoP_->testFit.m, 0, 'f', 4)
                                                        .arg(autoP_->testFit.l, 0, 'f', 4));
            logObject->writeLog("PD1校正結果:\n" + autoP_->PDvecToQString(autoP_->PD1));
            logObject->writeLog("PD2校正結果:\n" + autoP_->PDvecToQString(autoP_->PD2));
            logObject->writeLog("韌體用擬和結果1:" + QString("y = %1x + %2")
                                                         .arg(autoP_->resultFit1.m, 0, 'f', 4)
                                                         .arg(autoP_->resultFit1.l, 0, 'f', 4));
            logObject->writeLog("韌體用擬和結果2:" + QString("y = %1x + %2")
                                                         .arg(autoP_->resultFit2.m, 0, 'f', 4)
                                                         .arg(autoP_->resultFit2.l, 0, 'f', 4));
            logObject->deleteLater();

        });

        ui->lblStatusAuto->setText("狀態：程序已完成");
    });
    connect(autoP_, &AutoP::statusText, this, &MainWindow::onAutoPStatusText);
    connect(autoP_, &AutoP::errorSignal, this, [this](QString i, QString m) {
        onAutoLogText(i, m);
        // 狀態改變後表示程序結束
        LoggerObject* logObject = new LoggerObject(this);
        QTimer::singleShot(1000, this, [=]() {
            logObject->writeLog(ui->teLog->toPlainText());
            logObject->deleteLater();
        });

        ui->lblStatusAuto->setText("狀態：程序發生錯誤");
    });
    connect(autoP_, &AutoP::addCommandtoLog, this, [this](QString c) {
        appendLog(c, true);
    });

    connect(autoP_, &AutoP::powerDoub, this, [this](QString i, QString m) {
        onAutoLogText(i, m);});

    // 當autoPThread結束時，自動安全地刪除 autoP_，避免記憶體洩漏與跨執行緒錯誤
    //connect(autoPThread, &QThread::finished, autoP_, &QObject::deleteLater);
    //autoPThread->start();
}

void MainWindow::onAutoPStatusText(const QString& s) {   // 一般狀態
    ui->lblStatusAuto->setText("狀態：" + s);           // 顯示於狀態標籤
}


void MainWindow::onAutoLogText(const QString& info, const QString& massage) {

    const QString ts = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz"); // 製作時間戳
    ui->teLog->append(QString("[%1] %2: %3").arg(ts, info, massage));
}

void MainWindow::delay(int ms){
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<ms);
}
