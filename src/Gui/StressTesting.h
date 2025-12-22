#ifndef STRESSTESTING_H
#define STRESSTESTING_H

#include <QWidget>
#include <QDateTime>
#include <QStyleOption>
#include <QPainter>

#include "Automation.h"
#include "ConnectDevice.h"

namespace Ui {
class StressTesting;
}

class StressTesting : public QWidget
{
    Q_OBJECT

public:
    explicit StressTesting(QWidget *parent = nullptr, AutoP* auto_ = nullptr, LaserDriver* laser = nullptr);
    ~StressTesting();

    bool ST_Implement = false;
    QString command;
    QString KeyWord;
    int time;

signals:
    void ST_finish();
    void abnormal_msg(QString msg);

private:
    Ui::StressTesting *ui;

    LaserDriver* laser_ = nullptr;
    AutoP* autoP_ = nullptr;

    QMetaObject::Connection ST_linking;

    QTimer* StressTimer;
    QRegularExpression regex;

    int countT = 0;
    void ST_roop(QString cmd, QString key, int t);

protected:
    // 處理繪圖事件
    void paintEvent(QPaintEvent *event) override;
};

#endif // STRESSTESTING_H
