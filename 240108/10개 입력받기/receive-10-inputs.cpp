#include <iostream>
using namespace std;

int main() {
    int arr[10], cnt = 0, total = 0;
    bool noZero = true;
    for (int i=0; i<10; i++) {
        cin >> arr[i];
        if (arr[i] == 0) noZero = false;
        if (noZero) {
            total += arr[i];
            cnt++;
        }
    }
    double avg = (double)total/cnt;
    cout << fixed; cout.precision(1);
    cout << total << " " << avg;
    return 0;
}