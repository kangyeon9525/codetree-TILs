#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 50

using namespace std;

// 변수 선언:
int n;
int ans;
int root;
int par[MAX_N];
vector<int> edges[MAX_N];
bool is_deleted[MAX_N];

// DFS를 통해 x 아래의 리프노드의 개수를 찾아줍니다.
void DFS(int x) {
    // (루트 노드가 삭제되었을 때) 삭제된 노드는 스킵합니다.
    if(is_deleted[x])
        return;

    // x번 노드가 리프노드인지 판단합니다. 자신의 자식 노드가
    // 하나라도 남아 있을 경우 x번 노드는 리프노드가 아닙니다.
    bool is_leaf = true;

    for(int i = 0; i < edges[x].size(); i++) {
        int y = edges[x][i];
        
        // 삭제된 노드는 스킵합니다.
        if(is_deleted[y]) 
            continue;
        
        DFS(y);
        is_leaf = false;
    }

    // 자신 노드가 리프 노드일 경우 답을 갱신합니다.
    if(is_leaf)
        ans++;
}

int main() {
    // 입력:
    cin >> n;
    // n개의 간선 정보를 입력받습니다.
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> par[i];
        x = i;
        y = par[i];

        // -1이 입력된 경우 루트 노드로 지정합니다.
        if(y == -1) {
            root = x;
            continue;
        }
        
        // 간선 정보를 인접리스트에 넣어줍니다.
        edges[y].push_back(x);
    }

    // 노드를 제거합니다.
    int del_node;
    cin >> del_node;

    // 노드를 제거하는 방법에는 간선을 직접 끊어주는 등 여러 방법이 있습니다.
    // 여기서는 삭제되었는지 여부를 배열로 관리합니다.
    is_deleted[del_node] = true;

    // root 정점으로부터 리프노드의 개수를 찾습니다.
    DFS(root);

    cout << ans;
    return 0;
}