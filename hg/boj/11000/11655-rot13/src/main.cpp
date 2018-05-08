#include <bits/stdc++.h>
using namespace std;

inline bool num(char ch) { return ch >= '0' and ch <= '9'; }
inline bool upper(char ch) { return ch >= 'A' and ch <= 'Z'; }
inline bool lower(char ch) { return ch >='a' and ch <='z'; }
char rot13(char ch) {
    if (lower(ch)) {
        return (ch - 'a' + 13) % 26 + 'a';
    }
    if (upper(ch)) {
        return (ch - 'A' + 13) % 26 + 'A';
    }
    return ch;
}
int main() {
    string str;
    getline(cin, str);
    
    // cout << str;
    for (size_t i=0; i < str.length(); i++) {
        cout << rot13(str[i]);
    }
    cout << '\n';
    return 0;
}