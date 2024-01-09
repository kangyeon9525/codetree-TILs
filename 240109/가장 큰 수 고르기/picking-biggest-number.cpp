#include <iostream>
using namespace std;

int main() {
    int arr[10];

    for (int i=0; i<10; i++) {
        cin >> arr[i];
    }

    int max_num = arr[0];
    for (int i=0; i<10; i++) {
        if (arr[i] > max_num) max_num = arr[i];
    }
    cout << max_num;
    return 0;
}