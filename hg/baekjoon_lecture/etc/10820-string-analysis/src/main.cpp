#include <bits/stdc++.h>
using namespace std;
void _(string &str) {
    int a,b,c,d;
    a=b=c=d=0;
    for (size_t i=0; i < str.size(); i++) {
        char ch = str[i];
        if (ch >= 'a' and ch <= 'z') a++;
        else if (ch >='A' and ch <= 'Z') b++;
        else if (ch >='0' and ch <= '9') c++;
        else if (ch == ' ') d++;
    }
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}
int main() {
    string str;
    while(true) {
        getline(cin, str);
        if (str == "") return 0;
        _(str);
        
        str = "";
    }
}