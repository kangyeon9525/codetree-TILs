#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n], val_cnt[1001] = {}, idx = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<n; i++) {
        val_cnt[arr[i]]++;
    }

    int max_val = -1;
    for (int i=0; i<n; i++) {
        if (val_cnt[arr[i]] == 1 && max_val < arr[i]) max_val = arr[i]; 
    }

    cout << max_val;
    return 0;
}