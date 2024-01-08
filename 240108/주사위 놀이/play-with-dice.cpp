#include <iostream>
using namespace std;

int main() {
    int dice[6] = {0, }, tmp;
    for (int i=0; i<10; i++) {
        cin >> tmp;
        dice[tmp-1]++;
    }

    for (int i=0; i<6; i++) {
        cout << i+1 << " - " << dice[i] << endl;
    }
    return 0;
}