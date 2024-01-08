#include <iostream>
using namespace std;

int main() {
    char symptom[3];
    int temp[3], emer[4] = {};
    for (int i=0; i<3; i++) {
        cin >> symptom[i] >> temp[i];
    }

    for (int i=0; i<3; i++) {
        if (symptom[i] == 'Y' && temp[i] >= 37) emer[0]++;
        else if (symptom[i] == 'N' && temp[i] >= 37) emer[1]++;
        else if (symptom[i] == 'Y' && temp[i] < 37) emer[2]++;
        else if (symptom[i] == 'N' && temp[i] < 37) emer[3]++;
        else break;
    }

    for (int i=0; i<4; i++) {
        cout << emer[i] << " ";
    }
    if (emer[0] >= 2) cout << "E";


    return 0;
}