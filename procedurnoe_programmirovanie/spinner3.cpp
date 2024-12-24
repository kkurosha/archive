#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int n, m, count;
	cout << "Введите размеры исходного листа N и M: ";
	cin >> n >> m;
	count = n * (n + 1) * m * (m + 1) / 4;
	cout << "Количество прямоугольников, которые можно выразть из данного листа бумаги: " << count;
}