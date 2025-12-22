#include "ConnectDevice.h"         // 對應標頭
#include <QElapsedTimer>         // 用於簡單逾時計時
#include <QThread>               // 用於 msleep（讓輪詢不會佔滿 CPU）
#include <cstring>
#include <QMessageBox>          // 顯示錯誤訊息對話框
#include <QTimer>

void Delay(int ms);

LaserDriver::LaserDriver(QObject* parent)
    :QObject(parent)
    , serial_(new QSerialPort(this))                                // 建立 Serial Port，設置父物件便於自動釋放
    , sock_(new QTcpSocket(this))
{
    currentMode = -1;
    connect(serial_, &QSerialPort::readyRead,   this, &LaserDriver::onSerialReadyRead);    // Serial 可讀
    connect(serial_, &QSerialPort::errorOccurred,
            this, [this](QSerialPort::SerialPortError error) {
                if (error == QSerialPort::ResourceError) {
                    emit SerialError("連線中斷");  // 自訂的 signal
                    serial_->close();
                }
            });

}
LaserDriver::~LaserDriver() {
    if (sock_->isOpen()) sock_->close();                              // 若 TCP 還開著則關閉
    if (serial_->isOpen()) serial_->close();                          // 若 Serial 還開著則關閉
}

bool LaserDriver::onConnectserial(QString port, int Baud, int Parity, int DataBits, int StopBits){
    qDebug() << "[Serial] 開始 connect clicked, port =" << port;  //開啟前後加入 debug
    serial_->close();                                         // 先確保關閉
    serial_->setPortName(port);          // 設定埠名
    serial_->setBaudRate(Baud);  // 設定鮑率（取 userData）
    serial_->setParity(static_cast<QSerialPort::Parity>(Parity)); // 同位元
    serial_->setDataBits(static_cast<QSerialPort::DataBits>(DataBits)); // 資料位
    serial_->setStopBits(static_cast<QSerialPort::StopBits>(StopBits)); // 停止位
    qDebug() << "[Serial] setPortName/baud done, about to open()";  //開啟前後加入 debug

    if (!serial_->open(QIODevice::ReadWrite)) return false;
    currentMode = 1;
    return true;
}

void LaserDriver::onSerialErrorOccurred(QSerialPort::SerialPortError e) { // Serial 錯誤回呼
    if (e == QSerialPort::NoError) return;                            // 若無錯誤則略過
    if (e == QSerialPort::NotOpenError) return;                       // 忽略開啟前的錯誤
    qDebug() << "[Serial] errorOccurred() called. enum=" << e
             << " isOpen=" << serial_->isOpen()
             << " errStr=" << serial_->errorString()
             << " port=" << serial_->portName();
    emit SerialError(QString("Error %1: %2")
                         .arg(e)
                         .arg(serial_->errorString()));
}

void LaserDriver::onSerialReadyRead() {                               // Serial 有資料可讀
    rxBuf_.append(serial_->readAll());                                // 讀取所有可用位元資料累加到緩衝
    QByteArray line;
    while (true) {                                                    // 以迴圈處理可能一次到多行
        int idx = rxBuf_.indexOf('\n');                               // 尋找換行符號位置
        if (idx < 0) {
            //serial_->clear(QSerialPort::Output);                    // 清除緩存
            break;                                                    // 找不到換行則暫停解析
        }
        line = rxBuf_.left(idx);                                      // 取出一行（不含換行）
        rxBuf_.remove(0, idx + 1);
        QString text = QString::fromUtf8(line).trimmed();
        if (text.isEmpty()) continue;                                 // 從緩衝移除已處理的部分
        //qDebug() << "Emit line (hex):" << text.toUtf8().toHex();    // 檢查是否還有奇怪字元
        emit serialRead(text);                                        // 回傳已 trimmed 過的字串數據
    }
}

void LaserDriver::sendAndWait(const QString& cmd) {

    // 這裡不再 Wait，而是直接「掛號」放入佇列
    commandQueue.enqueue(cmd);
    // 如果現在沒人在送，就開始送 (如果有在送，加入 Queue 後就沒事了，等上一筆送完會自動抓下一筆)
    if (!isSending) {
        isSending = true;
        sendCommandSlowly(nullptr);
    }
}

