/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actSaveLog;
    QAction *actClearLog;
    QAction *actionSimulation;
    QAction *actionSetting;
    QAction *actionEngineering;
    QAction *actionworking;
    QAction *actionSwitchPage;
    QAction *actionStress_Testing;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_11;
    QStackedWidget *stackedWidget;
    QWidget *Page_Auto;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_model;
    QComboBox *cb_model;
    QLabel *label_5;
    QLineEdit *line_laser_number;
    QLabel *lbl_laser_number;
    QHBoxLayout *horizontalLayout_34;
    QPushButton *btnPInit;
    QFrame *frame_PowerCheck_3;
    QHBoxLayout *horizontalLayout_33;
    QLabel *labelPowerTitle_3;
    QLabel *lblPower_3;
    QLabel *lblUnit_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnPRC1;
    QPushButton *btnPRC2;
    QPushButton *btnPRC3;
    QWidget *Page_Laser;
    QHBoxLayout *horizontalLayout_21;
    QTabWidget *tabWidget;
    QWidget *tab_Controls;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnDCD;
    QPushButton *btnDOPD;
    QPushButton *btnPowerOn;
    QPushButton *btnPowerOff;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnDLE;
    QPushButton *btnDEC;
    QPushButton *btnDMOD;
    QPushButton *btnEMON;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnABN;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QComboBox *cbPDx;
    QSpinBox *spL_PD;
    QLabel *label_3;
    QDoubleSpinBox *dspDT;
    QPushButton *btnRPD;
    QComboBox *cb_SDCorSDAC;
    QFrame *frame_SDAC1;
    QHBoxLayout *horizontalLayout_20;
    QComboBox *cb_selectSDAC;
    QSlider *sL1;
    QSpinBox *spL1;
    QGroupBox *centralwidget_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_36;
    QLabel *lblStatusMeter_1;
    QPushButton *btnMStart;
    QFrame *frame_PowerCheck;
    QHBoxLayout *layoutPower;
    QLabel *labelPowerTitle;
    QLabel *lblPower;
    QLabel *lblUnit;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QLineEdit *lineEdit_command;
    QPushButton *btnMSend;
    QWidget *tab_Function;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_37;
    QCheckBox *ckb_Fitting;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_38;
    QCheckBox *ckb_PD_value;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_10;
    QWidget *tab_Parameter;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_19;
    QLabel *lblLaser_model;
    QComboBox *cbLaser_model;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_17;
    QLabel *lblDAC_add;
    QLineEdit *lineDAC_add;
    QLabel *lblDAC_range;
    QLineEdit *lineDAC_range;
    QHBoxLayout *horizontalLayout_16;
    QLabel *lblLDfit_a;
    QLineEdit *lineLDfit_a;
    QLabel *lblLDfit_b;
    QLineEdit *lineLDfit_b;
    QHBoxLayout *horizontalLayout_13;
    QLabel *lblLaser_fit_a;
    QLineEdit *lineLaser_fit_a;
    QLabel *lblLaser_fit_b;
    QLineEdit *lineLaser_fit_b;
    QHBoxLayout *horizontalLayout_12;
    QLabel *lblFit_dvide;
    QLineEdit *lineFit_dvide;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *lblLow_tol;
    QLineEdit *lineLow_tol;
    QLabel *lblHigh_tol;
    QLineEdit *lineHigh_tol;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *btnParameter_enter;
    QPushButton *btnParameter_save;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *centralwidget_4;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *cbHexView;
    QTextEdit *teLog;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *leCmd;
    QPushButton *btnSendCmd;
    QWidget *page_Meter;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_35;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnMStart_2;
    QPushButton *btnMZero;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QComboBox *cbWaveLen;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *centralwidget_3;
    QVBoxLayout *verticalLayout_16;
    QLabel *lblStatusMeter_2;
    QHBoxLayout *frame_PowerCheck_2;
    QLabel *labelPowerTitle_2;
    QLabel *lblPower_2;
    QLabel *lblUnit_2;
    QHBoxLayout *layoutInterval_2;
    QLabel *labelInterval;
    QSpinBox *spnInterval;
    QSpacerItem *verticalSpacer_9;
    QWidget *page_Connect;
    QVBoxLayout *verticalLayout_10;
    QTabWidget *tabChange;
    QWidget *tabConnect;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_12;
    QTabWidget *tabConSwitch;
    QWidget *tabTcp;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_host;
    QLineEdit *leTcpHost;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_port;
    QSpinBox *sbTcpPort;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer;
    QWidget *tabSerial;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_portname;
    QComboBox *cbPort;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_baud;
    QComboBox *cbBaud;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_parity;
    QComboBox *cbParity;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_databits;
    QComboBox *cbDataBits;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_stopbits;
    QComboBox *cbStopBits;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_4;
    QLabel *labConStatus;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *btnLConnect;
    QLabel *lbStatus;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout_21;
    QGroupBox *gb_LASERPOINT;
    QVBoxLayout *verticalLayout_11;
    QLabel *lblStatusMeter_3;
    QLabel *labelDev;
    QHBoxLayout *horizontalLayout_24;
    QSpinBox *spn_LASERPOINT;
    QPushButton *btn_LASERPOINT;
    QFrame *frame_LASERPOINT;
    QGroupBox *gb_ThorlabMeter;
    QVBoxLayout *verticalLayout_18;
    QLabel *lb_ThorlabMeter;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_18;
    QComboBox *cbB_ThorlabMeter;
    QPushButton *btn_ThorlabMeter;
    QFrame *frame_ThorlabMet;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *lblSelect;
    QPushButton *btnPStart;
    QPushButton *btnPStop;
    QPushButton *btnPEStop;
    QLabel *lblStatusAuto;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuengineering;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1180, 720);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1180, 720));
        actSaveLog = new QAction(MainWindow);
        actSaveLog->setObjectName("actSaveLog");
        actSaveLog->setMenuRole(QAction::MenuRole::TextHeuristicRole);
        actClearLog = new QAction(MainWindow);
        actClearLog->setObjectName("actClearLog");
        actionSimulation = new QAction(MainWindow);
        actionSimulation->setObjectName("actionSimulation");
        actionSimulation->setMenuRole(QAction::MenuRole::NoRole);
        actionSetting = new QAction(MainWindow);
        actionSetting->setObjectName("actionSetting");
        actionEngineering = new QAction(MainWindow);
        actionEngineering->setObjectName("actionEngineering");
        actionworking = new QAction(MainWindow);
        actionworking->setObjectName("actionworking");
        actionSwitchPage = new QAction(MainWindow);
        actionSwitchPage->setObjectName("actionSwitchPage");
        actionSwitchPage->setMenuRole(QAction::MenuRole::NoRole);
        actionStress_Testing = new QAction(MainWindow);
        actionStress_Testing->setObjectName("actionStress_Testing");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout_11 = new QHBoxLayout(centralwidget);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        Page_Auto = new QWidget();
        Page_Auto->setObjectName("Page_Auto");
        verticalLayout_19 = new QVBoxLayout(Page_Auto);
        verticalLayout_19->setObjectName("verticalLayout_19");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lbl_model = new QLabel(Page_Auto);
        lbl_model->setObjectName("lbl_model");
        QFont font;
        font.setPointSize(18);
        lbl_model->setFont(font);

        horizontalLayout->addWidget(lbl_model);

        cb_model = new QComboBox(Page_Auto);
        cb_model->setObjectName("cb_model");
        QFont font1;
        font1.setPointSize(12);
        cb_model->setFont(font1);

        horizontalLayout->addWidget(cb_model);

        label_5 = new QLabel(Page_Auto);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        line_laser_number = new QLineEdit(Page_Auto);
        line_laser_number->setObjectName("line_laser_number");
        line_laser_number->setFont(font1);

        horizontalLayout->addWidget(line_laser_number);

        lbl_laser_number = new QLabel(Page_Auto);
        lbl_laser_number->setObjectName("lbl_laser_number");
        QFont font2;
        font2.setPointSize(15);
        lbl_laser_number->setFont(font2);
        lbl_laser_number->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lbl_laser_number);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        verticalLayout_19->addLayout(horizontalLayout);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName("horizontalLayout_34");
        horizontalLayout_34->setContentsMargins(10, 10, 10, 10);
        btnPInit = new QPushButton(Page_Auto);
        btnPInit->setObjectName("btnPInit");
        sizePolicy.setHeightForWidth(btnPInit->sizePolicy().hasHeightForWidth());
        btnPInit->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(20);
        btnPInit->setFont(font3);

        horizontalLayout_34->addWidget(btnPInit);

        frame_PowerCheck_3 = new QFrame(Page_Auto);
        frame_PowerCheck_3->setObjectName("frame_PowerCheck_3");
        horizontalLayout_33 = new QHBoxLayout(frame_PowerCheck_3);
        horizontalLayout_33->setObjectName("horizontalLayout_33");
        labelPowerTitle_3 = new QLabel(frame_PowerCheck_3);
        labelPowerTitle_3->setObjectName("labelPowerTitle_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelPowerTitle_3->sizePolicy().hasHeightForWidth());
        labelPowerTitle_3->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setPointSize(45);
        labelPowerTitle_3->setFont(font4);
        labelPowerTitle_3->setToolTipDuration(-1);
        labelPowerTitle_3->setTextFormat(Qt::TextFormat::AutoText);
        labelPowerTitle_3->setMargin(0);
        labelPowerTitle_3->setIndent(10);

        horizontalLayout_33->addWidget(labelPowerTitle_3);

        lblPower_3 = new QLabel(frame_PowerCheck_3);
        lblPower_3->setObjectName("lblPower_3");
        sizePolicy.setHeightForWidth(lblPower_3->sizePolicy().hasHeightForWidth());
        lblPower_3->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setPointSize(45);
        font5.setWeight(QFont::Medium);
        lblPower_3->setFont(font5);
        lblPower_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_33->addWidget(lblPower_3);

        lblUnit_3 = new QLabel(frame_PowerCheck_3);
        lblUnit_3->setObjectName("lblUnit_3");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblUnit_3->sizePolicy().hasHeightForWidth());
        lblUnit_3->setSizePolicy(sizePolicy2);
        lblUnit_3->setFont(font4);
        lblUnit_3->setMargin(10);
        lblUnit_3->setIndent(1);

        horizontalLayout_33->addWidget(lblUnit_3);


        horizontalLayout_34->addWidget(frame_PowerCheck_3);

        horizontalLayout_34->setStretch(0, 3);
        horizontalLayout_34->setStretch(1, 6);

        verticalLayout_19->addLayout(horizontalLayout_34);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(7);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, 10, 10, 10);
        btnPRC1 = new QPushButton(Page_Auto);
        btnPRC1->setObjectName("btnPRC1");
        sizePolicy.setHeightForWidth(btnPRC1->sizePolicy().hasHeightForWidth());
        btnPRC1->setSizePolicy(sizePolicy);
        btnPRC1->setFont(font3);

        horizontalLayout_3->addWidget(btnPRC1);

        btnPRC2 = new QPushButton(Page_Auto);
        btnPRC2->setObjectName("btnPRC2");
        sizePolicy.setHeightForWidth(btnPRC2->sizePolicy().hasHeightForWidth());
        btnPRC2->setSizePolicy(sizePolicy);
        btnPRC2->setFont(font3);

        horizontalLayout_3->addWidget(btnPRC2);

        btnPRC3 = new QPushButton(Page_Auto);
        btnPRC3->setObjectName("btnPRC3");
        sizePolicy.setHeightForWidth(btnPRC3->sizePolicy().hasHeightForWidth());
        btnPRC3->setSizePolicy(sizePolicy);
        btnPRC3->setFont(font3);

        horizontalLayout_3->addWidget(btnPRC3);

        horizontalLayout_3->setStretch(0, 5);
        horizontalLayout_3->setStretch(1, 5);
        horizontalLayout_3->setStretch(2, 5);

        verticalLayout_19->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(Page_Auto);
        Page_Laser = new QWidget();
        Page_Laser->setObjectName("Page_Laser");
        horizontalLayout_21 = new QHBoxLayout(Page_Laser);
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        tabWidget = new QTabWidget(Page_Laser);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setFont(font1);
        tabWidget->setIconSize(QSize(16, 16));
        tab_Controls = new QWidget();
        tab_Controls->setObjectName("tab_Controls");
        verticalLayout_9 = new QVBoxLayout(tab_Controls);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        btnDCD = new QPushButton(tab_Controls);
        btnDCD->setObjectName("btnDCD");

        horizontalLayout_7->addWidget(btnDCD);

        btnDOPD = new QPushButton(tab_Controls);
        btnDOPD->setObjectName("btnDOPD");

        horizontalLayout_7->addWidget(btnDOPD);

        btnPowerOn = new QPushButton(tab_Controls);
        btnPowerOn->setObjectName("btnPowerOn");

        horizontalLayout_7->addWidget(btnPowerOn);

        btnPowerOff = new QPushButton(tab_Controls);
        btnPowerOff->setObjectName("btnPowerOff");

        horizontalLayout_7->addWidget(btnPowerOff);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnDLE = new QPushButton(tab_Controls);
        btnDLE->setObjectName("btnDLE");

        horizontalLayout_2->addWidget(btnDLE);

        btnDEC = new QPushButton(tab_Controls);
        btnDEC->setObjectName("btnDEC");

        horizontalLayout_2->addWidget(btnDEC);

        btnDMOD = new QPushButton(tab_Controls);
        btnDMOD->setObjectName("btnDMOD");

        horizontalLayout_2->addWidget(btnDMOD);

        btnEMON = new QPushButton(tab_Controls);
        btnEMON->setObjectName("btnEMON");

        horizontalLayout_2->addWidget(btnEMON);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        btnABN = new QPushButton(tab_Controls);
        btnABN->setObjectName("btnABN");

        horizontalLayout_6->addWidget(btnABN);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_4 = new QLabel(tab_Controls);
        label_4->setObjectName("label_4");

        horizontalLayout_8->addWidget(label_4);

        cbPDx = new QComboBox(tab_Controls);
        cbPDx->setObjectName("cbPDx");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbPDx->sizePolicy().hasHeightForWidth());
        cbPDx->setSizePolicy(sizePolicy4);

        horizontalLayout_8->addWidget(cbPDx);

        spL_PD = new QSpinBox(tab_Controls);
        spL_PD->setObjectName("spL_PD");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(spL_PD->sizePolicy().hasHeightForWidth());
        spL_PD->setSizePolicy(sizePolicy5);

        horizontalLayout_8->addWidget(spL_PD);

        label_3 = new QLabel(tab_Controls);
        label_3->setObjectName("label_3");

        horizontalLayout_8->addWidget(label_3);

        dspDT = new QDoubleSpinBox(tab_Controls);
        dspDT->setObjectName("dspDT");
        sizePolicy4.setHeightForWidth(dspDT->sizePolicy().hasHeightForWidth());
        dspDT->setSizePolicy(sizePolicy4);
        dspDT->setMinimum(0.000000000000000);
        dspDT->setMaximum(5000.000000000000000);

        horizontalLayout_8->addWidget(dspDT);

        btnRPD = new QPushButton(tab_Controls);
        btnRPD->setObjectName("btnRPD");

        horizontalLayout_8->addWidget(btnRPD);


        verticalLayout_2->addLayout(horizontalLayout_8);


        verticalLayout_9->addLayout(verticalLayout_2);

        cb_SDCorSDAC = new QComboBox(tab_Controls);
        cb_SDCorSDAC->setObjectName("cb_SDCorSDAC");

        verticalLayout_9->addWidget(cb_SDCorSDAC);

        frame_SDAC1 = new QFrame(tab_Controls);
        frame_SDAC1->setObjectName("frame_SDAC1");
        horizontalLayout_20 = new QHBoxLayout(frame_SDAC1);
        horizontalLayout_20->setSpacing(15);
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        horizontalLayout_20->setContentsMargins(10, 10, 10, 10);
        cb_selectSDAC = new QComboBox(frame_SDAC1);
        cb_selectSDAC->setObjectName("cb_selectSDAC");

        horizontalLayout_20->addWidget(cb_selectSDAC);

        sL1 = new QSlider(frame_SDAC1);
        sL1->setObjectName("sL1");
        sL1->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_20->addWidget(sL1);

        spL1 = new QSpinBox(frame_SDAC1);
        spL1->setObjectName("spL1");

        horizontalLayout_20->addWidget(spL1);


        verticalLayout_9->addWidget(frame_SDAC1);

        centralwidget_2 = new QGroupBox(tab_Controls);
        centralwidget_2->setObjectName("centralwidget_2");
        sizePolicy3.setHeightForWidth(centralwidget_2->sizePolicy().hasHeightForWidth());
        centralwidget_2->setSizePolicy(sizePolicy3);
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(false);
        centralwidget_2->setFont(font6);
        verticalLayout_5 = new QVBoxLayout(centralwidget_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName("horizontalLayout_36");
        lblStatusMeter_1 = new QLabel(centralwidget_2);
        lblStatusMeter_1->setObjectName("lblStatusMeter_1");

        horizontalLayout_36->addWidget(lblStatusMeter_1);

        btnMStart = new QPushButton(centralwidget_2);
        btnMStart->setObjectName("btnMStart");
        btnMStart->setEnabled(false);

        horizontalLayout_36->addWidget(btnMStart);

        horizontalLayout_36->setStretch(0, 7);
        horizontalLayout_36->setStretch(1, 3);

        verticalLayout_5->addLayout(horizontalLayout_36);

        frame_PowerCheck = new QFrame(centralwidget_2);
        frame_PowerCheck->setObjectName("frame_PowerCheck");
        sizePolicy.setHeightForWidth(frame_PowerCheck->sizePolicy().hasHeightForWidth());
        frame_PowerCheck->setSizePolicy(sizePolicy);
        layoutPower = new QHBoxLayout(frame_PowerCheck);
        layoutPower->setSpacing(3);
        layoutPower->setObjectName("layoutPower");
        layoutPower->setContentsMargins(2, 2, 2, 2);
        labelPowerTitle = new QLabel(frame_PowerCheck);
        labelPowerTitle->setObjectName("labelPowerTitle");
        sizePolicy1.setHeightForWidth(labelPowerTitle->sizePolicy().hasHeightForWidth());
        labelPowerTitle->setSizePolicy(sizePolicy1);
        QFont font7;
        font7.setPointSize(22);
        font7.setBold(false);
        labelPowerTitle->setFont(font7);
        labelPowerTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelPowerTitle->setMargin(0);
        labelPowerTitle->setIndent(4);

        layoutPower->addWidget(labelPowerTitle);

        lblPower = new QLabel(frame_PowerCheck);
        lblPower->setObjectName("lblPower");
        sizePolicy.setHeightForWidth(lblPower->sizePolicy().hasHeightForWidth());
        lblPower->setSizePolicy(sizePolicy);
        QFont font8;
        font8.setPointSize(22);
        font8.setWeight(QFont::Medium);
        lblPower->setFont(font8);
        lblPower->setAlignment(Qt::AlignmentFlag::AlignCenter);

        layoutPower->addWidget(lblPower);

        lblUnit = new QLabel(frame_PowerCheck);
        lblUnit->setObjectName("lblUnit");
        sizePolicy2.setHeightForWidth(lblUnit->sizePolicy().hasHeightForWidth());
        lblUnit->setSizePolicy(sizePolicy2);
        lblUnit->setFont(font7);

        layoutPower->addWidget(lblUnit);

        layoutPower->setStretch(0, 4);
        layoutPower->setStretch(1, 5);
        layoutPower->setStretch(2, 2);

        verticalLayout_5->addWidget(frame_PowerCheck);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(10);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_2 = new QLabel(centralwidget_2);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_10->addWidget(label_2);

        lineEdit_command = new QLineEdit(centralwidget_2);
        lineEdit_command->setObjectName("lineEdit_command");
        sizePolicy.setHeightForWidth(lineEdit_command->sizePolicy().hasHeightForWidth());
        lineEdit_command->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(lineEdit_command);

        btnMSend = new QPushButton(centralwidget_2);
        btnMSend->setObjectName("btnMSend");

        horizontalLayout_10->addWidget(btnMSend);

        horizontalLayout_10->setStretch(1, 5);
        horizontalLayout_10->setStretch(2, 5);

        verticalLayout_5->addLayout(horizontalLayout_10);


        verticalLayout_9->addWidget(centralwidget_2);

        tabWidget->addTab(tab_Controls, QString());
        tab_Function = new QWidget();
        tab_Function->setObjectName("tab_Function");
        verticalLayout_17 = new QVBoxLayout(tab_Function);
        verticalLayout_17->setObjectName("verticalLayout_17");
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName("horizontalLayout_37");
        ckb_Fitting = new QCheckBox(tab_Function);
        ckb_Fitting->setObjectName("ckb_Fitting");

        horizontalLayout_37->addWidget(ckb_Fitting);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_37->addItem(horizontalSpacer_11);


        verticalLayout_17->addLayout(horizontalLayout_37);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName("horizontalLayout_38");
        ckb_PD_value = new QCheckBox(tab_Function);
        ckb_PD_value->setObjectName("ckb_PD_value");

        horizontalLayout_38->addWidget(ckb_PD_value);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_12);


        verticalLayout_17->addLayout(horizontalLayout_38);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_10);

        tabWidget->addTab(tab_Function, QString());
        tab_Parameter = new QWidget();
        tab_Parameter->setObjectName("tab_Parameter");
        verticalLayout_8 = new QVBoxLayout(tab_Parameter);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        lblLaser_model = new QLabel(tab_Parameter);
        lblLaser_model->setObjectName("lblLaser_model");
        lblLaser_model->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_19->addWidget(lblLaser_model);

        cbLaser_model = new QComboBox(tab_Parameter);
        cbLaser_model->setObjectName("cbLaser_model");

        horizontalLayout_19->addWidget(cbLaser_model);


        verticalLayout_8->addLayout(horizontalLayout_19);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        lblDAC_add = new QLabel(tab_Parameter);
        lblDAC_add->setObjectName("lblDAC_add");
        lblDAC_add->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblDAC_add->sizePolicy().hasHeightForWidth());
        lblDAC_add->setSizePolicy(sizePolicy1);
        lblDAC_add->setMinimumSize(QSize(100, 0));
        lblDAC_add->setBaseSize(QSize(0, 0));
        lblDAC_add->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_17->addWidget(lblDAC_add);

        lineDAC_add = new QLineEdit(tab_Parameter);
        lineDAC_add->setObjectName("lineDAC_add");

        horizontalLayout_17->addWidget(lineDAC_add);

        lblDAC_range = new QLabel(tab_Parameter);
        lblDAC_range->setObjectName("lblDAC_range");
        lblDAC_range->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblDAC_range->sizePolicy().hasHeightForWidth());
        lblDAC_range->setSizePolicy(sizePolicy1);
        lblDAC_range->setMinimumSize(QSize(100, 0));
        lblDAC_range->setBaseSize(QSize(0, 0));
        lblDAC_range->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_17->addWidget(lblDAC_range);

        lineDAC_range = new QLineEdit(tab_Parameter);
        lineDAC_range->setObjectName("lineDAC_range");

        horizontalLayout_17->addWidget(lineDAC_range);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        lblLDfit_a = new QLabel(tab_Parameter);
        lblLDfit_a->setObjectName("lblLDfit_a");
        lblLDfit_a->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblLDfit_a->sizePolicy().hasHeightForWidth());
        lblLDfit_a->setSizePolicy(sizePolicy1);
        lblLDfit_a->setMinimumSize(QSize(100, 0));
        lblLDfit_a->setBaseSize(QSize(0, 0));
        lblLDfit_a->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_16->addWidget(lblLDfit_a);

        lineLDfit_a = new QLineEdit(tab_Parameter);
        lineLDfit_a->setObjectName("lineLDfit_a");

        horizontalLayout_16->addWidget(lineLDfit_a);

        lblLDfit_b = new QLabel(tab_Parameter);
        lblLDfit_b->setObjectName("lblLDfit_b");
        lblLDfit_b->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblLDfit_b->sizePolicy().hasHeightForWidth());
        lblLDfit_b->setSizePolicy(sizePolicy1);
        lblLDfit_b->setMinimumSize(QSize(100, 0));
        lblLDfit_b->setBaseSize(QSize(0, 0));
        lblLDfit_b->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_16->addWidget(lblLDfit_b);

        lineLDfit_b = new QLineEdit(tab_Parameter);
        lineLDfit_b->setObjectName("lineLDfit_b");

        horizontalLayout_16->addWidget(lineLDfit_b);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        lblLaser_fit_a = new QLabel(tab_Parameter);
        lblLaser_fit_a->setObjectName("lblLaser_fit_a");
        lblLaser_fit_a->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblLaser_fit_a->sizePolicy().hasHeightForWidth());
        lblLaser_fit_a->setSizePolicy(sizePolicy1);
        lblLaser_fit_a->setMinimumSize(QSize(100, 0));
        lblLaser_fit_a->setBaseSize(QSize(0, 0));
        lblLaser_fit_a->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_13->addWidget(lblLaser_fit_a);

        lineLaser_fit_a = new QLineEdit(tab_Parameter);
        lineLaser_fit_a->setObjectName("lineLaser_fit_a");

        horizontalLayout_13->addWidget(lineLaser_fit_a);

        lblLaser_fit_b = new QLabel(tab_Parameter);
        lblLaser_fit_b->setObjectName("lblLaser_fit_b");
        lblLaser_fit_b->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblLaser_fit_b->sizePolicy().hasHeightForWidth());
        lblLaser_fit_b->setSizePolicy(sizePolicy1);
        lblLaser_fit_b->setMinimumSize(QSize(100, 0));
        lblLaser_fit_b->setBaseSize(QSize(0, 0));
        lblLaser_fit_b->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_13->addWidget(lblLaser_fit_b);

        lineLaser_fit_b = new QLineEdit(tab_Parameter);
        lineLaser_fit_b->setObjectName("lineLaser_fit_b");

        horizontalLayout_13->addWidget(lineLaser_fit_b);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        lblFit_dvide = new QLabel(tab_Parameter);
        lblFit_dvide->setObjectName("lblFit_dvide");
        sizePolicy1.setHeightForWidth(lblFit_dvide->sizePolicy().hasHeightForWidth());
        lblFit_dvide->setSizePolicy(sizePolicy1);
        lblFit_dvide->setMinimumSize(QSize(100, 0));
        lblFit_dvide->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(lblFit_dvide);

        lineFit_dvide = new QLineEdit(tab_Parameter);
        lineFit_dvide->setObjectName("lineFit_dvide");

        horizontalLayout_12->addWidget(lineFit_dvide);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        lblLow_tol = new QLabel(tab_Parameter);
        lblLow_tol->setObjectName("lblLow_tol");
        lblLow_tol->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblLow_tol->sizePolicy().hasHeightForWidth());
        lblLow_tol->setSizePolicy(sizePolicy1);
        lblLow_tol->setMinimumSize(QSize(100, 0));
        lblLow_tol->setBaseSize(QSize(0, 0));
        lblLow_tol->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_14->addWidget(lblLow_tol);

        lineLow_tol = new QLineEdit(tab_Parameter);
        lineLow_tol->setObjectName("lineLow_tol");

        horizontalLayout_14->addWidget(lineLow_tol);

        lblHigh_tol = new QLabel(tab_Parameter);
        lblHigh_tol->setObjectName("lblHigh_tol");
        lblHigh_tol->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblHigh_tol->sizePolicy().hasHeightForWidth());
        lblHigh_tol->setSizePolicy(sizePolicy1);
        lblHigh_tol->setMinimumSize(QSize(100, 0));
        lblHigh_tol->setBaseSize(QSize(0, 0));
        lblHigh_tol->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_14->addWidget(lblHigh_tol);

        lineHigh_tol = new QLineEdit(tab_Parameter);
        lineHigh_tol->setObjectName("lineHigh_tol");

        horizontalLayout_14->addWidget(lineHigh_tol);


        verticalLayout->addLayout(horizontalLayout_14);


        verticalLayout_8->addLayout(verticalLayout);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_6);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        btnParameter_enter = new QPushButton(tab_Parameter);
        btnParameter_enter->setObjectName("btnParameter_enter");

        horizontalLayout_15->addWidget(btnParameter_enter);

        btnParameter_save = new QPushButton(tab_Parameter);
        btnParameter_save->setObjectName("btnParameter_save");

        horizontalLayout_15->addWidget(btnParameter_save);


        verticalLayout_8->addLayout(horizontalLayout_15);

        verticalLayout_8->setStretch(0, 1);
        verticalLayout_8->setStretch(1, 5);
        verticalLayout_8->setStretch(3, 1);
        tabWidget->addTab(tab_Parameter, QString());

        horizontalLayout_21->addWidget(tabWidget);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        centralwidget_4 = new QGroupBox(Page_Laser);
        centralwidget_4->setObjectName("centralwidget_4");
        sizePolicy.setHeightForWidth(centralwidget_4->sizePolicy().hasHeightForWidth());
        centralwidget_4->setSizePolicy(sizePolicy);
        centralwidget_4->setFont(font6);
        verticalLayout_6 = new QVBoxLayout(centralwidget_4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        cbHexView = new QCheckBox(centralwidget_4);
        cbHexView->setObjectName("cbHexView");
        QFont font9;
        font9.setPointSize(10);
        font9.setBold(false);
        cbHexView->setFont(font9);
        cbHexView->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        verticalLayout_6->addWidget(cbHexView);

        teLog = new QTextEdit(centralwidget_4);
        teLog->setObjectName("teLog");
        teLog->setTabChangesFocus(false);
        teLog->setReadOnly(true);

        verticalLayout_6->addWidget(teLog);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_9 = new QLabel(centralwidget_4);
        label_9->setObjectName("label_9");

        horizontalLayout_4->addWidget(label_9);

        leCmd = new QLineEdit(centralwidget_4);
        leCmd->setObjectName("leCmd");

        horizontalLayout_4->addWidget(leCmd);

        btnSendCmd = new QPushButton(centralwidget_4);
        btnSendCmd->setObjectName("btnSendCmd");

        horizontalLayout_4->addWidget(btnSendCmd);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_7->addWidget(centralwidget_4);


        horizontalLayout_21->addLayout(verticalLayout_7);

        stackedWidget->addWidget(Page_Laser);
        page_Meter = new QWidget();
        page_Meter->setObjectName("page_Meter");
        verticalLayout_20 = new QVBoxLayout(page_Meter);
        verticalLayout_20->setObjectName("verticalLayout_20");
        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName("horizontalLayout_35");
        groupBox = new QGroupBox(page_Meter);
        groupBox->setObjectName("groupBox");
        groupBox->setFont(font1);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btnMStart_2 = new QPushButton(groupBox);
        btnMStart_2->setObjectName("btnMStart_2");
        btnMStart_2->setEnabled(false);

        horizontalLayout_5->addWidget(btnMStart_2);

        btnMZero = new QPushButton(groupBox);
        btnMZero->setObjectName("btnMZero");

        horizontalLayout_5->addWidget(btnMZero);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 74, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout_9->addWidget(label);

        cbWaveLen = new QComboBox(groupBox);
        cbWaveLen->setObjectName("cbWaveLen");

        horizontalLayout_9->addWidget(cbWaveLen);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer_3 = new QSpacerItem(20, 73, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_35->addWidget(groupBox);

        centralwidget_3 = new QGroupBox(page_Meter);
        centralwidget_3->setObjectName("centralwidget_3");
        centralwidget_3->setFont(font1);
        verticalLayout_16 = new QVBoxLayout(centralwidget_3);
        verticalLayout_16->setObjectName("verticalLayout_16");
        lblStatusMeter_2 = new QLabel(centralwidget_3);
        lblStatusMeter_2->setObjectName("lblStatusMeter_2");
        QFont font10;
        font10.setPointSize(10);
        lblStatusMeter_2->setFont(font10);

        verticalLayout_16->addWidget(lblStatusMeter_2);

        frame_PowerCheck_2 = new QHBoxLayout();
        frame_PowerCheck_2->setSpacing(10);
        frame_PowerCheck_2->setObjectName("frame_PowerCheck_2");
        labelPowerTitle_2 = new QLabel(centralwidget_3);
        labelPowerTitle_2->setObjectName("labelPowerTitle_2");
        sizePolicy1.setHeightForWidth(labelPowerTitle_2->sizePolicy().hasHeightForWidth());
        labelPowerTitle_2->setSizePolicy(sizePolicy1);
        QFont font11;
        font11.setPointSize(33);
        labelPowerTitle_2->setFont(font11);

        frame_PowerCheck_2->addWidget(labelPowerTitle_2);

        lblPower_2 = new QLabel(centralwidget_3);
        lblPower_2->setObjectName("lblPower_2");
        sizePolicy.setHeightForWidth(lblPower_2->sizePolicy().hasHeightForWidth());
        lblPower_2->setSizePolicy(sizePolicy);
        QFont font12;
        font12.setPointSize(36);
        font12.setWeight(QFont::Medium);
        lblPower_2->setFont(font12);
        lblPower_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        frame_PowerCheck_2->addWidget(lblPower_2);

        lblUnit_2 = new QLabel(centralwidget_3);
        lblUnit_2->setObjectName("lblUnit_2");
        sizePolicy2.setHeightForWidth(lblUnit_2->sizePolicy().hasHeightForWidth());
        lblUnit_2->setSizePolicy(sizePolicy2);
        lblUnit_2->setFont(font11);

        frame_PowerCheck_2->addWidget(lblUnit_2);


        verticalLayout_16->addLayout(frame_PowerCheck_2);

        layoutInterval_2 = new QHBoxLayout();
        layoutInterval_2->setObjectName("layoutInterval_2");
        labelInterval = new QLabel(centralwidget_3);
        labelInterval->setObjectName("labelInterval");
        labelInterval->setFont(font10);

        layoutInterval_2->addWidget(labelInterval);

        spnInterval = new QSpinBox(centralwidget_3);
        spnInterval->setObjectName("spnInterval");
        spnInterval->setFont(font10);
        spnInterval->setMinimum(50);
        spnInterval->setMaximum(10000);
        spnInterval->setSingleStep(50);
        spnInterval->setValue(200);

        layoutInterval_2->addWidget(spnInterval);


        verticalLayout_16->addLayout(layoutInterval_2);


        horizontalLayout_35->addWidget(centralwidget_3);

        horizontalLayout_35->setStretch(0, 5);
        horizontalLayout_35->setStretch(1, 5);

        verticalLayout_20->addLayout(horizontalLayout_35);

        verticalSpacer_9 = new QSpacerItem(20, 292, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_20->addItem(verticalSpacer_9);

        stackedWidget->addWidget(page_Meter);
        page_Connect = new QWidget();
        page_Connect->setObjectName("page_Connect");
        verticalLayout_10 = new QVBoxLayout(page_Connect);
        verticalLayout_10->setObjectName("verticalLayout_10");
        tabChange = new QTabWidget(page_Connect);
        tabChange->setObjectName("tabChange");
        sizePolicy.setHeightForWidth(tabChange->sizePolicy().hasHeightForWidth());
        tabChange->setSizePolicy(sizePolicy);
        tabChange->setMinimumSize(QSize(0, 0));
        tabConnect = new QWidget();
        tabConnect->setObjectName("tabConnect");
        horizontalLayout_22 = new QHBoxLayout(tabConnect);
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        tabConSwitch = new QTabWidget(tabConnect);
        tabConSwitch->setObjectName("tabConSwitch");
        tabConSwitch->setFont(font1);
        tabTcp = new QWidget();
        tabTcp->setObjectName("tabTcp");
        verticalLayout_13 = new QVBoxLayout(tabTcp);
        verticalLayout_13->setObjectName("verticalLayout_13");
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        label_host = new QLabel(tabTcp);
        label_host->setObjectName("label_host");

        horizontalLayout_25->addWidget(label_host);

        leTcpHost = new QLineEdit(tabTcp);
        leTcpHost->setObjectName("leTcpHost");

        horizontalLayout_25->addWidget(leTcpHost);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_8);

        horizontalLayout_25->setStretch(0, 1);
        horizontalLayout_25->setStretch(1, 4);
        horizontalLayout_25->setStretch(2, 1);

        verticalLayout_13->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        label_port = new QLabel(tabTcp);
        label_port->setObjectName("label_port");

        horizontalLayout_26->addWidget(label_port);

        sbTcpPort = new QSpinBox(tabTcp);
        sbTcpPort->setObjectName("sbTcpPort");

        horizontalLayout_26->addWidget(sbTcpPort);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_9);

        horizontalLayout_26->setStretch(0, 1);
        horizontalLayout_26->setStretch(1, 4);
        horizontalLayout_26->setStretch(2, 1);

        verticalLayout_13->addLayout(horizontalLayout_26);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_13->addItem(verticalSpacer);

        tabConSwitch->addTab(tabTcp, QString());
        tabSerial = new QWidget();
        tabSerial->setObjectName("tabSerial");
        verticalLayout_14 = new QVBoxLayout(tabSerial);
        verticalLayout_14->setObjectName("verticalLayout_14");
        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        label_portname = new QLabel(tabSerial);
        label_portname->setObjectName("label_portname");

        horizontalLayout_27->addWidget(label_portname);

        cbPort = new QComboBox(tabSerial);
        cbPort->setObjectName("cbPort");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(cbPort->sizePolicy().hasHeightForWidth());
        cbPort->setSizePolicy(sizePolicy6);

        horizontalLayout_27->addWidget(cbPort);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_3);

        horizontalLayout_27->setStretch(0, 2);
        horizontalLayout_27->setStretch(1, 6);
        horizontalLayout_27->setStretch(2, 1);

        verticalLayout_14->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        label_baud = new QLabel(tabSerial);
        label_baud->setObjectName("label_baud");

        horizontalLayout_28->addWidget(label_baud);

        cbBaud = new QComboBox(tabSerial);
        cbBaud->setObjectName("cbBaud");
        sizePolicy6.setHeightForWidth(cbBaud->sizePolicy().hasHeightForWidth());
        cbBaud->setSizePolicy(sizePolicy6);

        horizontalLayout_28->addWidget(cbBaud);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_4);

        horizontalLayout_28->setStretch(0, 2);
        horizontalLayout_28->setStretch(1, 6);
        horizontalLayout_28->setStretch(2, 1);

        verticalLayout_14->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        label_parity = new QLabel(tabSerial);
        label_parity->setObjectName("label_parity");

        horizontalLayout_29->addWidget(label_parity);

        cbParity = new QComboBox(tabSerial);
        cbParity->setObjectName("cbParity");
        sizePolicy6.setHeightForWidth(cbParity->sizePolicy().hasHeightForWidth());
        cbParity->setSizePolicy(sizePolicy6);

        horizontalLayout_29->addWidget(cbParity);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_5);

        horizontalLayout_29->setStretch(0, 2);
        horizontalLayout_29->setStretch(1, 6);
        horizontalLayout_29->setStretch(2, 1);

        verticalLayout_14->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        label_databits = new QLabel(tabSerial);
        label_databits->setObjectName("label_databits");

        horizontalLayout_30->addWidget(label_databits);

        cbDataBits = new QComboBox(tabSerial);
        cbDataBits->setObjectName("cbDataBits");
        sizePolicy6.setHeightForWidth(cbDataBits->sizePolicy().hasHeightForWidth());
        cbDataBits->setSizePolicy(sizePolicy6);

        horizontalLayout_30->addWidget(cbDataBits);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_6);

        horizontalLayout_30->setStretch(0, 2);
        horizontalLayout_30->setStretch(1, 6);
        horizontalLayout_30->setStretch(2, 1);

        verticalLayout_14->addLayout(horizontalLayout_30);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName("horizontalLayout_31");
        label_stopbits = new QLabel(tabSerial);
        label_stopbits->setObjectName("label_stopbits");

        horizontalLayout_31->addWidget(label_stopbits);

        cbStopBits = new QComboBox(tabSerial);
        cbStopBits->setObjectName("cbStopBits");
        sizePolicy6.setHeightForWidth(cbStopBits->sizePolicy().hasHeightForWidth());
        cbStopBits->setSizePolicy(sizePolicy6);

        horizontalLayout_31->addWidget(cbStopBits);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_7);

        horizontalLayout_31->setStretch(0, 2);
        horizontalLayout_31->setStretch(1, 6);
        horizontalLayout_31->setStretch(2, 1);

        verticalLayout_14->addLayout(horizontalLayout_31);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_4);

        tabConSwitch->addTab(tabSerial, QString());

        verticalLayout_12->addWidget(tabConSwitch);

        labConStatus = new QLabel(tabConnect);
        labConStatus->setObjectName("labConStatus");

        verticalLayout_12->addWidget(labConStatus);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        btnLConnect = new QPushButton(tabConnect);
        btnLConnect->setObjectName("btnLConnect");

        horizontalLayout_23->addWidget(btnLConnect);

        lbStatus = new QLabel(tabConnect);
        lbStatus->setObjectName("lbStatus");

        horizontalLayout_23->addWidget(lbStatus);


        verticalLayout_12->addLayout(horizontalLayout_23);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_7);

        verticalLayout_12->setStretch(0, 6);
        verticalLayout_12->setStretch(2, 1);
        verticalLayout_12->setStretch(3, 1);

        horizontalLayout_22->addLayout(verticalLayout_12);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName("verticalLayout_21");
        gb_LASERPOINT = new QGroupBox(tabConnect);
        gb_LASERPOINT->setObjectName("gb_LASERPOINT");
        gb_LASERPOINT->setFont(font1);
        verticalLayout_11 = new QVBoxLayout(gb_LASERPOINT);
        verticalLayout_11->setObjectName("verticalLayout_11");
        lblStatusMeter_3 = new QLabel(gb_LASERPOINT);
        lblStatusMeter_3->setObjectName("lblStatusMeter_3");
        lblStatusMeter_3->setFont(font10);

        verticalLayout_11->addWidget(lblStatusMeter_3);

        labelDev = new QLabel(gb_LASERPOINT);
        labelDev->setObjectName("labelDev");
        labelDev->setFont(font10);

        verticalLayout_11->addWidget(labelDev);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        spn_LASERPOINT = new QSpinBox(gb_LASERPOINT);
        spn_LASERPOINT->setObjectName("spn_LASERPOINT");
        spn_LASERPOINT->setFont(font10);
        spn_LASERPOINT->setMinimum(0);
        spn_LASERPOINT->setMaximum(31);
        spn_LASERPOINT->setValue(0);

        horizontalLayout_24->addWidget(spn_LASERPOINT);

        btn_LASERPOINT = new QPushButton(gb_LASERPOINT);
        btn_LASERPOINT->setObjectName("btn_LASERPOINT");
        btn_LASERPOINT->setFont(font10);

        horizontalLayout_24->addWidget(btn_LASERPOINT);


        verticalLayout_11->addLayout(horizontalLayout_24);

        frame_LASERPOINT = new QFrame(gb_LASERPOINT);
        frame_LASERPOINT->setObjectName("frame_LASERPOINT");
        frame_LASERPOINT->setFrameShape(QFrame::Shape::StyledPanel);
        frame_LASERPOINT->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_11->addWidget(frame_LASERPOINT);

        verticalLayout_11->setStretch(0, 1);
        verticalLayout_11->setStretch(1, 1);
        verticalLayout_11->setStretch(2, 2);
        verticalLayout_11->setStretch(3, 3);

        verticalLayout_21->addWidget(gb_LASERPOINT);

        gb_ThorlabMeter = new QGroupBox(tabConnect);
        gb_ThorlabMeter->setObjectName("gb_ThorlabMeter");
        gb_ThorlabMeter->setFont(font1);
        verticalLayout_18 = new QVBoxLayout(gb_ThorlabMeter);
        verticalLayout_18->setObjectName("verticalLayout_18");
        lb_ThorlabMeter = new QLabel(gb_ThorlabMeter);
        lb_ThorlabMeter->setObjectName("lb_ThorlabMeter");
        lb_ThorlabMeter->setFont(font10);

        verticalLayout_18->addWidget(lb_ThorlabMeter);

        label_6 = new QLabel(gb_ThorlabMeter);
        label_6->setObjectName("label_6");
        label_6->setFont(font10);

        verticalLayout_18->addWidget(label_6);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        cbB_ThorlabMeter = new QComboBox(gb_ThorlabMeter);
        cbB_ThorlabMeter->setObjectName("cbB_ThorlabMeter");
        cbB_ThorlabMeter->setFont(font10);

        horizontalLayout_18->addWidget(cbB_ThorlabMeter);

        btn_ThorlabMeter = new QPushButton(gb_ThorlabMeter);
        btn_ThorlabMeter->setObjectName("btn_ThorlabMeter");
        btn_ThorlabMeter->setFont(font10);

        horizontalLayout_18->addWidget(btn_ThorlabMeter);

        horizontalLayout_18->setStretch(0, 7);
        horizontalLayout_18->setStretch(1, 3);

        verticalLayout_18->addLayout(horizontalLayout_18);

        frame_ThorlabMet = new QFrame(gb_ThorlabMeter);
        frame_ThorlabMet->setObjectName("frame_ThorlabMet");
        frame_ThorlabMet->setFrameShape(QFrame::Shape::StyledPanel);
        frame_ThorlabMet->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_18->addWidget(frame_ThorlabMet);

        verticalLayout_18->setStretch(0, 1);
        verticalLayout_18->setStretch(1, 1);
        verticalLayout_18->setStretch(2, 2);
        verticalLayout_18->setStretch(3, 3);

        verticalLayout_21->addWidget(gb_ThorlabMeter);

        verticalLayout_21->setStretch(0, 5);
        verticalLayout_21->setStretch(1, 5);

        horizontalLayout_22->addLayout(verticalLayout_21);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_10);

        tabChange->addTab(tabConnect, QString());

        verticalLayout_10->addWidget(tabChange);

        stackedWidget->addWidget(page_Connect);

        horizontalLayout_11->addWidget(stackedWidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        QFont font13;
        font13.setPointSize(19);
        font13.setBold(true);
        font13.setUnderline(true);
        label_8->setFont(font13);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_8);

        lblSelect = new QLabel(centralwidget);
        lblSelect->setObjectName("lblSelect");
        QFont font14;
        font14.setPointSize(16);
        font14.setItalic(false);
        font14.setUnderline(false);
        lblSelect->setFont(font14);
        lblSelect->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(lblSelect);

        btnPStart = new QPushButton(centralwidget);
        btnPStart->setObjectName("btnPStart");
        sizePolicy.setHeightForWidth(btnPStart->sizePolicy().hasHeightForWidth());
        btnPStart->setSizePolicy(sizePolicy);
        btnPStart->setMinimumSize(QSize(0, 29));
        QFont font15;
        font15.setBold(false);
        btnPStart->setFont(font15);
        btnPStart->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(btnPStart);

        btnPStop = new QPushButton(centralwidget);
        btnPStop->setObjectName("btnPStop");
        sizePolicy.setHeightForWidth(btnPStop->sizePolicy().hasHeightForWidth());
        btnPStop->setSizePolicy(sizePolicy);
        btnPStop->setMinimumSize(QSize(0, 29));
        btnPStop->setFont(font15);
        btnPStop->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(btnPStop);

        btnPEStop = new QPushButton(centralwidget);
        btnPEStop->setObjectName("btnPEStop");
        sizePolicy.setHeightForWidth(btnPEStop->sizePolicy().hasHeightForWidth());
        btnPEStop->setSizePolicy(sizePolicy);
        btnPEStop->setMinimumSize(QSize(0, 29));
        QFont font16;
        font16.setBold(true);
        btnPEStop->setFont(font16);
        btnPEStop->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(btnPEStop);

        lblStatusAuto = new QLabel(centralwidget);
        lblStatusAuto->setObjectName("lblStatusAuto");
        QFont font17;
        font17.setPointSize(13);
        lblStatusAuto->setFont(font17);
        lblStatusAuto->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_4->addWidget(lblStatusAuto);


        horizontalLayout_11->addLayout(verticalLayout_4);

        horizontalLayout_11->setStretch(0, 6);
        horizontalLayout_11->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1180, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName("menuMenu");
        menuengineering = new QMenu(menuBar);
        menuengineering->setObjectName("menuengineering");
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionSwitchPage);
        toolBar->addAction(actSaveLog);
        toolBar->addAction(actClearLog);
        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuengineering->menuAction());
        menuMenu->addAction(actionSetting);
        menuMenu->addSeparator();
        menuMenu->addAction(actionSimulation);
        menuMenu->addAction(actionStress_Testing);
        menuengineering->addAction(actionworking);
        menuengineering->addAction(actionEngineering);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        tabWidget->setCurrentIndex(0);
        tabChange->setCurrentIndex(0);
        tabConSwitch->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LaserGUI (Qt Designer)", nullptr));
        actSaveLog->setText(QCoreApplication::translate("MainWindow", "Save Log...", nullptr));
        actClearLog->setText(QCoreApplication::translate("MainWindow", "Clear Log", nullptr));
        actionSimulation->setText(QCoreApplication::translate("MainWindow", "Simulation", nullptr));
        actionSetting->setText(QCoreApplication::translate("MainWindow", "Setting", nullptr));
        actionEngineering->setText(QCoreApplication::translate("MainWindow", "Engineering", nullptr));
        actionworking->setText(QCoreApplication::translate("MainWindow", "Working", nullptr));
        actionSwitchPage->setText(QCoreApplication::translate("MainWindow", "Switch Page", nullptr));
