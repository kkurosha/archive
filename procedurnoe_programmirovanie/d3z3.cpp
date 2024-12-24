#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	ofstream zxc("zxc.txt");
	zxc << "qwerty5656565656565656565656555647575757675576767565656565656 h   5 6456664 6 6 6456645646464/59645645o45j90;;45=-=-5=465645'6]4[5'p'yp45'y'PPPP$%P)TUJ056045655 0;0405 6";
	string sls;
	zxc.close();
	ifstream qwe("zxc.txt");
	while (!qwe.eof()) {
		getline(qwe, sls);	
		cout << sls << endl;
	}
	
} 
