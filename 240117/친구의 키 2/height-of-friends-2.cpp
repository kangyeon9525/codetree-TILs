#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;

vector<int> edges[MAX_N + 1];
bool visited[MAX_N + 1];
bool finished[MAX_N + 1];
stack<int> reversed_order;

bool DFS(int x) {
    visited[x] = true;

    for (int i = 0; i < (int)edges[x].size(); i++) {
        int y = edges[x][i];

        if (!visited[y]) {
            if (!DFS(y))
                return false;
        } else if (!finished[y]) {
            // Back edge (cycle detected)
            return false;
        }
    }

    finished[x] = true;
    reversed_order.push(x);
    return true;
}

bool isConsistent(int n) {
    fill(visited, visited + n + 1, false);
    fill(finished, finished + n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (!DFS(i))
                return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> friend_height[MAX_N];

    for (int i = 0; i < m; i++) {
        cin >> friend_height[i].first >> friend_height[i].second;
        edges[friend_height[i].first].push_back(friend_height[i].second);
    }

    if (isConsistent(n)) {
        cout << "Consistent" << endl;
    } else {
        cout << "Inconsistent" << endl;
    }

    return 0;
}