#if QT_CONFIG(shortcut)
        actionSwitchPage->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Tab", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStress_Testing->setText(QCoreApplication::translate("MainWindow", "Stress Testing", nullptr));
        lbl_model->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        lbl_laser_number->setText(QCoreApplication::translate("MainWindow", "Laser_Number", nullptr));
        btnPInit->setText(QCoreApplication::translate("MainWindow", "Initialization", nullptr));
        labelPowerTitle_3->setText(QCoreApplication::translate("MainWindow", "\345\212\237\347\216\207\357\274\232", nullptr));
        lblPower_3->setText(QCoreApplication::translate("MainWindow", "--.-", nullptr));
        lblUnit_3->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        btnPRC1->setText(QCoreApplication::translate("MainWindow", "LD-Test", nullptr));
        btnPRC2->setText(QCoreApplication::translate("MainWindow", "Laser-Test", nullptr));
        btnPRC3->setText(QCoreApplication::translate("MainWindow", "PD Test", nullptr));
        btnDCD->setText(QCoreApplication::translate("MainWindow", "DCD", nullptr));
        btnDOPD->setText(QCoreApplication::translate("MainWindow", "DOPD", nullptr));
        btnPowerOn->setText(QCoreApplication::translate("MainWindow", "Power ON", nullptr));
        btnPowerOff->setText(QCoreApplication::translate("MainWindow", "Power OFF", nullptr));
        btnDLE->setText(QCoreApplication::translate("MainWindow", "DLE", nullptr));
        btnDEC->setText(QCoreApplication::translate("MainWindow", "DEC", nullptr));
        btnDMOD->setText(QCoreApplication::translate("MainWindow", "DMOD", nullptr));
        btnEMON->setText(QCoreApplication::translate("MainWindow", "EMON", nullptr));
        btnABN->setText(QCoreApplication::translate("MainWindow", "ABN", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Protection\n"
"Device Test", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Limit\n"
"Time", nullptr));
        btnRPD->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        centralwidget_2->setTitle(QCoreApplication::translate("MainWindow", "Meter", nullptr));
        lblStatusMeter_1->setText(QCoreApplication::translate("MainWindow", "\347\213\200\346\205\213\357\274\232\346\234\252\351\200\243\347\267\232", nullptr));
        btnMStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        labelPowerTitle->setText(QCoreApplication::translate("MainWindow", "\345\212\237\347\216\207\357\274\232", nullptr));
        lblPower->setText(QCoreApplication::translate("MainWindow", "--.-", nullptr));
        lblUnit->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Inst", nullptr));
        btnMSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Controls), QCoreApplication::translate("MainWindow", "Laser Controls", nullptr));
        ckb_Fitting->setText(QCoreApplication::translate("MainWindow", "Measured Check", nullptr));
        ckb_PD_value->setText(QCoreApplication::translate("MainWindow", "PD_value Check", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Function), QCoreApplication::translate("MainWindow", "Laser Function", nullptr));
        lblLaser_model->setText(QCoreApplication::translate("MainWindow", "Laser Model", nullptr));
        lblDAC_add->setText(QCoreApplication::translate("MainWindow", "DAC_add", nullptr));
        lblDAC_range->setText(QCoreApplication::translate("MainWindow", "DAC_range", nullptr));
        lblLDfit_a->setText(QCoreApplication::translate("MainWindow", "LD_fit_a", nullptr));
        lblLDfit_b->setText(QCoreApplication::translate("MainWindow", "LD_fit_b", nullptr));
        lblLaser_fit_a->setText(QCoreApplication::translate("MainWindow", "Laser_fit_a", nullptr));
        lblLaser_fit_b->setText(QCoreApplication::translate("MainWindow", "Laser_fit_b", nullptr));
        lblFit_dvide->setText(QCoreApplication::translate("MainWindow", "Fit_divide", nullptr));
        lblLow_tol->setText(QCoreApplication::translate("MainWindow", "Low_tol", nullptr));
        lblHigh_tol->setText(QCoreApplication::translate("MainWindow", "High_tol", nullptr));
        btnParameter_enter->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        btnParameter_save->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Parameter), QCoreApplication::translate("MainWindow", "Laser Parameter", nullptr));
        centralwidget_4->setTitle(QCoreApplication::translate("MainWindow", "Log Infomation", nullptr));
        cbHexView->setText(QCoreApplication::translate("MainWindow", "Hex view (RX)", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Command", nullptr));
        leCmd->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type command, e.g. help", nullptr));
        btnSendCmd->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Setting", nullptr));
        btnMStart_2->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnMZero->setText(QCoreApplication::translate("MainWindow", "ZERO", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Wavelength:", nullptr));
        centralwidget_3->setTitle(QCoreApplication::translate("MainWindow", "Meter", nullptr));
        lblStatusMeter_2->setText(QCoreApplication::translate("MainWindow", "\347\213\200\346\205\213\357\274\232\346\234\252\351\200\243\347\267\232", nullptr));
        labelPowerTitle_2->setText(QCoreApplication::translate("MainWindow", "\345\212\237\347\216\207\357\274\232", nullptr));
        lblPower_2->setText(QCoreApplication::translate("MainWindow", "--.-", nullptr));
        lblUnit_2->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        labelInterval->setText(QCoreApplication::translate("MainWindow", "\351\207\217\346\270\254\351\226\223\351\232\224 (ms)\357\274\232", nullptr));
        label_host->setText(QCoreApplication::translate("MainWindow", "Host", nullptr));
        label_port->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        tabConSwitch->setTabText(tabConSwitch->indexOf(tabTcp), QCoreApplication::translate("MainWindow", "TCP", nullptr));
        label_portname->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        label_baud->setText(QCoreApplication::translate("MainWindow", "Baud", nullptr));
        label_parity->setText(QCoreApplication::translate("MainWindow", "Parity", nullptr));
        label_databits->setText(QCoreApplication::translate("MainWindow", "Data bits", nullptr));
        label_stopbits->setText(QCoreApplication::translate("MainWindow", "Stop bits", nullptr));
        tabConSwitch->setTabText(tabConSwitch->indexOf(tabSerial), QCoreApplication::translate("MainWindow", "Serial", nullptr));
        labConStatus->setText(QCoreApplication::translate("MainWindow", "Not connect", nullptr));
        btnLConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        lbStatus->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        gb_LASERPOINT->setTitle(QCoreApplication::translate("MainWindow", "LASERPOINT Meter", nullptr));
        lblStatusMeter_3->setText(QCoreApplication::translate("MainWindow", "\347\213\200\346\205\213\357\274\232\346\234\252\351\200\243\347\267\232", nullptr));
        labelDev->setText(QCoreApplication::translate("MainWindow", "Device Index\357\274\232", nullptr));
        btn_LASERPOINT->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        gb_ThorlabMeter->setTitle(QCoreApplication::translate("MainWindow", "THORLAB Meter", nullptr));
        lb_ThorlabMeter->setText(QCoreApplication::translate("MainWindow", "\347\213\200\346\205\213\357\274\232\346\234\252\351\200\243\347\267\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Device Name:", nullptr));
        btn_ThorlabMeter->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        tabChange->setTabText(tabChange->indexOf(tabConnect), QCoreApplication::translate("MainWindow", "CONNECT", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Process", nullptr));
        lblSelect->setText(QCoreApplication::translate("MainWindow", "Not select", nullptr));
        btnPStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnPStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        btnPEStop->setText(QCoreApplication::translate("MainWindow", "Emergency\n"
"Stop", nullptr));
        lblStatusAuto->setText(QCoreApplication::translate("MainWindow", "\347\213\200\346\205\213\357\274\232\347\204\241\347\250\213\345\272\217", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuengineering->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
