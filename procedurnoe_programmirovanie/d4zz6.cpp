#include <iostream>
#include <string>
using namespace std;
int alph(char s) {
	switch (s) {
	case 'I': return 1;
		break;
	case 'V': return 5;
		break;
	case 'X': return 10;
		break;
	case 'L': return 50;
		break;
	case 'C': return 100;
		break;
	case 'D': return 500;
		break;
	case 'M': return 1000;
		break;
	case '0': return 0;
		break;
	}
	return -1;
}
int main() {
	setlocale(LC_ALL, "rus");
	string s = "";
	int nmbr = 0, c, k = 0, len;
	cout << "Введите число: ";
	cin >> s;
	len = s.length();
	for (c = len - 1; c >= 0; c--) {
		if (alph(s[c]) >= k) {
			nmbr += alph(s[c]);
		}
		else {
			nmbr -= alph(s[c]);
		}
		k = alph(s[c]);
	}
	cout << nmbr << endl;
} 

