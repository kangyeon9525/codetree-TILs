#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isTree(int n, const vector<pair<int, int>>& edges) {
    if (edges.size() != n - 1) return false;

    vector<int> inDegree(n + 1, 0);
    vector<bool> isNodePresent(n + 1, false);

    for (const auto& edge : edges) {
        int start = edge.first;
        int end = edge.second;

        inDegree[end]++;
        isNodePresent[start] = true;
        isNodePresent[end] = true;
    }

    int rootCnt = 0;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            rootCnt++;
            if (rootCnt > 1) return false;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!isNodePresent[i]) return false;
    }

    return rootCnt == 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int m;
    cin >> m;

    vector<pair<int, int>> edges;
    int maxNodeNumber = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        maxNodeNumber = max(maxNodeNumber, max(a, b));
    }

    if (isTree(maxNodeNumber, edges))
        cout << 1;
    else
        cout << 0;

    return 0;
}