#include <iostream>
using namespace std;

int main() {
    double n;
    cin >> n;
    cout << fixed; cout.precision(1); cout << 30.48*n;
    return 0;
}