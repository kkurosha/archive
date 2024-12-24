#include <iostream> /* Si+1 = (m*Si + i) mod c */
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int m1 = 37, b1 = 3, c1 = 64;
	int m2 = 25173, b2 = 13849, c2 = 65537;
	int s = 0, n = 10;
	while (s != n) {
		cout << (m1 * s + b1) % c1 << " ";
		s += 1;
	}
	cout << endl;
	s = 0;
	while (s != n) {
		cout << (m2 * s + b2) % c2 << " ";
		s += 1;
	}
}