#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n], max_val = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] < arr[j] && (arr[j]-arr[i] > max_val)) max_val = arr[j]-arr[i];
        }
    }

    cout << max_val;
    return 0;
}