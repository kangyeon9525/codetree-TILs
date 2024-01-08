#include <iostream>
using namespace std;

int main() {
    int n, arr[100], idx;
    cin >> n;

    arr[0] = 1; arr[1] = n;
    for (int i=2; i<100; i++) {
        arr[i] = arr[i-1] + arr[i-2];
        idx = i+1;
        if (arr[i] >= 100) break;
    }

    for (int i=0; i<idx; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}