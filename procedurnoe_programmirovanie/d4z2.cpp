#include <iostream>
using namespace std;
int sign(float x) {
	if (x > 0) {
		return 1;
	}
	else if (x == 0) {
		return 0;
	}
	else {
		return -1;
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	float c;
	cout << "Введите число: ";
	cin >> c;
	cout << "Знак введенного числа: ";
	switch (sign(c)) {
	case 1:
		cout << "+";
		break;
	case 0:
		cout << "0";
		break;
	case -1:
		cout << "-";
		break;
	}

}