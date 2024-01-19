#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<vector<int>> adj(n + 1);
    vector<int> time(n + 1, 0);
    vector<int> indegree(n + 1, 0);
    vector<int> result(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> time[i];
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int job;
            cin >> job;
            adj[job].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            result[i] = time[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            result[next] = max(result[next], result[cur] + time[next]);
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << *max_element(result.begin(), result.end());

    return 0;
}