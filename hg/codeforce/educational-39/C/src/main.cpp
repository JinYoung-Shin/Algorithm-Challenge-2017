#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int l = str.length();
    vector<char> arr;
    arr.reserve(l);
    char current = 0;
    for (int i=0; i < l; i++) {
        char ch = str[i];
        char val = ch - 'a';
        if (current <= 25 and val <= current) {
            char cc = current + 'a';
            // cout << cc;
            arr.push_back(cc);
            current++;
        } else {
            arr.push_back(ch);
            // cout << ch;
        }
    }
    if (current <= 25) {
        cout << -1 << endl;
        return 0;
    } 
    
    for (int i=0; i < l; i++) {
        putchar(arr[i]);
    }
    cout << endl;
	return 0;
}

