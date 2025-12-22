#include "Simulation.h"
#include "src/Gui/ui_Simulation.h"

Simulation::Simulation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Simulation)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);   // 或 Qt::Dialog
    setWindowTitle("Simulation");

    ui->cb_connect->addItem("TCP");
    ui->cb_connect->addItem("Serial");
    ui->btn_disconnect->setEnabled(false);

    connect(ui->btn_connect, &QPushButton::clicked, this, [this]() {
        if(isConnected == true) return;
        isConnected = true;
        if (ui->cb_connect->currentText() == "TCP") emit setConnect("TCP");
        else emit setConnect("Serial");
        ui->btn_disconnect->setEnabled(true);
        ui->btn_connect->setEnabled(false);
    });
    connect(ui->btn_disconnect, &QPushButton::clicked, this, [this]() {
        if(isConnected == false) return;
        isConnected = false;
        emit setConnect("disable");
        ui->btn_connect->setEnabled(true);
        ui->btn_disconnect->setEnabled(false);
    });

    ui->ckb_QBH_off->setCheckState(Qt::Checked);
    ui->ckb_Channel_off->setCheckState(Qt::Checked);
    ui->ckb_MainPower_off->setCheckState(Qt::Checked);
    ui->ckb_LaserEnable_off->setCheckState(Qt::Checked);

    connect(ui->ckb_Channel_on, &QCheckBox::checkStateChanged, this, [this]() {
        if(ui->ckb_Channel_on->isChecked() ) {
            ui->ckb_Channel_off->setCheckState(Qt::Unchecked);
            emit ledStateChange(1, true);
        }else {ui->ckb_Channel_off->setCheckState(Qt::Checked); emit ledStateChange(1, false);}
    });
    connect(ui->ckb_Channel_off, &QCheckBox::checkStateChanged, this, [this]() {
        if(ui->ckb_Channel_off->isChecked() ) {
            ui->ckb_Channel_on->setCheckState(Qt::Unchecked);
            emit ledStateChange(1, false);
        }else {ui->ckb_Channel_on->setCheckState(Qt::Checked); emit ledStateChange(1, true);}
    });

    connect(ui->ckb_QBH_on, &QCheckBox::checkStateChanged, this, [this]() {
        if(ui->ckb_QBH_on->isChecked() ) {
            ui->ckb_QBH_off->setCheckState(Qt::Unchecked);
            emit ledStateChange(2, true);
        }else {ui->ckb_QBH_off->setCheckState(Qt::Checked); emit ledStateChange(2, false);}
    });
    connect(ui->ckb_QBH_off, &QCheckBox::checkStateChanged, this, [this]() {
        if(ui->ckb_QBH_off->isChecked() ) {
            ui->ckb_QBH_on->setCheckState(Qt::Unchecked);
            emit ledStateChange(2, false);
        }else {ui->ckb_QBH_on->setCheckState(Qt::Checked); emit ledStateChange(2, true);}
    });


    connect(ui->ckb_MainPower_on, &QCheckBox::checkStateChanged, this, [this,parent]() {
        if(ui->ckb_MainPower_on->isChecked() ) {
            ui->ckb_MainPower_off->setCheckState(Qt::Unchecked);
            qDebug() << "發出訊號on";
            emit ledStateChange(3, true);
        }else {ui->ckb_MainPower_off->setCheckState(Qt::Checked); emit ledStateChange(3, false); qDebug() << "發出訊號off";}

    });
    connect(ui->ckb_MainPower_off, &QCheckBox::checkStateChanged, this, [this]() {
        if(ui->ckb_MainPower_off->isChecked() ) {
            ui->ckb_MainPower_on->setCheckState(Qt::Unchecked);
            emit ledStateChange(3, false);
        } else {ui->ckb_MainPower_on->setCheckState(Qt::Checked); emit ledStateChange(3, true);}
    });

    connect(ui->ckb_LaserEnable_on, &QCheckBox::checkStateChanged, this, [this]() {
        if(ui->ckb_LaserEnable_on->isChecked() ) {
            ui->ckb_LaserEnable_off->setCheckState(Qt::Unchecked);
            emit ledStateChange(4, true);
        }else {ui->ckb_LaserEnable_off->setCheckState(Qt::Checked); emit ledStateChange(4, false);};
    });
    connect(ui->ckb_LaserEnable_off, &QCheckBox::checkStateChanged, this, [this]() {
        if(ui->ckb_LaserEnable_off->isChecked() ) {
            ui->ckb_LaserEnable_on->setCheckState(Qt::Unchecked);
            emit ledStateChange(4, false);
        }else {ui->ckb_LaserEnable_on->setCheckState(Qt::Checked); emit ledStateChange(4, true);}
    });

    connect(ui->btn_testOn, &QPushButton::clicked, this, [this](){
        qDebug() << "isSimulation = true";
        isSimulation = true;
    });
    connect(ui->btn_testOff, &QPushButton::clicked, this, [this](){
        qDebug() << "isSimulation = false";
        isSimulation = false;
    });
}

Simulation::~Simulation()
{
    delete ui;
}

void Simulation::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);

    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

