#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class Login;
}

class Login: public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr);
    bool islogin = false;

    void setlogin(bool ok);

signals:
    void loginFinsh(bool ok);

private:
    QString userName;
    QString PassWord;

    Ui::Login *ui;

protected:
    // 處理繪圖事件
    void paintEvent(QPaintEvent *event) override;

};

#endif // LOGIN_H
