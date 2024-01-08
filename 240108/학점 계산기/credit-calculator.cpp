#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double arr[n], total = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    double avg = total/n;
    cout << fixed; cout.precision(1);
    cout << avg << endl;
    if(avg >= 4) cout << "Perfect";
    else if (avg >= 3) cout << "Good";
    else cout << "Poor";
    return 0;
}