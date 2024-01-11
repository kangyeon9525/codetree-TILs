#include <iostream>
#include <vector>
#include <unordered_set>
#define MAX_M 1001

using namespace std;

bool isTree(int n, const vector<pair<int, int>>& edges) {
    if (edges.size() != n-1) return false;

    vector<int> inDegree(n+1, 0);
    unordered_set<int> nodes;

    for (const auto& edge : edges) {
        int start = edge.first;
        int end = edge.second;
        
        inDegree[end]++;
        nodes.insert(start);
        nodes.insert(end);
    }

    int rootCnt = 0;

    for (int i=1; i<=n; i++) {
        if (inDegree[i] == 0) {
            rootCnt++;
            if (rootCnt > 1) return false;
        }
    }

    return (rootCnt == 1 && nodes.size() == n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int m;
    cin >> m;

    vector<pair<int, int>> edges;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    if (isTree(m+1, edges)) cout << 1;
    else cout << 0;

    return 0;
}