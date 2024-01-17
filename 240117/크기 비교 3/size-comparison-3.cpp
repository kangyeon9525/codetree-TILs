#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 32000;

vector<int> adj[MAX_N + 1];
int in_degree[MAX_N + 1];
vector<int> result;

void topologicalSort(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();
        result.push_back(current);

        for (int next : adj[current]) {
            in_degree[next]--;
            if (in_degree[next] == 0) {
                pq.push(next);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    topologicalSort(n);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}