#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열 사이에 #을 삽입하여 홀수, 짝수 길이의 팰린드롬을 동일하게 다룸
string preprocessString(const string& s) {
    string result = "#";
    for (char c : s) {
        result += c;
        result += "#";
    }
    return result;
}

int longestPalindrome(string s) {
    s = preprocessString(s);
    int n = s.size();
    vector<int> P(n, 0); // P[i]는 i를 중심으로 하는 팰린드롬의 반지름 길이
    int C = 0, R = 0; // C는 현재까지 확인한 팰린드롬 중심, R은 그 팰린드롬의 오른쪽 끝 인덱스

    for (int i = 0; i < n; i++) {
        int mirror = 2 * C - i; // i를 중심으로 하는 팰린드롬의 미러(대칭점) 인덱스
        if (i < R) {
            P[i] = min(R - i, P[mirror]);
        }

        // 현재 i를 중심으로 확장
        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while (a < n && b >= 0 && s[a] == s[b]) {
            P[i]++;
            a++;
            b--;
        }

        // 현재 팰린드롬이 이전의 어떤 팰린드롬보다 오른쪽 끝이 더 멀리 갔다면 중심과 오른쪽 끝을 업데이트
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // P 배열에서 가장 큰 값이 팰린드롬의 반지름
    int maxRadius = *max_element(P.begin(), P.end());
    return maxRadius;
}

int main() {
    string input_str;
    cin >> input_str;

    int ans = longestPalindrome(input_str);

    cout << ans << endl;

    return 0;
}