void LaserDriver::sendCommandSlowly(QByteArray command) {
    if(command.isEmpty()) {

        if(!commandQueue.isEmpty()) {
            QString cmd = commandQueue.dequeue();
            QByteArray fullCommand = cmd.toUtf8() + '\r';
            QTimer::singleShot(100, this, nullptr);
            sendCommandSlowly(fullCommand);
            qDebug() << "開始送出" << cmd;
            return;
        }

        isSending = false;
        return;
    }
    // 取出第一個 byte，包成長度為 1 的 QByteArray
    QByteArray one(1, command.front());
    transmit(one);
    // 移除已經送出的第一個 byte
    command.remove(0, 1);
    // 對剩下的資料做遞迴處理
    QTimer::singleShot(intervalMs, this,[this, command]() {sendCommandSlowly(command);});
}

void LaserDriver::transmit(const QByteArray& bytes) {                   // 依模式傳送資料
    if (currentMode == 0) {                                  // TCP 模式
        /*if (sock_->state() != QAbstractSocket::ConnectedState) {       // 若未連線
            QMessageBox::warning(this, tr("Not connected"), tr("TCP socket not connected.")); // 提示未連線
            return;                                                    // 中止
        }*/
        sock_->write(bytes);                                           // 寫入 TCP socket
        sock_->flush();                                                // 立刻嘗試送出緩衝
    } else if(currentMode == 1)  serial_->write(bytes);                // Serial 模式 寫入序列埠

}

MeterDevice::MeterDevice(QObject* parent)
    : QObject(parent)
    //, thermometer(new ThermometerWidget(this))


{ // 建構子初始化列表
    // 當定時器時間到時要做的事情（lambda 直接綁定 this）
    connect(&poller_, &QTimer::timeout, [this]() {
        if (!opened_) return; // 若尚未開啟裝置，直接略過

        QByteArray ans; // 用於儲存回覆
        if (!sendAndRead("*OUTPM:", ans)) { // 送出讀功率指令，並讀回覆
            emit errorText("讀取功率失敗"); // 發出錯誤訊號給 UI
            return;                         // 結束這次輪詢
        }

        // 處理協定上可能的特殊字串（no head / ??）
        if (ans.startsWith("no head")) {           // 若回覆提示沒有測頭
            emit statusText("未偵測到測頭（no head）"); // 提示 UI 狀態
            return;                                // 不更新功率數值
        }
        if (ans.startsWith("??")) {                // 若指令格式錯誤或裝置無法理解
            emit errorText("通訊錯誤（??;）");      // 提示錯誤
            return;                                // 不更新功率數值
        }

        // 嘗試將 ASCII 浮點數轉為 double
        double w=0.0;                              // 用於接收轉換後的瓦特值
        if (parseFloatAnswer(ans, w)) {            // 解析成功
            emit powerUpdated(w);                  // 對外通報新的功率數值
        } else {                                   // 解析失敗（字串不是浮點數）
            emit errorText(QString("無法解析功率回覆：%1").arg(QString::fromLatin1(ans))); // 提示失敗內容
        }
    });
}

MeterDevice::~MeterDevice() { // 解構子
    close(); // 確保離開時關閉裝置
}

bool MeterDevice::open(int index) { // 嘗試開啟指定 index 的 FTDI 裝置
    if (opened_) return true; // 若已開啟則直接回 true

    FT_STATUS st = FT_Open(index, &handle_); // 呼叫 D2XX 開啟
    if (st != FT_OK) {                       // 若狀態非 OK
        emit errorText("FT_Open 失敗");      // 告知 UI 開啟失敗
        handle_ = nullptr;                   // 保險起見設為空
        return false;                        // 回傳失敗
    }

    FT_SetTimeouts(handle_, 250, 250); // 設定讀寫逾時（毫秒）
    opened_ = true;                    // 標記為已開啟
    emit statusText("FTDI 已開啟");    // 提示 UI
    return true;                       // 回傳成功
}

void MeterDevice::close() {                // 關閉裝置
    if (opened_ && handle_) {             // 只有在已開啟且 handle_ 有效時
        FT_Close(handle_);                // 呼叫 D2XX 關閉
        handle_ = nullptr;                // 清空控制代碼
        opened_ = false;                  // 標記為未開啟
        emit statusText("FTDI 已關閉");  // 提示 UI
    }
}

