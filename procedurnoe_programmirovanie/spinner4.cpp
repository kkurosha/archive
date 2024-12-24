#include <cmath> 
#include <iostream> 
using namespace std;
int main() {
    int seats[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= 36) {
            seats[(x - 1) / 4] += 1;
        }
        else {
            seats[8 - (x - 37) / 2] += 1;
        }
    }
    int k = 0, m = 0;
    for (int cup : seats) {
        if (cup == 6) {
            k += 1;
            m = max(m, k);
        }
        else {
            k = 0;
        }
    }
    cout << m;
}