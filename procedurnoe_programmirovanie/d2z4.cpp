#include <iostream>
#include <math.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    float N;
    cout << "Число N: ";
    cin >> N;
    if (N > 0) {
        if (trunc(N) == N) {
            cout << "Следующие 10 значений, начиная с N: " << endl;
            for (int i = 0; i < 10; i++) {
                cout << N + i << endl;
            }
        }
        else {
            cout << "N не натуральное";
        }
    }
    else {
        cout << "N не подходит";
    }
    return 0;
}