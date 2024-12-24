#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;
int sogl(char b) {
	int check = true;
	char glas[6] = { 'A', 'E', 'U', 'O', 'Y', 'I' };
	for (int i = 0; i < 6; i++) {
		if (b == glas[i]) {
			check = false;
		}
	}
	return check;
}
int main() {
	setlocale(LC_ALL, "rus");
	int count = 0;
	ofstream fout("f.txt");
	fout.close();
	string text;
	ifstream fin("f.txt");
	cout << "Введите строку: ";
	getline(cin, text);
	map<char, int> dict;
	for (char b : text) {
		if (isalpha(b)) {
			b = toupper(b);
			if (sogl(b)) {
				dict[b]++;
				if (dict[b] > count) {
					count = dict[b];
				}
			}
		}
	}
	for (auto s : dict) {
		if (s.second == count) {
			cout << "Согласная '" << s.first << "' была введена " << count << " раз(a)" << endl;
		}
	}
}