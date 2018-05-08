#include <bits/stdc++.h>
using namespace std;


bool check(string& str) {
    stack<bool> pda;
    for (size_t i=0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '(') {
            pda.push(true);
        } else {
            if (pda.empty()) {
                return false;
            }
            pda.pop();
        }
    }
    return pda.empty();
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        cout << (check(str) ? "YES" : "NO") << '\n';
    }
    return 0;
}