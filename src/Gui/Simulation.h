#ifndef SIMULATION_H
#define SIMULATION_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class Simulation;
}

class Simulation : public QWidget
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = nullptr);
    ~Simulation();

    bool isConnected = false;
    bool isSimulation = false;

private:
    Ui::Simulation *ui;

signals:
    void ledStateChange(int who, bool isOn);
    void setConnect(QString type);

protected:
    // 處理繪圖事件
    void paintEvent(QPaintEvent *event) override;
};

#endif // SIMULATION_H
