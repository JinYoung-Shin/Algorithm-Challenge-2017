#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string str;
    cin >> n >> k;
    cin >> str;
    set<char> ss;
    for(size_t i=0; i< str.size(); i++) {
        ss.insert(str[i]);
    }
    char first, last;
    first = *ss.begin();
    auto it = ss.end();
    last = *(--it);
    
    if (n < k) {
        cout << str;
        for (int i=n; i < k; i++) {
            cout << first;
        }
        cout << endl;
        return 0;
    }
    
    if (n > k) {
        str = str.substr(0, k);
    }
    size_t pos = str.size() - 1;
    while(str[pos] == last) {
        pos--;
    }
    cout << str.substr(0, pos);
    auto it2 = ss.find(str[pos]);
    cout << *(++it2);
    
    for (int i=pos+1; i < k;i++) {
        cout << first;
    }

    cout << endl;
    
    
	return 0;
}

