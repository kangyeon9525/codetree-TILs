#include <iostream>
using namespace std;

int main() {
    int arr[10] = {}, tmp;


    while (true) {
        cin >> tmp;
        if (tmp == 0) break;
        arr[tmp/10]++;
    }

    for (int i=1; i<10; i++) {
        cout << i << " - " << arr[i] << endl;
    }
    return 0;
}