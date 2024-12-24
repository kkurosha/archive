#include <iostream>
#include <math.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    double x, y, b;
    cout << "Введите три значения x, y, b: " << endl;
    cin >> x >> y >> b;
    if ((b - x) >= 0 && (b - y) > 0) {
        cout << "z = " << (log(b - y)) * (sqrt(b - x)) << endl;
    }
    else {
        cout << "решение невозможно" << endl;
    }
    return 0;
}