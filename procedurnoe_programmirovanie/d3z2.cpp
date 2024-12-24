#include <iostream>
#include <math.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "Rus");
    bool cr = false;
    float S, m, n, p, r, mm = m, nr, nm;
    cout << "Введите значения S, m, n: ";
    cin >> S >> m >> n;
    if (m && n) {
        for (int i = -100000; i < 100000; i++) {
            nr = i / 10000.0;
            nm = abs(m - (S * nr * pow(1 + nr, n)) / (12 * (pow(1 + nr, n) - 1)));
            if (nm < mm) {
                mm = nm;
                p = i / 100.0;
                cr = true;
            }
        }
        if (cr == true) {
            cout << "p = " << p << "%" << endl;
        }
        else {
            cout << "такого кредита не может быть" << endl;
        }
    }
    else {
        cout << "p = -100%" << endl;
    }
}