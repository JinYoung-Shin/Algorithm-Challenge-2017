#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e6;
ll dp[5005];
int main() {
    string str;
    cin >> str;
    size_t l = str.length();
    dp[0] = 1;
    for (size_t i=0; i < l; i++) {
        char ch = str[i];
        if (ch != '0') {
            dp[i+1] += dp[i];    
            dp[i+1] %= mod;    
        }
            
        if (i < l-1) {
            char nc = str[i+1];
            if ((ch == '1' and nc >= '0' and nc <= '9') or (ch == '2' and nc <= '6' and nc >= '0')) {
                dp[i+2] += dp[i];
                dp[i+2] %= mod;
            }
        }

    }
    cout << dp[l] << endl;
	return 0;
}