bool MeterDevice::initializeDConnect() {
    if (!opened_) return false;          // 未開啟則失敗
    FT_SetBaudRate(handle_, FT_BAUD_9600);            // 设置波特率（必须的）
    FT_SetDataCharacteristics(handle_, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_NONE);          // 设置字符格式（必须的）
    FT_SetUSBParameters(handle_, 512, 512);        // 设置输入输出缓存（必须的）
    FT_Purge(handle_, FT_PURGE_RX);                 // 清除输入缓存
    FT_Purge(handle_, FT_PURGE_RX);                 // 清除输出缓存
    return true;
}

bool MeterDevice::initializeForPower() { // 初始化功率模式
    if (!opened_) return false;          // 未開啟則失敗
    if (!setPowerMode()) return false;   // 發 *POWER: 並確認 ok
    if (!headPresent()) {                // 檢查 *STATUS: bit2（測頭是否在位）
        emit statusText("未偵測到測頭（no head）"); // 只是提示，不強制失敗
        // 不 return false，讓後續輪詢持續偵測（熱插拔時會恢復）
    }
    sendCommand("ZERO");
    return true;                         // 完成初始化
}

bool MeterDevice::setPowerMode() {       // 發送 *POWER: 切到功率模式
    QByteArray ans;                      // 用於接收回覆
    if (!sendAndRead("*POWER:", ans))    // 送出並讀回
        return false;                    // 逾時或通訊失敗
    if (!ans.startsWith("ok")) {         // 規格成功會回 "ok;"
        emit errorText("POWER 模式設定失敗"); // 告知 UI
        return false;                    // 回傳失敗
    }
    emit statusText("已切換 Power Meter 模式"); // 提示成功
    return true;                         // 回傳成功
}

bool MeterDevice::headPresent() {        // 檢測測頭連接狀態
    QByteArray ans;                      // 用於接收回覆
    if (!sendAndRead("*STATUS:", ans))   // 送出並讀回
        return false;                    // 逾時或通訊失敗
    if (ans.startsWith("no head"))       // 若裝置直接說沒有測頭
        return false;                    // 回傳未偵測

    bool ok=false;                       // 轉整數時的成功旗標
    int v = QString::fromLatin1(ans).toInt(&ok); // 字串轉 int
    if (!ok) return false;               // 轉換失敗則回 false
    bool connected = (v & (1<<2)) != 0;  // 第 2 位是否為 1（有測頭）
    return connected;                    // 回傳布林結果
}

void MeterDevice::startPolling(int intervalMs) { // 開始量測
    poller_.start(intervalMs);                   // 啟動定時器
    emit statusText(QString("開始量測功率， 每 %1 ms/次").arg(intervalMs)); // 提示 UI
}

void MeterDevice::stopPolling() { // 停止量測
    poller_.stop();               // 停止定時器
    emit statusText("已停止量測"); // 提示 UI
}

bool MeterDevice::writeCommand(const QByteArray& cmd) { // 寫入一條指令
    DWORD written = 0;                                  // 實際寫入的位元組數
    FT_STATUS st = FT_Write(handle_,                   // D2XX 寫入
                            (LPVOID)cmd.data(),        // 指向資料的指標
                            (DWORD)cmd.size(),         // 要寫入的長度
                            &written);                 // 寫入結果
    /*for Debug
    if(st == FT_INVALID_HANDLE) {emit errorText("FT_INVALID_HANDLE"); return false;}
    if(st == FT_DEVICE_NOT_FOUND) {emit errorText("FT_DEVICE_NOT_FOUND"); return false;}
    if(st == FT_IO_ERROR) {emit errorText("FT_IO_ERROR"); return false;}
    if(st == FT_INSUFFICIENT_RESOURCES) {emit errorText("FT_INSUFFICIENT_RESOURCES"); return false;}
    if(st == FT_INVALID_PARAMETER) {emit errorText("FT_INVALID_PARAMETER"); return false;}
    if(st == FT_INVALID_BAUD_RATE) {emit errorText("FT_INVALID_BAUD_RATE"); return false;}
    if(st == FT_FAILED_TO_WRITE_DEVICE) {emit errorText("FT_FAILED_TO_WRITE_DEVICE"); return false;}
    if(st == FT_NOT_SUPPORTED) {emit errorText("FT_NOT_SUPPORTED"); return false;}
    if(st == FT_EEPROM_WRITE_FAILED) {emit errorText("FT_EEPROM_WRITE_FAILEDR"); return false;}
    if(st == FT_DEVICE_NOT_OPENED) {emit errorText("FT_DEVICE_NOT_OPENED"); return false;}
    if(st == FT_DEVICE_NOT_OPENED_FOR_ERASE) {emit errorText("FT_DEVICE_NOT_OPENED_FOR_ERASE"); return false;}
    if(st == FT_DEVICE_NOT_OPENED_FOR_WRITE) {emit errorText("FT_DEVICE_NOT_OPENED_FOR_WRITE"); return false;}
    if(st == FT_OK) {emit errorText("FT_OK"); return false;}*/
    //if(written == (DWORD)cmd.size()) {emit errorText("written error"); return false;}
    return (st == FT_OK) && (written == (DWORD)cmd.size());    //確認成功且長度一致
}

