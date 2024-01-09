#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;


    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max_val = arr[0], idx = 0, range = n;
    do {
        max_val = arr[0], idx = 0;
        for (int i=0; i<range; i++) {
            if (max_val < arr[i]) {
                max_val = arr[i];
                idx = i;
            }
        }
        range = idx;
        cout << idx+1 << " ";
    } while (idx != 0);
    

    return 0;
}