#include <iostream>
#include "math.h"
using namespace std;
int main() {
    double x;
    double a;
    setlocale(LC_ALL, "rus");
    cout << "Введите число а: " << endl;
    cin >> a;
    cout << "Введите число x: " << endl;
    cin >> x;
    if (abs(x) < 1 && (x != 0)) {
        cout << "w = " << a * log(abs(x)) << endl;
    }
    else if ((abs(x) >= 1) && (a - x * x) >= 0) {
        cout << "w = " << sqrt(a - x * x) << endl;
    }
    else {
        cout << "определить невозможно" << endl;
    }
    return 0;
}