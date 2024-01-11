#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 50000; // 최대 정점의 수
const int MAX_H = 17; // 2^MAX_H > MAX_N

int n; // 정점의 수
vector<int> children[MAX_N + 1]; // 각 정점의 자식들을 저장하는 배열
int parent[MAX_H + 1][MAX_N + 1]; // 각 정점의 2^h 번째 부모를 저장하는 배열
int depth[MAX_N + 1]; // 각 정점의 깊이(depth)를 저장하는 배열

// 트리를 구성하고, 각 정점의 부모와 깊이 정보를 저장합니다.
void buildTree(int x, int p, int d) {
    parent[0][x] = p;
    depth[x] = d;

    for (int i = 0; i < children[x].size(); i++) {
        int y = children[x][i];
        if (y != p) {
            buildTree(y, x, d + 1);
        }
    }
}

// 트리의 부모 정보를 미리 계산합니다.
void precomputeParents() {
    for (int h = 1; (1 << h) <= n; h++) {
        for (int i = 1; i <= n; i++) {
            if (parent[h - 1][i] != 0) {
                parent[h][i] = parent[h - 1][parent[h - 1][i]];
            }
        }
    }
}

// LCA를 구하는 함수
int getLCA(int a, int b) {
    // Step 1. 높이를 맞추기 위해 두 노드를 올려줍니다.
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    for (int h = MAX_H; h >= 0; h--) {
        if (depth[b] - depth[a] >= (1 << h)) {
            b = parent[h][b];
        }
    }

    // Step 2. 두 노드를 같은 높이까지 올려줍니다.
    if (a != b) {
        for (int h = MAX_H; h >= 0; h--) {
            if (parent[h][a] != parent[h][b]) {
                a = parent[h][a];
                b = parent[h][b];
            }
        }
        a = parent[0][a];
    }

    return a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        children[u].push_back(v);
        children[v].push_back(u);
    }

    // 트리를 구성하고, 각 정점의 부모와 깊이 정보를 저장합니다.
    buildTree(1, 0, 0);

    // 트리의 부모 정보를 미리 계산합니다.
    precomputeParents();

    // 질의에 대한 답을 출력합니다.
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int lca = getLCA(a, b);
        cout << lca << "\n";
    }

    return 0;
}