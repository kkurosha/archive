#include <iostream>
#include "math.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    int a, b, c, d;
    cout << "Введите три числа: ";
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (a != 0) {
        if (d == 0) {
            cout << "x = " << (-b) / (2 * a) << endl;
        }
        if (d > 0) {
            cout << "x1 = " << ((-b) + sqrt(d)) / (2 * a) << endl;
            cout << "x2 = " << ((-b) - sqrt(d)) / (2 * a) << endl;
        }
        if (d < 0) {
            cout << "x не существует" << endl;
        }
    } 
    else
    {
        if (b != 0)
        {
            cout << "х = " << (-c) / b << endl;
        }
        else {
            if (c == 0)
            {
                cout << "бесконечное количество решений" << endl;
            }
            else
            {
                cout << "не имеет решений" << endl;
            }

        }
    }
    return 0;
}