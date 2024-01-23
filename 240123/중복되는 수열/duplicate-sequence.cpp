#include <iostream>
#include <string>

using namespace std;

// 변수 선언
int n;
string words[10000];

// Trie에 사용되는 노드를 정의합니다.
class TrieNode {
    public:
        TrieNode *children[10];
        bool is_end;
        TrieNode() {
            is_end = false;
            for(int i = 0; i < 10; i++)
                children[i] = nullptr;
        }
};

TrieNode *root = new TrieNode();

bool InsertWord(string s) {
    TrieNode *t = root;
    for(int i = 0; i < (int) s.size(); i++) {
        int index = s[i] - '0';
        if(t->children[index] == nullptr)
            t->children[index] = new TrieNode();
        else if(t->children[index]->is_end)
            return false;
        t = t->children[index];
    }
    t->is_end = true;
    for(int i = 0; i < 10; i++)
        if(t->children[i] != nullptr)
            return false;
    return true;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> words[i];
    for(int i = 0; i < n; i++)
        if(!InsertWord(words[i])) {
            cout << 0 << endl;
            return 0;
        }
    cout << 1 << endl;
    return 0;
}