#include <iostream>

#define MAX_N 26

using namespace std;

// 변수 선언
int n;
int left_num[MAX_N], right_num[MAX_N];

void PreOrder(int x) {
    // -1이면 존재하지 않으므로 빠져나갑니다.
    if(x == -1)
        return;

    cout << (char)(x + 'A');
    PreOrder(left_num[x]);
    PreOrder(right_num[x]);
}

void InOrder(int x) {
    // -1이면 존재하지 않으므로 빠져나갑니다.
    if(x == -1)
        return;

    InOrder(left_num[x]);
    cout << (char)(x + 'A');
    InOrder(right_num[x]);
}

void PostOrder(int x) {
    // -1이면 존재하지 않으므로 빠져나갑니다.
    if(x == -1)
        return;

    PostOrder(left_num[x]);
    PostOrder(right_num[x]);
    cout << (char)(x + 'A');
}

int main() {
    // 입력:
    cin >> n;

    // 자식이 없는 경우 -1을 넣어줍니다.
    for(int i = 0; i < n; i++)
        left_num[i] = right_num[i] = -1;

    for(int i = 0; i < n; i++) {
        char x, l, r;
        cin >> x >> l >> r;
        if(l != '.')
            left_num[x - 'A'] = l - 'A';
        if(r != '.')
            right_num[x - 'A'] = r - 'A';
    }

    // 전위 순회를 진행합니다.
    PreOrder(0);
    cout << endl;
    // 중위 순회를 진행합니다.
    InOrder(0);
    cout << endl;
    // 후위 순회를 진행합니다.
    PostOrder(0);
    cout << endl;
    return 0;
}