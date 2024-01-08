#include <iostream>
using namespace std;

int main() {
    
    int arr[100], idx = 0;
    while (true) {
        cin >> arr[idx];
        if (arr[idx] == 0) break;
        if (arr[idx] % 2 == 1) arr[idx] += 3;
        else if (arr[idx] % 2 == 0) arr[idx] /= 2;
        idx++;
    }

    for (int i=0; i<idx; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}