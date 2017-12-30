#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int ans = 0;
    for (size_t i=0; i < str.length(); i++) {
        char ch = str[i];
        if (ch >= '0' and ch <= '9') {
            int val = ch - '0';
            if (val & 1) {
                ans++;
            }
        } else {
            if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}