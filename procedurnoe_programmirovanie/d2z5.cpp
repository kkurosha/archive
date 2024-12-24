#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    double xmin = -4, xmax = 4, shag = 0.5;
    for (double x = xmin; x <= xmax; x = x + shag) {
        cout << "при х = " << x << ": ";
        if (x - 1 != 0) {
            cout << "y = " << (x * x - 2 * x + 2) / (x - 1) << endl;
        }
        else {
            cout << "решения нет" << endl;
        }

    }
    return 0;
}