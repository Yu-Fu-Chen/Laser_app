#pragma once                                                        // 防止重複 include 的編譯保護

#include <QMainWindow>                                              // 引入 QMainWindow 基底類別
#include <QTcpSocket>                                               // 引入 QTcpSocket（TCP 連線）
#include <QSerialPort>                                              // 引入 QSerialPort（序列埠）
#include <QSerialPortInfo>                                          // 引入 QSerialPortInfo（列舉序列埠）
#include <QDateTime>                                                // 引入 QDateTime（時間戳）
#include <QByteArray>                                               // 引入 QByteArray（原始位元資料）
#include <QThread>
#include <QMessageBox>
#include <QLineEdit>
#include <QFutureWatcher>

#include "ConnectDevice.h"                 // 引入我們的裝置封裝
#include "Automation.h"                  // 引入自動化程序
#include "Simulation.h"
#include "StressTesting.h"
#include "Login.h"

//#include "ftdithread.h"

void writeLog(QString& log, LoggerObject* logObject);

QT_BEGIN_NAMESPACE                                                  // 告知接下來是 Qt 命名空間的前置宣告
namespace Ui { class MainWindow; }                                  // 前置宣告由 .ui 生成的 Ui::MainWindow 類（ui_MainWindow.h）
QT_END_NAMESPACE                                                    // 結束 Qt 命名空間前置宣告範圍

// MainWindow：應用程式主視窗，負責連線與 UI 控制
class MainWindow : public QMainWindow {                             // 宣告 MainWindow 類別，繼承 QMainWindow
    Q_OBJECT                                                        // 啟用 Qt Meta-Object（signals/slots）機制的巨集
public:                                                             // 公開成員區
    explicit MainWindow(QWidget* parent = nullptr);                 // 建構子：可傳入父物件（預設空）
    ~MainWindow() override;                                         // 解構子：釋放資源

signals:
    void cmdFinished();


protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent* event) override;


private:                                                            // 私有工具函式與成員
    QSize  baseSize_;
    qreal  baseFontPointSize_ = 10.0;
    int currentPage = 0;
    bool isEnginerring = false;
    enum class Mode { TCP, Serial };                                // 連線模式列舉：TCP 或 Serial
    QString selectedProgram;

    const int dacinit = 0;
    const int dacRang = 1365;
    //int cmdSingDelay = 30;
    //int comdDelay = cmdSingDelay*8;
    bool cmdisOk = true;

    void initWindowsUi();
    void initLaser();
    void initLaserMDevice();
    void initThorMDevice();
    void initAutoP();
    void delay(int ms);

    // 來自 .ui 的元件指標（由 Ui::MainWindow 建立，這邊只保留指標給使用）
    Ui::MainWindow* ui = nullptr;                                   // 指向自動生成的 UI 類別

    // 核心 I/O 物件
    Simulation* Simulation_ = nullptr;
    Login* login_ = nullptr;
    StressTesting* Stress_ = nullptr;
    QTcpSocket* sock_ = nullptr;                                    // TCP Socket 物件
    QSerialPort* serial_ = nullptr;                                 // Serial Port 物件

    // 收包緩衝，用於行為單位解析（以 \n 作為結束）
    QByteArray rxBuf_;                                              // 累積接收的位元資料直到遇到換行

    // Laser設備指標
    LaserDriver* laser_ = nullptr;
    // Meter設備指標
    MeterDevice* Laser_meter_ = nullptr;   // 我們的裝置成員（組合使用)
    QTimer MmeasureTimer;
    ThorLABS_MeterDevice* Thor_meter_ = nullptr;
    // QThread *thread;
    QThread *autoPThread;
    AutoP* autoP_ = nullptr;         // 自動化物件

    // 用來管理非同步任務
    QFutureWatcher<QList<ThorLABS_MeterDevice::DeviceInfo>> *scanWatcher;
    // 目前的連線 Session (Handle)
    ViSession currentSession_ = VI_NULL;

private slots:          // Qt 的 slot（訊號連接的接收端）
    // WindowUI init
    void openSimulation();
    void openLogin();
    void openStressTest();
    void setEnginerring(bool ok);
    void onConnectClicked();                                        // 處理 Connect/Disconnect 按鈕點擊
    void onSocketConnected();                                       // TCP 連上時的回呼
    void onSocketDisconnected();                                    // TCP 斷線時的回呼
    void onSocketReadyRead();                                       // TCP 有資料可讀時的回呼
    void onErrorOccurred(QAbstractSocket::SocketError);             // TCP 發生錯誤時的回呼
    bool sendCommand(const QString& cmd);
    void sendArbitrary();                                           // 送出命令輸入框內的自訂指令
    void changSDCorSDAC(int index);                                 // 改變成SDC or SDAC
    void switchPage(int page);
    void refreshSConnect();                                      // 重新列舉序列埠
    void saveLogToFile();                                           // 將日誌存檔
    void clearLog();                                                // 清空日誌
    void loadSettings(QString model = "500W Laser");     // 載入設定
    void saveSettings(QString model = "500W Laser");     // 儲存設定
    void updateUiScale();
    void applyAdaptiveSpacing();
    void appendLog(const QString& line, bool isTx);                 // 在日誌視窗新增一行（含 TX/RX 標記與時間戳）
    void setConnected(bool ok);                                     // 更新連線狀態（按鈕文字與標籤）
    void showMessageBox(QMessageBox::Icon icon,
                        const QString &title,
                        const QString &text,
                        const QString &infoText = QString());
    void lineValidator(QLineEdit* ui,double min, double max,int f);
    void lineValidator(QLineEdit* ui,int min, int max);
    Mode currentMode() const;                                       // 取得目前模式（依 Tab）

    // LaserPoint Meter init
    void onMConnectClicked();       // 處理「Connect」按鈕
    void setMConnected(bool ok);
    void onMSWaveSelect(const QString s);         // 處理Wave設定
    void setMStarted(bool ok);
    void onMPowerUpdated(double w); // 收到功率更新事件
    void onMStatusText(const QString& s); // 收到狀態文字
    void onMErrorText(const QString& s);  // 收到錯誤文字
    void onbtnMSendClicked();

    // Thor Meter init
    void onbtnScanClicked();
    void onbtnThorMConnectCclicked();
    void onScanFinished(); // 用來接收掃描完成的 Slot
    void onTimerTimeout();

    // Thor AutoP init
    void onAutoPStatusText(const QString& s);
    void onAutoLogText(const QString& info, const QString& mag);
};
