#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;

const int MAX_N = 100000;

vector<int> edges[MAX_N + 1];
bool visited[MAX_N + 1];
stack<int> reversed_order;

void DFS(int x) {
    for (int i = 0; i < (int)edges[x].size(); i++) {
        int y = edges[x][i];

        if (!visited[y]) {
            visited[y] = true;
            DFS(y);
        }
    }

    reversed_order.push(x);
}

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> friend_height[MAX_N];

    for (int i = 0; i < m; i++) {
        cin >> friend_height[i].first >> friend_height[i].second;
        edges[friend_height[i].first].push_back(friend_height[i].second);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            DFS(i);
        }
    }

    while (!reversed_order.empty()) {
        cout << reversed_order.top() << " ";
        reversed_order.pop();
    }

    return 0;
}