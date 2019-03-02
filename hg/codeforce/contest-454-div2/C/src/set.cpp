#include <bits/stdc++.h>
using namespace std;

bool chk[26];
// false => 이놈이 범인일 수도 있다.
// true =>  명백히 결백하다.
bool is_unique() {
    int cnt = 0;
    for (int i=0; i < 26; i++) {
        if(chk[i] == false) {
            cnt++;
        }
    }
    return (cnt == 1);
}
int main() {
    int n;
    cin >> n;
    int ans = 0;
    bool flag = false;
    for (int i=0; i < n-1; i++) {
        char cmd;
        string word;
        cin >> cmd >> word;
        if(flag) {
            if (cmd == '!' || cmd == '?')
                ans++;
            continue;
        }
        if (cmd == '!') {
            set<char> hi;
            for(size_t j=0; j < word.length(); j++) {
                char ch = word[j];
                hi.insert(ch);
            }
            for (int j=0; j<26;j++) {
                char ch = j + 'a';
                if( hi.find(ch) == hi.end() ) {
                    chk[j] = true;
                }
            }
        } else if (cmd == '.') {
            for(size_t j=0; j < word.length(); j++) {
                char ch = word[j];
                int idx = ch - 'a';
                chk[idx] = true;
            }
        } else if (cmd == '?') {
            char ch = word[0];
            int idx = ch - 'a';
            chk[idx] = true;
        }
        flag = is_unique();
    }
    cout << ans << '\n';
    return 0;
}