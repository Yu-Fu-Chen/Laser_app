#pragma once // 防止重複包含此標頭
#include <QObject>       // 使用 Qt 的 QObject 基類
#include <QString>       // 使用 QString 字串
#include <QByteArray>    // 使用 QByteArray 位元組陣列
#include <QTimer>        // 使用 QTimer 做週期輪詢
#include <QWidget>
#include <QPainter>
#include <QTcpSocket>    // 引入 QTcpSocket（TCP 連線）
#include <QSerialPort>   // 引入 QSerialPort（序列埠）
#include <QMutex>        // 必須引入
#include <QMutexLocker>  // 必須引入
#include <QQueue>

// 引入 FTDI D2XX 標頭（請確認路徑已在 CMake 中設定）
#include "ftd2xx.h" // 提供 FT_Open / FT_Read / FT_Write 等 API
#include "TLPM.h"

class  LaserDriver : public QObject
{
    Q_OBJECT
public:
    explicit LaserDriver(QObject* parent=nullptr);
    ~LaserDriver();

    int intervalMs = 20;         // 送出字元間隔時間
    bool isConnected = false;
    bool onConnectSock();
    bool onConnectserial(QString port, int Baud, int Parity, int DataBits, int StopBits);

public slots:
    void onSerialErrorOccurred(QSerialPort::SerialPortError e);
    void onSerialReadyRead();
    void transmit(const QByteArray& bytes);
    void sendAndWait(const QString& cmd);

signals:
    void connectfinish();
    void serialRead(QString line);
    void SerialError(QString msg);

private:
    int currentMode;        // 目前連線模式

    // 核心 I/O 物件
    QTcpSocket* sock_ = nullptr;                                    // TCP Socket 物件
    QSerialPort* serial_ = nullptr;                                 // Serial Port 物件

    // 收包緩衝，用於行為單位解析（以 \n 作為結束）
    QByteArray rxBuf_;                                              // 累積接收的位元資料直到遇到換行
    QQueue<QString> commandQueue;
    bool isSending = false; // 取代 available，標記是否正在工作中

private slots:
    void sendCommandSlowly(QByteArray command);

};

// MeterDevice：封裝光功率計（透過 FTDI D2XX + 私有協定）的開啟、指令與讀取
class MeterDevice : public QObject { // 繼承 QObject 以便使用 signal/slot
    Q_OBJECT // 啟用 Qt 的 meta-object（signal/slot）
    friend class AutoP;

public:
    explicit MeterDevice(QObject* parent=nullptr); // 建構子，預設無父物件
    ~MeterDevice();                                 // 解構子，釋放資源

    bool open(int index = 0);     // 開啟第 index 台 FTDI 裝置（0 表第一台）
    void close();                 // 關閉目前已開啟的裝置
    bool isOpen() const { return opened_; } // 回傳裝置是否已開啟

    bool initializeDConnect();    // 初始化裝置連線
    bool initializeForPower();    // 初始化成功率模式（*POWER: + 檢查測頭）
    //ThermometerWidget* thermometer;

public slots:                     // 對外提供可連到 UI 的槽
    void startPolling(int intervalMs = 200); // 依間隔開始輪詢 *OUTPM: 取功率
    void stopPolling();                      // 停止輪詢
    void sendCommand(QString command); // 傳送指令（ASCII大寫）

signals:                          // 對外發出事件給 UI
    void powerUpdated(double watts);       // 成功取得功率（單位 W）
    void statusText(const QString& msg);   // 一般狀態文字
    void errorText(const QString& msg);    // 錯誤狀態文字
    void stringReceived(QString text);     // 回傳文字
    void intReceived(int value);           // 回傳整數
    void floatReceived(float value);       // 回傳浮點數

private:                          // 內部工具函式（不對外）
    bool writeCommand(const QByteArray& cmd);              // 寫入一條 "*CMD:" 指令
    bool readAnswer(QByteArray& out, int maxWaitMs = 250); // 讀到分號 ';' 為止
    bool sendAndRead(const QByteArray& cmd, QByteArray& answer); // 合併送/收
    bool parseFloatAnswer(const QByteArray& ans, double& value); // 將 ASCII 轉成 double
    bool headPresent();                                   // *STATUS: 檢查 bit2（測頭存在）
    bool setPowerMode();                                  // *POWER: 切換功率模式

private:                          // 成員變數
    FT_HANDLE handle_ = nullptr;  // D2XX 連線控制代碼
    bool opened_ = false;         // 是否已成功開啟
    QTimer poller_;               // 定時器做輪詢
};

class ThorLABS_MeterDevice: public QObject{
    Q_OBJECT
public:
    ThorLABS_MeterDevice(QObject* parent = nullptr);
    ~ThorLABS_MeterDevice();

    struct DeviceInfo {
        QString model;
        QString serialNumber;
        QString resourceString; // 這是連線用的關鍵
        bool isAvailable;
    };

    ViStatus connectThorLabsMeter(const QString &rsrcString);
    ViStatus disconnectThorLabsMeter();
    bool isConnected() const; // 輔助函式：檢查連線狀態

    void updatePowerReading();

    QList<DeviceInfo> scan_instruments();

    ViStatus userPowerCalibration();

signals:
    void update_measPower(double pw);
    void errorOccurred(QString msg);     // 發送錯誤訊息

private:
    ViSession m_handle;     // 用來存儀器的 Handle (ViSession)
    mutable QMutex m_mutex; // 執行緒安全鎖 (mutable 允許在 const 函式中使用)

    ViStatus get_power(double &outputPower, QString &outputUnit);   // 內部使用的 helper

};
