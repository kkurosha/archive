#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int m, tr, ch;
	cout << "Введите количество лопастей M: ";
	cin >> m;
	bool flag = false;
	for (int i = 0; i * 3 <= m; i++) {
		for (int j = 0; j * 4 <= m; j++) {
			tr = 3 * i;
			ch = 4 * j;
			if (tr + ch == m) {
				flag = true;
				cout << "Количество трёхлопастных: " << i << endl << "Количество четырёхлопастных: " << j << endl;
				break;
			}
		}
		if (flag) {
			break;
		}
	} 
	if (!flag) {
		cout << "невозможно составить";
	}
}