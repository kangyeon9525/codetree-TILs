#include <iostream>
#include <string>

#define MAX_M 100000

using namespace std;

// 변수 선언
int n, m;
string text, pattern;

// failure function입니다.
int f[MAX_M + 1];

int main() {
    cin >> text >> pattern;

    n = (int) text.size();
    m = (int) pattern.size();

    // 구현의 편의를 위해 맨 앞에 #을 붙여
    // 문자열을 1번지부터 사용합니다.
    text = "#" + text;
    pattern = "#" + pattern;

    // failure function값을 먼저 계산합니다.
    f[0] = -1;
    for(int i = 1; i <= m; i++) {
        int j = f[i - 1];
        while(j >= 0 && pattern[j + 1] != pattern[i])
            j = f[j];
        f[i] = j + 1;
    }
    
    // 한 문자씩 비교하며 패턴 문자열과 일치하게 되는 순간을 구합니다.
    int j = 0;
    int count = 0;
    for(int i = 1; i <= n; i++) {
        while(j >= 0 && pattern[j + 1] != text[i]) 
            j = f[j];
        j++;
        
        // j가 m이 되면 전부 일치했다는 뜻이므로 
        // 답을 갱신해주고 다시 그 다음 후보로 넘어갑니다.
        if(j == m) {
            count++;
            j = f[j];
        }
    }
    
    cout << count << endl;

    return 0;
}