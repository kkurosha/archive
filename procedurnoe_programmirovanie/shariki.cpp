#include <iostream>
#include <algorithm>
using namespace std;
bool perestanovka(int* u, int n) {
    for (int i = 0; i < n; i++) {
        if (u[i] == i) {
            return true;
        }
    }
    return false;
}
int main() { /* 10! = 3628800 */
    setlocale(LC_ALL, "rus");
    int u[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int  n = 10, factorial = 3628800, otv = 0;
    for (int i = 0; i < factorial; ++i) {
        next_permutation(u, u + n);
        if (perestanovka(u, n)) {
            otv += 1;
        }
    }
    cout << "Общее количество ситуаций: " << otv << endl;
}