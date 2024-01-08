#include <iostream>
using namespace std;

int main() {
    int arr[10], cnt = 0;
    for (int i=0; i<10; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) break;
        arr[i] = tmp;
        cnt++;
    }
    for (int i=cnt-1; i>=0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}