/********************************************************************************
** Form generated from reading UI file 'StressTesting.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRESSTESTING_H
#define UI_STRESSTESTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StressTesting
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbl_title;
    QLabel *lbl_currentTime;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_Input;
    QLineEdit *line_Input;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_Key;
    QLineEdit *line_Key;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_Repeat;
    QSpinBox *sp_Repeat;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_start;
    QPushButton *btn_stop;

    void setupUi(QWidget *StressTesting)
    {
        if (StressTesting->objectName().isEmpty())
            StressTesting->setObjectName("StressTesting");
        StressTesting->resize(640, 480);
        verticalLayout = new QVBoxLayout(StressTesting);
        verticalLayout->setObjectName("verticalLayout");
        lbl_title = new QLabel(StressTesting);
        lbl_title->setObjectName("lbl_title");
        QFont font;
        font.setPointSize(18);
        lbl_title->setFont(font);
        lbl_title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lbl_title);

        lbl_currentTime = new QLabel(StressTesting);
        lbl_currentTime->setObjectName("lbl_currentTime");
        QFont font1;
        font1.setPointSize(13);
        lbl_currentTime->setFont(font1);

        verticalLayout->addWidget(lbl_currentTime);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 0, 10, -1);
        lbl_Input = new QLabel(StressTesting);
        lbl_Input->setObjectName("lbl_Input");

        horizontalLayout_2->addWidget(lbl_Input);

        line_Input = new QLineEdit(StressTesting);
        line_Input->setObjectName("line_Input");

        horizontalLayout_2->addWidget(line_Input);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 6);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, 0, 10, -1);
        lbl_Key = new QLabel(StressTesting);
        lbl_Key->setObjectName("lbl_Key");

        horizontalLayout_3->addWidget(lbl_Key);

        line_Key = new QLineEdit(StressTesting);
        line_Key->setObjectName("line_Key");

        horizontalLayout_3->addWidget(line_Key);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 6);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 0, 10, -1);
        lbl_Repeat = new QLabel(StressTesting);
        lbl_Repeat->setObjectName("lbl_Repeat");

        horizontalLayout->addWidget(lbl_Repeat);

        sp_Repeat = new QSpinBox(StressTesting);
        sp_Repeat->setObjectName("sp_Repeat");

        horizontalLayout->addWidget(sp_Repeat);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 6);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btn_start = new QPushButton(StressTesting);
        btn_start->setObjectName("btn_start");

        horizontalLayout_4->addWidget(btn_start);

        btn_stop = new QPushButton(StressTesting);
        btn_stop->setObjectName("btn_stop");

        horizontalLayout_4->addWidget(btn_stop);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(StressTesting);

        QMetaObject::connectSlotsByName(StressTesting);
    } // setupUi

    void retranslateUi(QWidget *StressTesting)
    {
        StressTesting->setWindowTitle(QCoreApplication::translate("StressTesting", "Form", nullptr));
        lbl_title->setText(QCoreApplication::translate("StressTesting", "Stress Testing", nullptr));
        lbl_currentTime->setText(QCoreApplication::translate("StressTesting", "Current Time:", nullptr));
        lbl_Input->setText(QCoreApplication::translate("StressTesting", "Input Command", nullptr));
        lbl_Key->setText(QCoreApplication::translate("StressTesting", "Key word", nullptr));
        lbl_Repeat->setText(QCoreApplication::translate("StressTesting", "Repeat Time", nullptr));
        btn_start->setText(QCoreApplication::translate("StressTesting", "Start", nullptr));
        btn_stop->setText(QCoreApplication::translate("StressTesting", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StressTesting: public Ui_StressTesting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRESSTESTING_H
