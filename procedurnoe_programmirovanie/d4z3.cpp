#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double rect(double a, double b) {
	return a * b;
}
double trian(double a, double b, double c) {
	double p;
	p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
double circle(double r) {
	return 3.1415926535 * r * r;
}
int main() {
	setlocale(LC_ALL, "rus");
	double a, b, c, r, h;
	int ch;
	cout << "1 - прямоугольник, 2 - треугольник, 3 - круг" << endl;
	cin >> ch;
	switch (ch) {
		case 1:
			cout << "Введите стороны прямоугольника a и b: ";
			cin >> a >> b;
			if (a > 0 && b > 0) {
				cout << "S = " << rect(a, b);
			}
			else {
				cout << "Неправильные значения";
			}
			break;
		case 2:
			cout << "Введите стороны треугольника a, b, c: ";
			cin >> a >> b >> c;
			if (a > 0 && b > 0 && c > 0) {
				if (a + b > c && a + c > b && c + b > a) {
					cout << "S = " << trian(a, b, c);
				}
				else {
					cout << "Такого треугольника нет";
				}
			}
			else {
				cout << "Неправильные значения";
			}
			break;
		case 3:
			cout << "Введите радиус круга r: ";
			cin >> r;
			if (r > 0) {
				cout << "S = " << circle(r);
			}
			else {
				cout << "Неправильные значения";
			}
			break;
	}
}