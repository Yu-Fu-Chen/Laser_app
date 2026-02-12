#pragma once // 防止重複包含此標頭
#ifndef AUTOMATION_H
#define AUTOMATION_H

#include <QObject>    // 使用 Qt 的 QObject 基類
#include <QString>    // 使用 QString 字串
#include <QByteArray> // 使用 QByteArray 位元組陣列
#include <QTimer>     // 使用 QTimer 做週期輪詢
#include <QFile>
#include <QWaitCondition>
#include <QMutex>
#include <vector>
#include <QRegularExpression>

#include "ConnectDevice.h"
#include "PowerCheck.h"

#include "Simulation.h"

using namespace std;

class LoggerObject : public QObject {
    Q_OBJECT

public:
    explicit LoggerObject(QObject* parent = nullptr);
    ~LoggerObject();
    QString dateStr;
    QString fileName;

    void writeLog(const QString& message);

private:
    QFile* logFile = nullptr;
    QTextStream* log = nullptr;
};

class AutoP:public QObject {
    Q_OBJECT

public:
    explicit AutoP(QObject* parent=nullptr, MeterDevice* meter_ = nullptr, LaserDriver* laser_ = nullptr, Simulation* simulation_ = nullptr); // 建構子，預設無父物件
    ~AutoP();                                 // 解構子，釋放資源

    int model;
    int dacSet;                               // DAC 設定值
    int dcSet;                                // PD校正 DC設定值
    int dacRrange = 10;                            // DAC 迴圈範圍
    int dacAdd =10;                               // 每次迴圈DAC增加的量值
    double low_tol = 0.25;
    double high_tol = 0.1;
    int tol_divide = 300;
    const int cmd_singleWait = 20;
    int loop_msWait = 30000;                   // 每次測試，迴圈等待時間(單位ms)

    vector<double> setValue;                      // setValue vecter
    vector<double> measured;                     // measured vecter
    vector<int> PD1;
    vector<int> PD2;
    LinearFitResult Ld_fit;                   // LD擬合之a、b
    LinearFitResult Laser_fit;                // Laser擬合之a、b
    LinearFitResult testFit;
    LinearFitResult resultFit1;
    LinearFitResult resultFit2;
    QFile* filelog;
    QTextStream* log;

    // 程序狀態
    enum ProcessState {RUNNING, PAUSED, STOPPED, ERRO};
    ProcessState currentStatus = STOPPED;      // 初始值為STOPPED

    // Function open
    bool measureCheckOpen;
    bool PDvalueCheckOpen;

    // 音檔位置
    QString errorMusic = "./sound/powerTest_error.wav";

public slots:
    // 外部可用的函數
    void AutoPinit();
    void playmusicWithWarning(const QString & msg);         // 錯誤發生時播放音檔與彈出錯誤視窗
    void initialization();                                  // 初始化程序
    double takeMeterPower();                                // 取得meter數值，return -10表錯誤
    void startProcess1();                                   // LD檢測程序
    void startProcess2();                                   // Laser檢測程序
    void startProcess3();                                   // PD校正程序
    void pauseProcess();
    void resumeProcess();
    void stopProcess();
    void sendcommand(const QString& command);
    void powerOff();
    QString vecToQString(const vector<double>& x, const vector<double>& y) const;
    QString PDvecToQString(const vector<int>& x) const;

private:
    bool PausetoRun = false;

    // 內部參數
    bool isInit = false;
    int program;                              // 目前要執行的程序
    int progStack;                            // 暫停時儲存目前程序
    int countPD;
    const int powerPDLimit = 700;                         // 限制PD test power上限
    const int powerLaserLimit = 525;                      // 限制Laser test power上限

    QRegularExpression regex1;
    QRegularExpression regex2;
    QRegularExpression regex3;
    QRegularExpression regex4;
    std::optional<int> pendingPD_protection;
    std::optional<int> pendingOutput_PD_protection;


    QMetaObject::Connection protectionConnection_; // 具名連線

    // 自動化程序相關功能函數
    void processStep();                    // 程序步驟
    void pushData(double data);                       // 將數據加入尾端
    void endFitting();                     // 程序結束時做擬合
    void finishProcess();
    void errorProcess();
    void powerLoop();

    bool measureCheck(double measured, double setvalue,LinearFitResult fit) const;
    bool protectionCheck();
    LinearFitResult fitting(vector<double>& x, vector<double>& y);
    vector<double> pdAverageVector(vector<int>& x);

    // 自訂義物件
    MeterDevice* meter_;
    LaserDriver* laser_;
    Simulation* Simulation_;
    QTimer* processTimer;
    QTimer* PDTimer;


signals:
    void statusText(const QString& msg);   // 一般狀態文字
    void errorSignal(const QString& info, const QString& msg);    // 錯誤狀態文字
    void addCommandtoLog(const QString& command);
    void powerDoub(const QString& info,const QString& power);
    void processFinished();
    void PDerror();
};

#define Laser_500W 1;
#define Laser_1000W 2;
#define Laser_5000W 3;

#endif // AUTOMATION_H
