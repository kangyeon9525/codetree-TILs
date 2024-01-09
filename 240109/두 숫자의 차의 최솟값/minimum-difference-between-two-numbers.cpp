#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n], min_val = 100;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[j] >= arr[i] && arr[j]-arr[i] < min_val) min_val = arr[j]-arr[i];
            else if (arr[i] >= arr[j] && arr[i]-arr[j] < min_val) min_val = arr[i]-arr[j];
        }
    }

    cout << min_val;
    return 0;
}