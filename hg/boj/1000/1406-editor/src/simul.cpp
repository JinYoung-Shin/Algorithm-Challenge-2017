#include <bits/stdc++.h>
using namespace std;

list<char> text;
typedef list<char>::iterator Ptr;
int main() {
    string str;
    cin >> str;
    for (size_t i=0; i < str.size(); i++) {
        text.push_back(str[i]);
    }
    Ptr cur = text.end();
    int n;
    cin >> n;
    while(n--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (cur != text.begin()) cur--;
        } else if (cmd == 'D') {
            if (cur != text.end()) cur++;
        } else if (cmd == 'B') {
            if (cur != text.begin()) {
                Ptr victim = cur;
                victim--;
                text.erase(victim);
            }
        } else if (cmd == 'P') {
            char val;
            cin >> val;
            text.emplace(cur, val);
        }
    }
    
    for(Ptr i = text.begin(); i != text.end(); i++) {
        cout << *i;
    }
    cout << '\n';
    return 0;
}