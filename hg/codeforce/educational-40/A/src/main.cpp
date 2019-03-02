#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    int ans = str.length();
    char prev = str[0];
    for (size_t i=1; i < str.length(); i++) {
        char& cur = str[i];
        if ((prev == 'R' && cur == 'U') || (prev == 'U' && cur == 'R')) {
            ans--;
            prev = '-';
        } else {
            prev = cur;
        }
    }
    
    cout << ans << endl;
	return 0;
}