bool MeterDevice::readAnswer(QByteArray& out, int maxWaitMs) { // 讀到 ';' 為止
    out.clear();                         // 先清空輸出緩衝
    QElapsedTimer t; t.start();          // 啟動逾時計時器
    for (;;) {                           // 迴圈嘗試讀取直到逾時
        DWORD rx = 0;                    // 目前接收佇列長度
        FT_GetQueueStatus(handle_, &rx); // 查詢接收佇列中有多少位元組
        if (rx > 0) {                    // 若有可讀資料
            QByteArray buf; buf.resize((int)rx); // 準備暫存緩衝
            DWORD got = 0;                        // 實際讀到的位元組數
            FT_STATUS st = FT_Read(handle_,       // 呼叫 D2XX 讀取
                                   buf.data(),    // 放資料的位址
                                   rx,            // 讀取長度（嘗試讀完）
                                   &got);         // 回傳讀到長度
            if (st != FT_OK) return false;        // 若讀取錯誤，回 false
            out.append(buf.constData(), (int)got); // 追加到輸出緩衝
            if (out.contains(';')) {              // 若已讀到結尾分號
                int semi = out.indexOf(';');      // 找到 ';' 位置
                out = out.left(semi);             // 只保留 ';' 之前的內容
                out = out.trimmed();              // 去掉前後空白與換行
                return true;                      // 回傳成功
            }
        }
        if (t.elapsed() > maxWaitMs) {            // 若超過最大等待時間
            return !out.isEmpty();                // 若有部分內容就回 true 交由上層判斷
        }
        QThread::msleep(5);                       // 小睡 5ms，避免忙等
    }
}

bool MeterDevice::sendAndRead(const QByteArray& cmd, QByteArray& answer) { // 合併送/收
    if (!opened_) return false;                   // 未開啟則失敗
    if (!writeCommand(cmd)) return false;         // 送指令失敗則回 false
    return readAnswer(answer, 250);               // 讀回覆（250ms 逾時）
}

bool MeterDevice::parseFloatAnswer(const QByteArray& ans, double& value) { // 解析浮點數
    bool ok=false;                                 // 轉換旗標
    value = QString::fromLatin1(ans).toDouble(&ok);// ASCII 轉 double
    return ok;                                     // 回傳是否成功
}

void MeterDevice::sendCommand(QString command) {
    if (!opened_ || !handle_) {
        emit errorText("尚未連線，無法發送指令");
        qDebug() << "尚未連線，無法發送指令";
        return;
    }
    qDebug() << "Sending command...";
    // --- 開頭*，命令轉成大寫 ASCII，附上 :結尾 ---
    QString fullCmd = "*" + command.trimmed().toUpper() + ":";
    QByteArray cmdBytes = fullCmd.toUtf8();

    DWORD bytesWritten = 0;
    FT_STATUS ftStatus = FT_Write(handle_, cmdBytes.data(), cmdBytes.size(), &bytesWritten);
    if (ftStatus != FT_OK || bytesWritten != (DWORD)cmdBytes.size()) {
        emit errorText("指令傳送失敗");
        return;
    }
    emit statusText("已送出: " + fullCmd.trimmed());

    // --- 等待回覆 ---
    BYTE buffer[256] = {0};
    DWORD bytesRead = 0;
    ftStatus = FT_Read(handle_, buffer, sizeof(buffer), &bytesRead);

    if (ftStatus == FT_OK && bytesRead > 0) {
        QString response = QString::fromLatin1((char*)buffer, bytesRead).trimmed();

        // 嘗試解析型別
        bool okInt = false;
        bool okFloat = false;
        int intVal = response.toInt(&okInt);
        float floatVal = response.toFloat(&okFloat);

        if (okInt && !response.contains('.')) {
            emit intReceived(intVal);
            emit statusText("收到整數: " + QString::number(intVal));
        }
        else if (okFloat) {
            emit floatReceived(floatVal);
            emit statusText("收到浮點數: " + QString::number(floatVal));
        }
        else {
            emit stringReceived(response);
            emit statusText("收到字串: " + response);
        }
    }
    else {
        emit statusText("未收到回覆");
    }
}

