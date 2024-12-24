#include <iostream>
#include "math.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	float S, p, n, r;
	cout << "Введите значения S, p, n: " << endl;
	cin >> S >> p >> n;
	r = abs(p) / 100;
	if (p > 0) {
		if (S > 0 && n > 0) {
			cout << "Месячная выплата m = " << (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1)) << endl;
		}
		else {
			cout << "Введенные значения не корректны";
		}
	}
	else if (p == 0) {
		cout << "Месячная выплата m = " << S / (n * 12) << endl;
	}
	else {
		if (S > 0 && n > 0) {
			cout << "Месячная выплата m = " << (S * pow((1 + r), n)) << endl;
		}
		else {
			cout << "Введенные значения не корректны";
		}
	}
	return 0;
}