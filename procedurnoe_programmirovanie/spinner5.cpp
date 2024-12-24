#include <iostream> 
#include <vector> 
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    int places, students, temp;
    cin >> places >> students;
    vector<int> freePlaces{ places };
    for (int i = 0; i < students; i++) {
        for (int i = 0; i < freePlaces.size() - 1; i++) {
            for (int j = 0; j < freePlaces.size() - i - 1; j++) {
                if (freePlaces[j + 1] > freePlaces[j]) {
                    temp = freePlaces[j];
                    freePlaces[j] = freePlaces[j + 1];
                    freePlaces[j + 1] = temp;
                }
            }
        }
        if (!freePlaces[0]) {
            cout << "Слишком много учеников" << endl;
            return 0;
        }
        freePlaces.resize(freePlaces.size() + 1);
        if (freePlaces[0] % 2) {
            temp = (freePlaces[0] - 1) / 2;
            freePlaces[0] = temp;
            freePlaces[freePlaces.size() - 1] = temp;
        }
        else {
            temp = (freePlaces[0]) / 2;
            freePlaces[0] = temp;
            freePlaces[freePlaces.size() - 1] = temp - 1;
        }
    }
    cout << freePlaces[freePlaces.size() - 1] << " " << freePlaces[0] << endl;
}