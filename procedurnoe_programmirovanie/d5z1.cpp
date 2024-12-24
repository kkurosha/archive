#include <iostream>
using namespace std;
int del(int x, int y) {
	int dl;
	for (int i = 1; i <= y; i++) {
		if (x % i == 0 && y % i == 0) {
			dl = i;
		}
	}
	return dl;
}
int sl(int x, int y) {
	int pl;
	while (x != y) {
		if (x > y) {
			x -= y;
		}
		else {
			y -= x;
		}
	}
	pl = x;
	return pl;
}
int main() {
	setlocale(LC_ALL, "rus");
	int x, y;
	cout << "Введите два числа: ";
	cin >> x >> y;
	if (x <= 0 || y <= 0) {
		cout << "Нужно натуральное число";
	}
	else {
		cout << "НОД с помощью деления: " << del(x, y) << endl;
		cout << "НОД с помощью вычитания: " << sl(x, y);
	}
}