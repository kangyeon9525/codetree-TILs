#include <iostream>
#include <string>

using namespace std;

// 좌우대칭 여부를 확인하는 함수
bool IsPalindrome(const string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// 주어진 문자열에서 가장 긴 좌우대칭인 부분 문자열의 길이를 찾는 함수
int LongestPalindromeLength(const string& str) {
    int maxLength = 0;

    for (int start = 0; start < str.size(); start++) {
        for (int end = start; end < str.size(); end++) {
            if (IsPalindrome(str, start, end)) {
                maxLength = max(maxLength, end - start + 1);
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