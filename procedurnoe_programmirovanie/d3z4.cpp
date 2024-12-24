#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	ofstream asd("asd.txt");
	asd << "128379812739812sdgsdggggggg1345215325gggggggggggg00000000000g0000001g";
	asd.close();
	string q;
	ifstream cvb("asd.txt");
	while (!cvb.eof()) {
		getline(cvb, q);
		bool plm = false;
		bool tyu = false;
		for (char i : q) {
			if (i >= '0' && i <= '9') {
				cout << i;
				plm = true;
			}
			else {
				if (plm) {
					cout << " ";
					plm = false;
				}
			}
			if (plm) {
				tyu = true;
			}
		}
		if (!tyu) {
			cout << "нет цифр";
		}
	}
	
} 
