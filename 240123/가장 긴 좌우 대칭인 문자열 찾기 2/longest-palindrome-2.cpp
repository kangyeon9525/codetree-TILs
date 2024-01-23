#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 주어진 문자열에서 가장 긴 좌우대칭인 부분 문자열의 길이를 찾는 함수
int LongestPalindromeLength(const string& str) {
    int n = str.size();
    int maxLength = 0;

    // 중심을 기준으로 확장하면서 좌우대칭인지 확인하는 함수
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && str[left] == str[right]) {
            int currentLength = right - left + 1;
            maxLength = max(maxLength, currentLength);
            left--;
            right++;
        }
    };

    for (int i = 0; i < n; i++) {
        // 길이가 홀수인 경우
        expandAroundCenter(i, i);
        // 길이가 짝수인 경우
        expandAroundCenter(i, i + 1);
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