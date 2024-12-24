#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	cout << endl << setw(42) << "Былая слава 1912 года" << endl;
	cout << "  ";
	for (int i = 0; i < 60; i++) {
		cout << "_";
	}
	cout << "\n";
	for (int j = 0; j < 6; j++) {
		cout << " |";
		for (int t = 0; t < 9; t++) {
			cout << " * ";
		}
		cout << "|";
		for (int p = 0; p < 32; p++) {
			cout << "_";
		}
		cout << "|" << endl;
	}
	for (int q = 0; q < 7; q++) {
		cout << " |";
		for (int y = 0; y < 60; y++) {
			cout << "_";
		}
		cout << "|" << endl;
	}
}
