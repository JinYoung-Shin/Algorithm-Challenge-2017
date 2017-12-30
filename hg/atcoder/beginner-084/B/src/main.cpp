#include <bits/stdc++.h>

using namespace std;

void f() {
    cout << "No\n";
    exit(EXIT_SUCCESS);
}
int main() {
    int a, b;
    string str;
    cin >> a >> b;
    cin >> str;
    for (int i=0; i < a; i++) {
        char ch = str[i];
        if (ch >= '0' and ch <= '9') {
            
        } else {
            f();
        }
    }
    if (str[a] != '-') f();
    for (int i=a+1; i < a+b+1; i++) {
        char ch = str[i];
        if (ch >= '0' and ch <= '9') {
            
        } else {
            f();
        }
    }
    cout << "Yes\n";
    return 0;
}