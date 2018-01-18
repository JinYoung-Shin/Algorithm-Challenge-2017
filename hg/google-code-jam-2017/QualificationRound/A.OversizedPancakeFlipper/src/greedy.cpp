#include <bits/stdc++.h>
using namespace std;

int solve(string& str, int k) {
    int ans = 0;
    int limit = str.length() - k;
    for (int i=0; i <= limit; i++) {
        // cout << str.substr(i, k) << endl;
        char ch = str[i];
        if (ch == '-') {
            ans++;
            for (int j=i; j < i+k; j++) {
                if (str[j] == '-') {
                    str[j] = '+';
                } else {
                    str[j] = '-';
                }
            }    
        }
        
    }
    for (int i=limit+1; i < str.length(); i++) {
        if (str[i] == '-') {
            return -1;
        }
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    for (int i=1; i <= t; i++) {
        string str;
        int k;
        cin >> str;
        cin >> k;
        int ans = solve(str, k);
        printf("Case #%d: ", i);
        if (ans == -1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ans << '\n';
        }
        
    }
	return 0;
}

