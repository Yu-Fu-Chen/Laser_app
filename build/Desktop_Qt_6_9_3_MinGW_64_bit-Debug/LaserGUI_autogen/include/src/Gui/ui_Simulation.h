/********************************************************************************
** Form generated from reading UI file 'Simulation.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATION_H
#define UI_SIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simulation
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QComboBox *cb_connect;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_connect;
    QPushButton *btn_disconnect;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_Channel;
    QCheckBox *ckb_Channel_on;
    QCheckBox *ckb_Channel_off;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_QBH;
    QCheckBox *ckb_QBH_on;
    QCheckBox *ckb_QBH_off;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_MainPower;
    QCheckBox *ckb_MainPower_on;
    QCheckBox *ckb_MainPower_off;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_LaserEnable;
    QCheckBox *ckb_LaserEnable_on;
    QCheckBox *ckb_LaserEnable_off;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_testOn;
    QPushButton *btn_testOff;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Simulation)
    {
        if (Simulation->objectName().isEmpty())
            Simulation->setObjectName("Simulation");
        Simulation->resize(480, 640);
        verticalLayout_2 = new QVBoxLayout(Simulation);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(Simulation);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        groupBox = new QGroupBox(Simulation);
        groupBox->setObjectName("groupBox");
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        cb_connect = new QComboBox(groupBox);
        cb_connect->setObjectName("cb_connect");

        verticalLayout_3->addWidget(cb_connect);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btn_connect = new QPushButton(groupBox);
        btn_connect->setObjectName("btn_connect");

        horizontalLayout_5->addWidget(btn_connect);

        btn_disconnect = new QPushButton(groupBox);
        btn_disconnect->setObjectName("btn_disconnect");

        horizontalLayout_5->addWidget(btn_disconnect);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lbl_Channel = new QLabel(Simulation);
        lbl_Channel->setObjectName("lbl_Channel");

        horizontalLayout->addWidget(lbl_Channel);

        ckb_Channel_on = new QCheckBox(Simulation);
        ckb_Channel_on->setObjectName("ckb_Channel_on");

        horizontalLayout->addWidget(ckb_Channel_on);

        ckb_Channel_off = new QCheckBox(Simulation);
        ckb_Channel_off->setObjectName("ckb_Channel_off");

        horizontalLayout->addWidget(ckb_Channel_off);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_QBH = new QLabel(Simulation);
        lbl_QBH->setObjectName("lbl_QBH");

        horizontalLayout_2->addWidget(lbl_QBH);

        ckb_QBH_on = new QCheckBox(Simulation);
        ckb_QBH_on->setObjectName("ckb_QBH_on");

        horizontalLayout_2->addWidget(ckb_QBH_on);

        ckb_QBH_off = new QCheckBox(Simulation);
        ckb_QBH_off->setObjectName("ckb_QBH_off");

        horizontalLayout_2->addWidget(ckb_QBH_off);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lbl_MainPower = new QLabel(Simulation);
        lbl_MainPower->setObjectName("lbl_MainPower");

        horizontalLayout_3->addWidget(lbl_MainPower);

        ckb_MainPower_on = new QCheckBox(Simulation);
        ckb_MainPower_on->setObjectName("ckb_MainPower_on");

        horizontalLayout_3->addWidget(ckb_MainPower_on);

        ckb_MainPower_off = new QCheckBox(Simulation);
        ckb_MainPower_off->setObjectName("ckb_MainPower_off");

        horizontalLayout_3->addWidget(ckb_MainPower_off);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lbl_LaserEnable = new QLabel(Simulation);
        lbl_LaserEnable->setObjectName("lbl_LaserEnable");

        horizontalLayout_4->addWidget(lbl_LaserEnable);

        ckb_LaserEnable_on = new QCheckBox(Simulation);
        ckb_LaserEnable_on->setObjectName("ckb_LaserEnable_on");

        horizontalLayout_4->addWidget(ckb_LaserEnable_on);

        ckb_LaserEnable_off = new QCheckBox(Simulation);
        ckb_LaserEnable_off->setObjectName("ckb_LaserEnable_off");

        horizontalLayout_4->addWidget(ckb_LaserEnable_off);


        verticalLayout_2->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(Simulation);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        btn_testOn = new QPushButton(groupBox_2);
        btn_testOn->setObjectName("btn_testOn");

        horizontalLayout_6->addWidget(btn_testOn);

        btn_testOff = new QPushButton(groupBox_2);
        btn_testOff->setObjectName("btn_testOff");

        horizontalLayout_6->addWidget(btn_testOff);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 176, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        retranslateUi(Simulation);

        QMetaObject::connectSlotsByName(Simulation);
    } // setupUi

    void retranslateUi(QWidget *Simulation)
    {
        Simulation->setWindowTitle(QCoreApplication::translate("Simulation", "Form", nullptr));
        label->setText(QCoreApplication::translate("Simulation", "Simulation", nullptr));
        groupBox->setTitle(QString());
        btn_connect->setText(QCoreApplication::translate("Simulation", "Connect", nullptr));
        btn_disconnect->setText(QCoreApplication::translate("Simulation", "Disconnect", nullptr));
        lbl_Channel->setText(QCoreApplication::translate("Simulation", "Interlack Channel", nullptr));
        ckb_Channel_on->setText(QCoreApplication::translate("Simulation", "ON", nullptr));
        ckb_Channel_off->setText(QCoreApplication::translate("Simulation", "Off", nullptr));
        lbl_QBH->setText(QCoreApplication::translate("Simulation", "Interlack QBH", nullptr));
        ckb_QBH_on->setText(QCoreApplication::translate("Simulation", "ON", nullptr));
        ckb_QBH_off->setText(QCoreApplication::translate("Simulation", "Off", nullptr));
        lbl_MainPower->setText(QCoreApplication::translate("Simulation", "Main Power", nullptr));
        ckb_MainPower_on->setText(QCoreApplication::translate("Simulation", "ON", nullptr));
        ckb_MainPower_off->setText(QCoreApplication::translate("Simulation", "Off", nullptr));
        lbl_LaserEnable->setText(QCoreApplication::translate("Simulation", "Laser Enable", nullptr));
        ckb_LaserEnable_on->setText(QCoreApplication::translate("Simulation", "ON", nullptr));
        ckb_LaserEnable_off->setText(QCoreApplication::translate("Simulation", "Off", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Simulation", "Test Simulation", nullptr));
        btn_testOn->setText(QCoreApplication::translate("Simulation", "ON", nullptr));
        btn_testOff->setText(QCoreApplication::translate("Simulation", "OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simulation: public Ui_Simulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATION_H
