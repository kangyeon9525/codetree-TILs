#include <iostream>
#include <vector>
#define MAX_N 100001

using namespace std;

vector<vector<int>> children; 
vector<int> parent; 
vector<int> depth; 

void DFS(int x) {
    for(int i = 0; i < (int) children[x].size(); i++) {
        int y = children[x][i];
        depth[y] = depth[x] + 1;
        DFS(y);
    }
}

int main() {
    int n;
    cin >> n;

    children.resize(MAX_N);
    parent.resize(MAX_N);
    depth.resize(MAX_N);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        children[u].push_back(v);
        parent[v] = u;
    }

    int a, b;
    cin >> a >> b;

    // 부모가 여전히 없는 노드가 루트 노드가 됩니다.
    int root_vertex = 0;
    for(int i = 1; i <= n; i++)
        if(parent[i] == 0)
            root_vertex = i;
    
    depth[root_vertex] = 1;
    DFS(root_vertex);

    // Step 1.
    // 두 노드 a, b의 depth를 비교하며
    // depth가 더 큰 쪽을 위로 올리는 것을 반복하며 두 노드의 depth를 맞춰줍니다.
    while (depth[a] != depth[b]) {
        if (depth[a] > depth[b]) 
            a = parent[a];
        else 
            b = parent[b];
    }

    // Step 2.
    // 두 노드 a, b가 일치해질떄까지
    // 한 칸씩 위로 올라갑니다.
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    cout << a << endl; 

    return 0;
}