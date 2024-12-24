#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int i = 1;
	float s = 0, h;
	setlocale(LC_ALL, "rus");
	cout << "Введите 10 значений: " << endl;
	ofstream fout("m.txt");
	while (i != 11) {
		cout << i << ". ";
		i += 1;
		float a;
		cin >> a;
		fout << a << endl;
	}
	fout.close();
	ifstream fin("m.txt");
	while (fin >> h) {
		s += h;
	}
	cout << "Сумма равна " << s;
}