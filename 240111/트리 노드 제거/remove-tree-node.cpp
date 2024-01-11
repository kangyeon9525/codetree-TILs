#include <iostream>
#include <vector>

using namespace std;

int n, removeNodeIdx;
bool isRemoved[51] = {false, };
vector<vector<int>> tree;

void removeNode(int node) {
    isRemoved[node] = true;
    for (int i=0; i<tree[node].size(); i++) {
        int child = tree[node][i];
        if (!isRemoved[child]) removeNode(child);
    }
}

int countLeaf(int node) {
    if (tree[node].empty() || (tree[node].size() == 1 && isRemoved[tree[node][0]])) {
        return 1;
    }

    int cnt = 0;
    for (int i=0; i<tree[node].size(); i++) {
        int child = tree[node][i];
        if (!isRemoved[child]) cnt += countLeaf(child);
    }
    return cnt;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    tree.resize(n);

    for (int i=0; i<n; i++) {
        int parent;
        cin >> parent;
        if (parent != -1) tree[parent].push_back(i);
    }

    cin >> removeNodeIdx;
    removeNode(removeNodeIdx);
    int leafNode = countLeaf(0);
    cout << leafNode;


    return 0;
}