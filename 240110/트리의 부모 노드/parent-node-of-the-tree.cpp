#include <iostream>
#include <vector>
#define MAX_N 100001

using namespace std;

vector<int> edges[MAX_N];
vector<int> parent(MAX_N, 0);
vector<bool> visited(MAX_N, false);

void dfs(int n) {
    visited[n] = true;
    for (int i = 0; i < edges[n].size(); i++) {
        int neighbor = edges[n][i];
        if (!visited[neighbor]) {
            parent[neighbor] = n;
            dfs(neighbor);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1);

    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << '\n';
    }

    return 0;
}