#define TIMEOUT_MILLISEC   5000  // Communication timeout [ms]
#define NUM_MULTI_READING  1000

#ifndef VI_ERROR_RSRC_NFOUND
#define VI_ERROR_RSRC_NFOUND 111
#endif

ThorLABS_MeterDevice::ThorLABS_MeterDevice(QObject* parent)
    : QObject(parent)
    , m_handle(VI_NULL) // 初始化為 NULL
{

}

ThorLABS_MeterDevice::~ThorLABS_MeterDevice() {
    disconnectThorLabsMeter();
}

ViStatus ThorLABS_MeterDevice::connectThorLabsMeter(const QString &resourceString)
{
    // 上鎖 (Scope 結束自動解鎖)
    QMutexLocker locker(&m_mutex);

    // 防呆：如果已經連線，先斷線
    if (m_handle != VI_NULL) {
        TLPM_close(m_handle);
        m_handle = VI_NULL;
    }

    QByteArray asciiData = resourceString.toLatin1();
    ViRsrc rsrcName = (ViRsrc)asciiData.data();

    // 呼叫底層 API
    // 建議：IDQuery=VI_FALSE, Reset=VI_FALSE 以加速連線
    ViStatus err = TLPM_init(rsrcName, VI_ON, VI_OFF, &m_handle);

    if (err == VI_SUCCESS) {
        qDebug() << "連線成功，Handle:" << m_handle;

        // 連線成功後，直接在這裡設定好環境，外部不用管
        // 請根據你的雷射波長設定
        ViReal64 wavelength = 1064; // 雷射是 1064nm
        err = TLPM_setWavelength(m_handle, wavelength);
        if(err) qDebug() << "Warning: 設定波長失敗 Code:" << Qt::hex << err;
        else    qDebug() << "波長設定 OK";

        // 設定單位為 Watts (防止 dBm 全黑時 NaN)
        err = TLPM_setPowerUnit(m_handle, TLPM_POWER_UNIT_WATT);
        if(err) qDebug() << "Warning: 設定單位(W)失敗 Code:" << Qt::hex << err;
        else    qDebug() << "單位設定 OK";

        // 開啟自動換檔 (Auto Range)
        // 避免因為檔位鎖死在過低或過高而報錯
        err = TLPM_setPowerAutoRange(m_handle, 1);
        if(err) qDebug() << "Warning: 設定AutoRange失敗 Code:" << Qt::hex << err;
        else    qDebug() << "AutoRange OK";

        // 這樣 measPower 就不會因為等待平均而 Timeout

        err = TLPM_setAvgCnt(m_handle, 1);
        if(err) qDebug() << "Warning: 設定AvgCount失敗 Code:" << Qt::hex << err;
        else    qDebug() << "AvgCount OK";

    } else {
        qDebug() << "連線失敗，代碼: 0x" << QString::number(err, 16).toUpper();
        m_handle = VI_NULL; // 確保失敗時狀態歸零
    }

    return err;
}

ViStatus ThorLABS_MeterDevice::disconnectThorLabsMeter()
{
    QMutexLocker locker(&m_mutex);

    if (m_handle == VI_NULL) {
        return VI_SUCCESS; // 本來就沒連線
    }

    ViStatus err = TLPM_close (m_handle);
    m_handle = VI_NULL; // 【重要】歸零
    qDebug() << "裝置已斷線";

    return err;
}

// 輔助函式：檢查是否連線
bool ThorLABS_MeterDevice::isConnected() const
{
    QMutexLocker locker(&m_mutex);
    return (m_handle != VI_NULL);
}

