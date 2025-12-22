/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbl_enginerMode;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_user;
    QLineEdit *line_user;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_password;
    QLineEdit *line_password;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_login;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(460, 280);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName("verticalLayout");
        lbl_enginerMode = new QLabel(Login);
        lbl_enginerMode->setObjectName("lbl_enginerMode");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        lbl_enginerMode->setFont(font);
        lbl_enginerMode->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lbl_enginerMode);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lbl_user = new QLabel(Login);
        lbl_user->setObjectName("lbl_user");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_user->sizePolicy().hasHeightForWidth());
        lbl_user->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lbl_user);

        line_user = new QLineEdit(Login);
        line_user->setObjectName("line_user");

        horizontalLayout->addWidget(line_user);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_password = new QLabel(Login);
        lbl_password->setObjectName("lbl_password");

        horizontalLayout_2->addWidget(lbl_password);

        line_password = new QLineEdit(Login);
        line_password->setObjectName("line_password");

        horizontalLayout_2->addWidget(line_password);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btn_login = new QPushButton(Login);
        btn_login->setObjectName("btn_login");
        sizePolicy.setHeightForWidth(btn_login->sizePolicy().hasHeightForWidth());
        btn_login->setSizePolicy(sizePolicy);
        btn_login->setMinimumSize(QSize(150, 0));
        btn_login->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(btn_login);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 2);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        lbl_enginerMode->setText(QCoreApplication::translate("Login", "Enginerring Mode ", nullptr));
        lbl_user->setText(QCoreApplication::translate("Login", "User Name", nullptr));
        lbl_password->setText(QCoreApplication::translate("Login", "Password", nullptr));
        btn_login->setText(QCoreApplication::translate("Login", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
