#include <iostream>
using namespace std;

int main() {
    int student[100], grade[11] = {}, idx;
    for (int i=0; i<100; i++) {
        cin >> student[i];
        if (student[i] == 0) break;
        else {
            idx = student[i]/10;
            grade[idx]++;
        }
    }
    for (int i=10; i>0; i--) {
        cout << i*10 << " - " << grade[i] << endl;
    }
    return 0;
}