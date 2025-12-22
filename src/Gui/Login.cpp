#include "Login.h"
#include "src/Gui/ui_Login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{

    ui->setupUi(this);
    setWindowFlag(Qt::Window);   // 或 Qt::Dialog
    setWindowTitle("Login");

    connect(ui->btn_login, &QPushButton::clicked, this, [this]() {
        if(ui->btn_login->text() == "Logout") {
            islogin = false;
            setlogin(islogin);

        }else{
        if(ui->line_user->text() != "") {qDebug() << "登入失敗"; return;}
        if(ui->line_password->text() != "") {qDebug() << "登入失敗"; return;}
        islogin = true;
        qDebug() << "登入成功";
        setlogin(islogin);
        }
    });
}

void Login::setlogin(bool ok) {
    qDebug() << QString("送出%1訊號").arg(ok ? "login":"logout");
    ui->btn_login->setText(QString(ok ? "Logout":"Login"));
    emit loginFinsh(ok);
}

void Login::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);

    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
