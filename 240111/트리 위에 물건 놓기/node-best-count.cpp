#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree; // 트리 구조를 저장할 2차원 벡터
vector<bool> hasItem; // 정점에 물건이 놓여져 있는지를 저장할 벡터

void dfs(int node, int parent) {
    bool allItems = true; // 현재 정점에서 모든 간선에 대해 물건이 있는지 여부를 저장할 변수

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];
        if (next != parent) { // 부모 정점으로 되돌아가는 간선은 제외
            dfs(next, node);
            if (!hasItem[next]) { // 다음 정점에 물건이 없는 경우
                allItems = false;
            }
        }
    }

    if (!allItems) { 
        hasItem[node] = true;
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    hasItem.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0); 

    int itemCount = 0;
    for (int i = 1; i <= n; i++) {
        if (hasItem[i]) {
            itemCount++;
        }
    }

    cout << itemCount << endl;

    return 0;
}