#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;

#define NUM_CHAR 26
#define MOD 1000000007

ll dp[1001][1001][NUM_CHAR];
bool chk[1001][1001][NUM_CHAR];
string str;

inline int get(int l, int r, char sigma) {

    if (l > r) return 0;
    if (l == r) {
        if (str[l] == sigma) return 1;
        else return 0;
    }
    if (chk[l][r][sigma-'a']) return dp[l][r][sigma-'a'];
    
    ll ret = 0;
    int nl = l+1;
    int nr = r-1;
    
    if (str[l] != sigma || str[r] != sigma) {
        ret = get(nl, r, sigma) + get(l, nr, sigma) - get(nl, nr, sigma);
        ret %= MOD;
    } else { // str[l] == sigma && str[r] == sigma !case!
        for (int i=0; i < NUM_CHAR; i++) {
            ret += get(nl, nr, i + 'a');
            ret %= MOD;
        }
        ret += 2;
    }
    chk[l][r][sigma-'a'] = true;
    return dp[l][r][sigma-'a'] = ret;
}
int main() {
    
    cin >> str;
    int len = str.length()-1;
    ll ans = 0;
    for (int i=0; i < NUM_CHAR; i++) {
        ans += get(0, len, i+'a');
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
    
}
