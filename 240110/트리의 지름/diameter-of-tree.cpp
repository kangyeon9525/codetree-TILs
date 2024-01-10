#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000

using namespace std;

int n;
vector<pair<int, int>> edges[MAX_N + 1];
int parent[MAX_N + 1];
bool visited[MAX_N + 1];
int diameter = 0;

void dfs(int node, int dist) {
    visited[node] = true;
    for (auto i : edges[node]) {
        int neighbor = i.first;
        int weight = i.second;

        if (visited[neighbor]) continue;
        parent[neighbor] = node;
        dfs(neighbor, dist + weight);
    }

    if (dist > diameter) diameter = dist;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    dfs(1, 0);
    cout << diameter << "\n";

    return 0;
}