#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
vector<pair<int, int>> tree[10001];
vector<int> dist(10001);

pair<int, int> bfs(int start) {
    vector<bool> visited(n+1, false);
    fill(dist.begin(), dist.end(), 0);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    pair<int, int> maxDist = {0, start};

    while (!q.empty()) {
        int current = q.front(); q.pop();
        for (auto &adj : tree[current]) {
            int next = adj.first, weight = adj.second;
            if (visited[next]) continue;
            visited[next] = true;
            dist[next] = dist[current] + weight;
            q.push(next);
            if (dist[next] > maxDist.first) {
                maxDist.first = dist[next];
                maxDist.second = next;
            }
        }
    }
    return maxDist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    pair<int, int> p = bfs(1);
    pair<int, int> result = bfs(p.second);

    cout << result.first << '\n';

    return 0;
}