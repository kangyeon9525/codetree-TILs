#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> tree;

void buildTree(vector<int>& inorder, int start, int end, int depth) {
    if (start > end) 
        return;

    int mid = (start + end) / 2;
    tree[depth].push_back(inorder[mid]);

    buildTree(inorder, start, mid - 1, depth + 1);
    buildTree(inorder, mid + 1, end, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int K;
    cin >> K;

    int num = pow(2, K) - 1;
    vector<int> inorder(num);
    for (int i=0; i < num; i++) {
        cin >> inorder[i];
    }

    tree.resize(K);
    buildTree(inorder, 0, num - 1, 0);

    for (const auto &level : tree) {
        for (const auto &node : level) {
            cout << node << ' ';
        }
        cout << endl;
    }

    return 0;
}