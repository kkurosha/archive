#include <iostream>
#include <fstream>
#include <string>
#include <map>  /* 48 - 57 */
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	string text;
	ofstream fout("fq.txt");
	fout.close();
	ifstream fin("fq.txt");
	cout << "Введите текст: ";
	getline(cin, text);
	for (int i = 0; i < text.length(); i++) {
		if (text[i] > '0' && text[i] < '9') {
			cout << "Цифра: " << text[i] << " Индекс: " << i << endl;
		}
	}
}