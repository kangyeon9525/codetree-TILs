#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    string grade[n];
    for (int i=0; i<n; i++) {
        int tmp[4];
        double total = 0;
        for (int j=0; j<4; j++) {
            cin >> tmp[j];
            total += tmp[j];
        }
        double avg = total/4;
        if (avg >= 60) grade[i] = "pass", cnt++;
        else grade[i] = "fail";
    }
    for (int i=0; i<n; i++) {
        cout << grade[i] << endl;
    }
    cout << cnt;
    return 0;
}