#include <iostream>
using namespace std;

int main() {
    int arr[10], total = 0, cnt = 0;
    double avg;
    
    for (int i=0; i<10; i++) {
        cin >> arr[i];
        if (arr[i] >= 250) break;
        total += arr[i];
        cnt++;
    }
    avg = double(total)/cnt;

    cout << fixed; cout.precision(1);
    cout << total << " " << avg;

    return 0;
}