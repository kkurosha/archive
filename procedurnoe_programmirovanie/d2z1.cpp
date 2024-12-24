#include <iostream> //V = 1/3ph(R2+Rr+r2), S = p(R2+(R+r)l+r2)
#include "math.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    double p = 3.14;
    cout << "введите значения h, R, r, l:" << endl;
    double h, R, r, l;
    cin >> h >> R >> r >> l;
    if (h > 0 && R > 0 && r > 0) {
        double l1 = sqrt((R - r) * (R - r) + h * h);
        if (l == l1) {
            double V = (p * h * (R * R + R * r + r * r)) / 3;
            double S = p * (R * R + (R + r) * l + r * r);
            cout << "V = " << V << endl;
            cout << "S = " << S << endl;
        }
        else {
            cout << "значения введены неправильно" << endl;
        }
    }
    else {
        cout << "значения не положительны" << endl;
    }
    return 0;
}