﻿#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	float a[3][4] = { {5, 2, 0, 10 }, {3, 5, 2, 5}, {20, 0, 0, 0} };
	float b[4][2] = { {1.20, 0.50}, {2.80, 0.40}, {5.0, 1.0}, {2.0, 1.5} };
	float c[3][2] = { {0, 0}, {0, 0}, {0, 0} };
	float summa = 0, com = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	cout << " Матрица С: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << setw(5) << c[i][j];
		}
		cout << endl;	
	}
	cout << " Деньги с продажи:\t";
	for (int i = 0; i < 3; i++) {
		cout << c[i][0] << "\t";
		summa += c[i][0];
	}
	if (c[0][0] > c[1][0] && c[0][0] > c[2][0]) {
		cout << endl << " - Первый продавец выручил больше всего денег, a";
	}
	else if (c[1][0] > c[0][0] && c[1][0] > c[2][0]) {
		cout << endl << " - Второй продавец выручил больше всего денег, a";
	}
	else {
		cout << endl << " - Третий продавец выручил больше всего денег, a";
	}
	if (c[0][0] < c[1][0] && c[0][0] < c[2][0]) {
		cout << " первый - меньше всего";
	}
	else if (c[1][0] < c[0][0] && c[1][0] < c[2][0]) {
		cout << " второй - меньше всего";
	}
	else {
		cout << " третий - меньше всего";
	}
	cout << endl << " Комиссионные:\t\t";
	for (int i = 0; i < 3; i++) {
		cout << c[i][1] << "\t";
		com += c[i][1];
	}
	if (c[0][1] > c[1][1] && c[0][1] > c[2][1]) {
		cout << endl << " - Первый продавец выручил больше всего комиссионных, a";
	}
	else if (c[1][1] > c[0][1] && c[1][1] > c[2][1]) {
		cout << endl << " - Второй продавец выручил больше всего комиссионных, a";
	}
	else {
		cout << endl << " - Третий продавец выручил больше всего комиссионных, a";
	}
	if (c[0][1] < c[1][1] && c[0][1] < c[2][1]) {
		cout << " первый - меньше всего";
	}
	else if (c[1][1] < c[0][1] && c[1][1] < c[2][1]) {
		cout << " второй - меньше всего";
	}
	else {
		cout << " третий - меньше всего";
	}
	cout << endl << " Общая сумма денег:\t" << summa;
	cout << endl << " Сумма комиссионных:\t" << com;
	cout << endl << " Общая сумма денег:\t" << com + summa << endl;
}