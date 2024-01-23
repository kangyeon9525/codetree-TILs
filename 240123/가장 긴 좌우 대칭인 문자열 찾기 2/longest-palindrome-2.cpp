#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 주어진 문자열에서 가장 긴 좌우대칭인 부분 문자열의 길이를 찾는 함수
int LongestPalindromeLength(const string& str) {
    int n = str.size();
    int maxLength = 0;

    // dp[i][j]는 문자열 str[i..j]가 좌우대칭인지 여부를 나타냄
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // 길이가 1인 경우 모두 좌우대칭
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        maxLength = 1;
    }

    // 길이가 2인 경우 좌우대칭일 때만 true
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = true;
            maxLength = 2;
        }
    }

    // 길이가 3 이상인 경우를 확인
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // 현재 부분 문자열의 끝 인덱스
            // 현재 부분 문자열의 양 끝이 같고 그 사이의 문자열도 좌우대칭일 때
            if (str[i] == str[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                maxLength = len;
            }
        }
    }

    return maxLength;
}

int main() {
    string input_str;
    cin >> input_str;

    int ans = LongestPalindromeLength(input_str);

    cout << ans << endl;

    return 0;
}