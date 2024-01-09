#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int min_val = arr[0], min_cnt = 1;
    for (int i=0; i<n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_cnt = 1;
        } else if (arr[i] == min_val) {
            min_cnt++;
        } else continue;
    }

    cout << min_val << " " << min_cnt;

    return 0;
}