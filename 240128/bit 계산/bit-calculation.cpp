#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    int S = 0;

    while (q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int x;
            cin >> x;
            S |= (1 << (x - 1));
        } else if (cmd == "delete") {
            int x;
            cin >> x;
            S &= ~(1 << (x - 1));
        } else if (cmd == "print") {
            int x;
            cin >> x;
            cout << ((S & (1 << (x - 1))) != 0) << '\n';
        } else if (cmd == "toggle") {
            int x;
            cin >> x;
            S ^= (1 << (x - 1));
        } else if (cmd == "clear") {
            S = 0;
        }
    }

    return 0;
}