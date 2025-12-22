#include <QApplication>                                              // 引入 QApplication，Qt Widgets 程式的核心應用物件
#include "MainWindow.h"                                             // 引入自訂的主視窗類別定義
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[]) {                                   // 程式進入點：main 函式，帶入命令列參數
    QApplication app(argc, argv);                                    // 建立 Qt 應用程式物件，負責事件迴圈與資源管理
    QApplication::setApplicationName("LaserGUI");                   // 設定應用程式名稱（顯示與設定用）
    QApplication::setOrganizationName("KSECO");                     // 設定組織名稱（設定檔命名空間）

    // 載入 QSS 樣式表
    QFile f("./styles/laser_theme.qss");
    //QFile f(":/styles/laser_theme.qss");
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString css = QString::fromUtf8(f.readAll());
        app.setStyleSheet(css);
    }

    MainWindow w;                                                    // 建立主視窗物件
    w.resize(1180, 720);                                             // 設定主視窗初始大小
    w.show();                                                        // 顯示主視窗


    return app.exec();                                               // 進入事件迴圈，直到視窗關閉才返回
}
