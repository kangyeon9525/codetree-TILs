#include <iostream>
using namespace std;

int main() {
    int arr[10], idx = 0;
    bool noZero = true;
    for (int i=0; i<10; i++) {
        cin >> arr[i];
        if (arr[i] == 0) noZero = false;
        if (noZero) {
            idx++;
        } 
    }

    int cnt = 0, total = 0;
    for (int i=idx-1; i>=0; i--) {
        if (arr[i] % 2 == 0) {
            total += arr[i];
            cnt++;
        }
    }
    cout << cnt << " " << total;
    return 0;
}