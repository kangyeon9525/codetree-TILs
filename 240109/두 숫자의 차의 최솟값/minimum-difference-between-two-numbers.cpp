#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n], min_val = 100;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=1; i<n; i++) {
       if (arr[i]-arr[i-1] < min_val) min_val = arr[i]-arr[i-1];
    }

    cout << min_val;
    return 0;
}