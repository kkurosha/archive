#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int a, b, c, n;
	cout << "Введите значения для A, B и С: ";
	cin >> a >> b >> c;
	if (a > c) {
		cout << "неправильно введенные данные!";
	}
	else {
		n = floor((c - a) / b);
	}
	cout << "Максимальное число лопастей спиннера: " << n;
}