/*---------------------------------------------------------------------------
  Measure Power
---------------------------------------------------------------------------*/
ViStatus ThorLABS_MeterDevice::get_power(double &outputPower, QString &outputUnit)
{
    ViStatus       err = VI_SUCCESS;
    ViInt16        power_unit;
    char           *unit;

    err = TLPM_getPowerUnit(m_handle, &power_unit);
    if (err != VI_SUCCESS) return err;
    switch(power_unit)
    {
    case TLPM_POWER_UNIT_DBM: outputUnit = "dBm";break;
    default: outputUnit = "W";break;
    }
    err = TLPM_measPower(m_handle, &outputPower);

    return (err);

}

/*---------------------------------------------------------------------------
  User Power Calibration
---------------------------------------------------------------------------*/
ViStatus ThorLABS_MeterDevice::userPowerCalibration()
{

}

/*---------------------------------------------------------------------------
  Find Instruments
---------------------------------------------------------------------------*/
QList<ThorLABS_MeterDevice::DeviceInfo> ThorLABS_MeterDevice::scan_instruments()
{
    QList<DeviceInfo> list;
    ViUInt32 deviceCount = 0;

    // 1. 尋找裝置
    ViStatus err = TLPM_findRsrc(0, &deviceCount);
    if (err != VI_SUCCESS || deviceCount == 0) return list;

    // 2. 遍歷裝置
    for (ViUInt32 i = 0; i < deviceCount; ++i) {
        ViChar model[TLPM_BUFFER_SIZE];
        ViChar sernr[TLPM_BUFFER_SIZE];
        ViChar rsrcName[TLPM_BUFFER_SIZE]; // 這是 VISA Resource String
        ViBoolean available;

        // 注意：TLPM_getRsrcInfo 參數順序需依照你的 API 版本確認
        // 這裡假設有方法可以取得 resourceName，通常 TLPM_getRsrcName 存在
        // 如果沒有 TLPM_getRsrcName，通常 TLPM_getRsrcInfo 內部某個參數就是 Resource String

        TLPM_getRsrcInfo(0, i, model, sernr, NULL, &available);
        TLPM_getRsrcName(0, i, rsrcName); // 這是關鍵，必須取得 Resource Name

        DeviceInfo info;
        info.model = QString::fromLatin1(model);
        info.serialNumber = QString::fromLatin1(sernr);
        info.resourceString = QString::fromLatin1(rsrcName);
        info.isAvailable = (available != 0);

        list.append(info);
    }
    return list;
}

void Delay(int ms) {
    QEventLoop waitloop;
    QTimer::singleShot(ms, &waitloop, SLOT(quit()));
    waitloop.exec();
}

void ThorLABS_MeterDevice::updatePowerReading()
{
    // 1. 上鎖
    QMutexLocker locker(&m_mutex);

    // 2. 檢查連線狀態 (這一步非常重要，防止崩潰)
    if (m_handle == VI_NULL) {
        // 沒連線就不要做事
        return;
    }
    ViStatus err = VI_SUCCESS;
    ViReal64       power = 0.0;
    ViInt16        power_unit;
    char           *unit;
    // 3. 呼叫量測
    err = TLPM_getPowerUnit(m_handle, &power_unit);
    switch(power_unit)
    {
    case TLPM_POWER_UNIT_DBM: unit = "dBm";break;
    default: unit = "W";break;
    }
    if(!err) err = TLPM_measPower(m_handle, &power);

    // 4. 錯誤處理
    if(!err){
        qDebug() << QString("更新measPower: %1").arg(power);
        emit update_measPower(power);

    }else if (err == 0x3FFC0903) {
        // 處理 NaN (Overload/Underload)
        qDebug() << "Warning: NaN detected (Low signal or Overload)";
        // 視需求決定是否發送 0 或 -1
        // emit update_measPower(0.0);
    }
    else {
        qDebug() << "量測失敗 Code: 0x" << QString::number(err, 16).toUpper();
        // 如果是 Timeout (0xBFFF0015)，通常忽略
        // 如果是嚴重錯誤，才考慮發送 errorOccurred 信號
    }

    // 注意：這裡不需要管理 Timer，Timer 由 MainWindow 控制
    // 解鎖會在這裡自動發生 (locker 解構)
}



