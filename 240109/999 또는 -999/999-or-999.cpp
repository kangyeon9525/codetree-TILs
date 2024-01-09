#include <iostream>
using namespace std;

int main() {
    
    int arr[100], idx;
    for (int i=0; i<100; i++) {
        cin >> arr[i];
        idx = i;
        if (arr[i] == 999 || arr[i] == -999) break;
        else continue;
    }

    int max_val = arr[0], min_val = arr[0];

    for (int i=0; i<idx; i++) {
        if (max_val < arr[i]) max_val = arr[i];
        if (min_val > arr[i]) min_val = arr[i];
    }

    cout << max_val << " " << min_val;
    return 0;
}