#include "StressTesting.h"
#include "src/Gui/ui_StressTesting.h"
#include <QRegularExpression>

#include <qtimer.h>
int msPeriod = 500;

StressTesting::StressTesting(QWidget *parent, AutoP* autoP, LaserDriver* laser)
    : QWidget(parent)
    , ui(new Ui::StressTesting)
    , laser_(laser)
    , autoP_(autoP)
    , regex("Frequency:\\s*(\\d+(?:\\.\\d+)?)")
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);   // 或 Qt::Dialog
    setWindowTitle("StressTesting");

    ui->sp_Repeat->setMaximum(100);
    StressTimer = new QTimer(this);

    connect(ui->btn_start, &QPushButton::clicked, this, [this]() {
        command = ui->line_Input->text();
        KeyWord = ui->line_Key->text();
        time = ui->sp_Repeat->value()*60*1000;
        ST_roop(command, KeyWord, time);
        StressTimer->start(msPeriod);
    });
    connect(ui->btn_stop, &QPushButton::clicked, this, [this]() {
        StressTimer->stop();
        countT = 0;
    });

    connect(StressTimer, &QTimer::timeout, this, [this]() {
        ST_roop(command, KeyWord, time);
    });


}

StressTesting::~StressTesting()
{
    delete ui;
}

void StressTesting::ST_roop(QString cmd, QString key, int t) {
    laser_->sendAndWait(QString("%1").arg(cmd));
    //if(countT % 3 == 0)
    //autoP_->sendAndWait("sdc0");
    ST_linking = connect(laser_, &LaserDriver::serialRead, this, [this, &key](const QString& rawLine) {
        QString line = rawLine.trimmed();

        if (line.isEmpty()) return;

        //qDebug() << "StressTesting接收到：" << line;
        //qDebug() << "Line (hex):" << line.toUtf8().toHex();
        //qDebug() << "Line (text):" << line;

        const auto match = regex.match(line.trimmed());
        if (match.hasMatch()) {
            disconnect(ST_linking);
            double backvalue = match.captured(1).toDouble();
            if(backvalue <1000*0.9 || backvalue > 1000*1.1) {
                const QString ts = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz"); // 製作時間戳
                emit abnormal_msg(QString("[%1]: %2").arg(ts).arg(backvalue));
                qDebug() << "StressTesting接收到：" << line;
            }
        }
    });
    countT += msPeriod;
    if(countT >= t) {StressTimer->stop(); countT = 0;}
}

void StressTesting::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);

    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
