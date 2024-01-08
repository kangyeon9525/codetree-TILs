#include <iostream>
using namespace std;

int main() {
    int n, idx = 1, cnt = 0;
    cin >> n;

    while (cnt < 2) {
        cout << n*idx << " ";
        if ((n*idx) % 5 == 0) cnt++;
        idx++;
    }
    return 0;
}