#include <iostream>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, m, k;

// 번호별 그룹을 관리합니다.
int uf[MAX_N + 1];
int path[MAX_N + 1];

// x의 대표 번호를 찾아줍니다.
int Find(int x) {
    // x가 루트 노드라면 x값을 반환합니다.
    if(uf[x] == x)
        return x;
    // x가 루트 노드가 아니라면
    // x의 부모인 uf[x]에서 탐색을 더 진행한 뒤
    // 찾아낸 루트 노드를 uf[x]에 넣어줌과 동시에
    // 해당 노드값을 반환합니다.
    return uf[x] = Find(uf[x]);
}

// x, y가 같은 집합이 되도록 합니다.
void Union(int x, int y) {
    // x, y의 대표 번호를 찾은 뒤
    // 연결해줍니다.
    int X = Find(x);
    int Y = Find(y);
    uf[X] = Y;
}

int main() {
    // 입력:
    cin >> n >> m >> k;

    // 초기 uf 값을 설정합니다.
    for(int i = 1; i <= n; i++)
        uf[i] = i;

    // 주어진 간선으로
    // 연결관계를 만들어줍니다.
    while(m--) {
        int a, b;
        cin >> a >> b;

        // 합치는 명령입니다.
        Union(a, b);
    }

    // 경로를 이동하는 것이 가능하면 true, 아니라면 false를 기록합니다.
    bool is_pos = true;
    for(int i = 1; i <= k; i++)
        cin >> path[i];

    // 만약 경로의 i번째 노드에서 i + 1번째 노드가 연결되어 있지 않으면 이동하는 것이 불가능합니다.
    // 이는 대표 번호가 동일한지로 판단 가능합니다.
    for(int i = 1; i <= k - 1; i++) {
        if(Find(path[i]) != Find(path[i + 1]))
            is_pos = false;
    }
    
    if(is_pos) cout << 1;
    else cout << 0;
    return 0;
}