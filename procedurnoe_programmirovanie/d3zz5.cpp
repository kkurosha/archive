#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	string str;
	getline(cin, str);
	bool flag = false;
	for (char c : str) {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			flag = false;
		}
		else {
			cout << "данные введены неверно";
			flag = true;
			break;
		}
	}
	if (!flag) {
		for (int i = 0; i < str.length(); i++) {
			for (int j = i+1; j < str.length(); j++) {
				if (str[i] > str[j]) {
					swap(str[i], str[j]);
				}
			}
		}
		cout << str;
	}
} 
