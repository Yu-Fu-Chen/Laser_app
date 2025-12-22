#include <cmath>
#include <QMessageBox>          // 顯示錯誤訊息對話框
#include <vector>

#include "PowerCheck.h"
using namespace std;
using namespace Eigen;

LinearFitResult linearFit(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    if (n == 0) return {0, 0};

    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumX2 = 0;

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double l = (sumY - m * sumX) / n;

    return {m, l};
}


QuadFitResult quadraticFit(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    MatrixXd A(n, 3);
    VectorXd Y(n);

    for (int i = 0; i < n; ++i) {
        A(i, 0) = x[i] * x[i];
        A(i, 1) = x[i];
        A(i, 2) = 1.0;
        Y(i) = y[i];
    }

    // (A^T A)^-1 * A^T * Y
    VectorXd coeff = (A.transpose() * A).ldlt().solve(A.transpose() * Y);

    QuadFitResult result;
    result.a = coeff(0);
    result.b = coeff(1);
    result.c = coeff(2);
    return result;
}

PowerCheck::PowerCheck() {

}

// === 預測功率 ===
// 輸入 SDAC 設定值（ex:880）
// 回傳預測功率（W）
double PowerCheck::predictLinear(double x) {
    qDebug() <<"fit.m = "<< m << " fit.l = " << l;
    return m * x + l;
}

double PowerCheck::predictquad(double x) {
    return a * x * x + b * x + c;
    //return a * setting + b;
}

// === 驗證功率是否正常 ===
// measured：實際量測功率（W）
// setting：SDAC1 設定值
// tol：允許誤差比例（預設 ±10%）
// 回傳：true = 正常，false = 異常
bool PowerCheck::isLDPowerNormal(double measured, double setting, double tol) {
    double predicted = predictLinear(setting);
    double error_ratio = std::fabs(measured - predicted) / predicted;
    qDebug() << "設定值: " << setting
              << " | 預測功率: " << predicted
              << " | 實測功率: " << measured
              << " | 誤差比例: " << error_ratio * 100 << "%";
    if(setting ==0) return true;
    if (error_ratio <= tol) {
        qDebug() << "正常";
        return true;
    } else {
        qDebug() << "異常";
        return false;
    }
}

bool PowerCheck::isLaserPowerNormal(double measured, double setting, double tol, double scale){
    double checkValue = predictLinear(setting);
    double error_ratio = std::fabs(measured - checkValue) / checkValue;
    qDebug() << "設定值: " << setting
             << " | 預測功率: " << checkValue
             << " | 實測功率: " << measured
             << " | 誤差比例: " << error_ratio * 100 << "%";
    if (error_ratio <= tol) {
        qDebug() << "正常";
        return true;
    } else {
        qDebug() << "異常";
        return false;
    }

}
