#include <iostream>
using namespace std;

int main() {
    int n, idx=0;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp%2 == 0) {
            arr[idx++] = tmp;
        }
    }
    for (int i=idx-1; i>=0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}