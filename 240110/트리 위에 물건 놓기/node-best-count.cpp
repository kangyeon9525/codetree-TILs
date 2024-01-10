#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> dp(n+1, 0);

    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        dp[u]++;
        dp[v]++;
    }

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (dp[i] == 1) cnt++;
    }
    cout << (cnt+1)/2 << "\n";
    return 0;
}