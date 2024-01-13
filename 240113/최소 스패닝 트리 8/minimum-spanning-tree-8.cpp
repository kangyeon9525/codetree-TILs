#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;

    // 간선의 가중치를 기준으로 정렬하기 위한 비교 함수
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findSet(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = findSet(parent[v]);
    }

    void unionSets(int a, int b) {
        int rootA = findSet(a);
        int rootB = findSet(b);

        if (rootA != rootB) {
            parent[rootA] = rootB;
        }
    }
};

int kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end()); // 가중치 기준으로 간선 정렬

    UnionFind uf(n);
    int minWeight = 0;

    for (const Edge& edge : edges) {
        int rootU = uf.findSet(edge.u);
        int rootV = uf.findSet(edge.v);

        if (rootU != rootV) {
            uf.unionSets(rootU, rootV);
            minWeight += edge.weight;
        }
    }

    return minWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    int result = kruskal(edges, n);
    cout << result << '\n';

    return 0;
}