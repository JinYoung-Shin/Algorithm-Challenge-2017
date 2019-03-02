#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; string str;
    cin >> n >> str;
    char prev = str[0];
    for (int i=1; i < n; i++) {
        auto& cur = str[i];
        if (prev != cur) {
            cout << "YES\n";
            cout << prev << cur << endl;
            return 0;
        }
        prev = cur;
    }
    
    cout << "NO\n";
	return 0;
}

