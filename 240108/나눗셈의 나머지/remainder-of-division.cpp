#include <iostream>
using namespace std;

int main() {
    int a, b, left[10] = {}, sum = 0;

    cin >> a >> b;

    int tmp;
    while (a>1) {
        tmp = a%b;
        left[tmp]++;
        a /= b;
    }

    for (int i=0; i<10; i++) {
        sum += left[i]*left[i];
    }
    cout << sum;
    return 0;
}