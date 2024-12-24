#include <iostream>
using namespace std;
bool prostoe(int n) {
	for (int d = 2; d <= sqrt(n) + 1; d++) {
		if (n % d == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите натуральное число: ";
	cin >> n;
	int* ch = new int[n];
	for (int c = 0; c < n + 1; c++) {
		ch[c] = c;
	}
	cout << "Простые числа:\n" << "2\n";
	for (int t = 0; t < n + 1; t++) {
		if (prostoe(ch[t])) {
			if (ch[t] > 1) {
				cout << ch[t] << endl;
			}
		}
	}
}