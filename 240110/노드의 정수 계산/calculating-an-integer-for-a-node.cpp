#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

int n;
vector<int> edges[MAX_N + 1];

int arr[MAX_N + 1];
int dp[MAX_N + 1]; 

void DFS(int x) {
    for(int i = 0; i < (int) edges[x].size(); i++) {
        int y = edges[x][i];
        DFS(y);
    }

    dp[x] = arr[x]; 
    for(int i = 0; i < (int) edges[x].size(); i++) {
        int y = edges[x][i];
        if(dp[y] > 0)
            dp[x] += dp[y];
    }
}

int main() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int t, a, p;
        cin >> t >> a >> p;

        edges[p].push_back(i);

        arr[i] = (t == 1) ? a : -a;
    }

    DFS(1);

    cout << dp[1];
    return 0;
}