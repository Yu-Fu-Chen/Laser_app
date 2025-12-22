#ifndef POWERCHECK_H
#define POWERCHECK_H
#include <Eigen/Dense>
#include <vector>

using namespace std;

struct LinearFitResult {
    double m;  // 斜率
    double l;  // 截距
};
struct QuadFitResult {
    double a, b, c;
};

LinearFitResult linearFit(const vector<double>& x, const vector<double>& y);

class PowerCheck
{
    friend class AutoP;
public:
    PowerCheck();
    double predictLinear(double x);
    double predictquad(double x);
    bool isLDPowerNormal(double measured, double setting, double tol = 0.10);
    bool isLaserPowerNormal(double measured, double measuredLD, double tol = 0.10, double scale = 0.75);

private:
    // --- 擬合係數（透過資料得出） --- 日後可通過大數據分析使資料收斂  P(x) = a*x^2 + b*x + c


    double a = 0;
    double b = 0;
    double c = 0;


    // 擬合一次方程
    double m = 0;
    double l = 0;

/*
    const double a = 5.669738647682768e-05;
    const double b = 0.5909026338447791;
    const double c = -44.48446358739881;
*/
};

#endif // POWERCHECK_H
