#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus"); /* au - 7 , ag - 6 , cusn - 5 */
	string countries[10] = { "Германия", "Норвегия", "Россия", "Австрия", "Канада", "США", "Финляндия", "Япония", "Китай", "Корея" };
	int au[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int ag[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int cusn[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int summa[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int score[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int au_ag[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	ofstream fout("Olympic_Games.txt");
	fout << setw(25) << "Итоги Олимпийских Игр: " << endl << endl;
	/* fout << "Страна\t" << "Золото\t" << "Серебро\t" << "Бронза\t" << "Всего\t" << "Очков" << endl; */
	for (int i = 0; i < 10; i++) {
		cout << "Количество золотых, серебряных, бронзовых медалей у " << countries[i] << ": ";
		cin >> au[i] >> ag[i] >> cusn[i];
		summa[i] = au[i] + ag[i] + cusn[i];
		score[i] = au[i] * 7 + ag[i] * 6 + cusn[i] * 5;
		cout << "Всего медалей у " << countries[i] << ": " << summa[i] << endl;
		cout << "Количество очков у " << countries[i] << ": " << score[i] << endl;
	}
	for (int c = 0; c < 10; c++) {
		au_ag[c] = au[c] + ag[c];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (au_ag[i] < au_ag[j]) {
				swap(au_ag[i], au_ag[j]);
				swap(countries[i], countries[j]);
				swap(au[i], au[j]);
				swap(ag[i], ag[j]);
				swap(cusn[i], cusn[j]);
				swap(summa[i], summa[j]);
				swap(score[i], score[j]);
			}
		}
	}
	cout << endl << endl << endl;
	for (int k = 0; k < 10; k++) {
		cout << "У " << countries[k] << " сумма количества золотых и серебряных медалей: " << au_ag[k] << endl;
		fout << countries[k] << " -> " << au[k] << " " << ag[k] << " " << cusn[k] << endl;
	}
	fout.close();
	cout << endl << endl << endl;
	string vv;
	ifstream fin("Olympic_Games.txt");
	while (!fin.eof()) {
		getline(fin, vv);
		cout << endl << vv;
	}
	fin.close();
}