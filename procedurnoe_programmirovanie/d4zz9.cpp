#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string p(string n, int c1, int c2) {
	string nmbr = "";
	int dc = 0;
	for (int i = 0; i < n.length(); i++) {
		char ch = n[i];
		if (ch >= '0' && ch <= '9') {
			dc += (ch - '0') * pow(c1, n.length() - i - 1);
		}
		else {
			dc += (ch - 55) * pow(c1, n.length() - i - 1);
		}
	}
	int cl = dc, dr = 0;
	while (cl) {
		dr = cl % c2;
		cl /= c2;
		if (dr < 10) {
			nmbr = to_string(dr) + nmbr;
		}
		else {
			nmbr = string(1, static_cast<char>(dr + 55)) + nmbr;
		}
	}
	return nmbr;
}
int main() {
	setlocale(LC_ALL, "rus");
	string n;
	int c1, c2;
	cout << "Введите число: ";
	cin >> n;
	cout << "Введите старую систему счисления: ";
	cin >> c1;
	cout << "Введите новую систему счисления: ";
	cin >> c2;
	int k = stoi(n);
	while (k) {
		if ((k % 10) >= c1) {
			cout << "Неправильно введённые данные";
			break;
		}
		else {
			cout << "Новое число: " << p(n, c1, c2);
			break;
		}
	}
}