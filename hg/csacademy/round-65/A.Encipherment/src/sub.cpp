#include <bits/stdc++.h>

using namespace std;

char P[27];
int main() {
    string s;
    cin >> s;
    scanf("%s", P);
    for (size_t i=0; i < s.length(); i++) {
        char ch = s[i];
        char ret = P[s[i] - 'a'];
        putchar(ret);
    }
    return 0;
}