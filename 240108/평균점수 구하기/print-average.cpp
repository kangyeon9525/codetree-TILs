#include <iostream>
using namespace std;

int main() {
    
    double grade[8], total = 0;
    for (int i=0; i<8; i++) {
        cin >> grade[i];
        total += grade[i];
    }
    double avg = total/8;
    cout << fixed; cout.precision(1);
    cout << avg;

    return 0;
}