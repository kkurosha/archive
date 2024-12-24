#include <iostream>
#include <cmath>
using namespace std;
double f(double x, double e, int& n) {
	int a1 = 1;
	double a2 = x, a3 = pow(x, 3);
	double a4 = (12 - a3 * x) / (pow(a2, 2) + sqrt(a1));
	n = 4;
	while (abs(a4 - a3) < e || n <= 15) {
		n++;
		a1 = a2;
		a2 = a3;
		a4 = (12 - a3 * x) / (pow(a2, 2) + sqrt(a1));
	}
	return a4;
}
int main() {
	setlocale(LC_ALL, "rus");
	double x, e;
	int n;
	cout << "Введите значения x и eps: ";
	cin >> x >> e;
	cout << "Условие выполняется для a(n) = " << f(x, e, n);
}