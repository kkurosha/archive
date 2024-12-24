#include <iostream>
#include <string>
using namespace std;
string to_tr(int n) { /* перевод в 3сс */
    string s = "";
    int k;
    while (n) {
        k = n % 3;
        n /= 3;
        if (k < 10) {
            s = to_string(k) + s;
        }
        else {
            s = string(1, static_cast<char>(k + 55)) + s;
        }
    }
    return s;
}
string to_sh(int n) { /* перевод в 6сс */
    string s = "";
    int k;
    while (n) {
        k = n % 6;
        n /= 6;
        if (k < 10) {
            s = to_string(k) + s;
        }
        else {
            s = string(1, static_cast<char>(k + 55)) + s;
        }
    }
    return s;
}
int main() {
    setlocale(LC_ALL, "rus");
    int count;
    cout << "Введите количество чисел для массива: ";
    cin >> count;
    int* arr = new int[count];
    int* otv = new int[count];
    cout << "Массив из чисел в троичной системе счисления: " << endl;
    for (int i = 1; i <= count; i++) {
        arr[i] = stoi(to_tr(i));
        cout << arr[i] << "\t";
    }
    cout << endl;
    cout << "Массив из чисел в шестеричной системе счисления: " << endl;
    for (int c = 1; c <= count; c++) {
        otv[c] = stoi(to_sh(c));
        cout << otv[c] << "\t";
    }
}