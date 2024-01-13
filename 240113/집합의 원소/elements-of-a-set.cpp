#include <iostream>
#include <vector>

using namespace std;

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

    void unionSets(int a, int b) {
        int rootA = findSet(a);
        int rootB = findSet(b);
        if (rootA != rootB) {
            parent[rootA] = rootB; 
        }
    }

    int findSet(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = findSet(parent[a]);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; ++i) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) {
            uf.unionSets(a, b);
        } else {
            int result = (uf.findSet(a) == uf.findSet(b)) ? 1 : 0;
            cout << result << '\n';
        }
    }

    return 0;
}