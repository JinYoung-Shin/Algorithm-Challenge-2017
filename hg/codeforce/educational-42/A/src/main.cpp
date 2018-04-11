#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll s[200005];
int main() {
    
    int n;
    scanf("%d", &n);
    for (int i=1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        s[i] = s[i-1] + val;
    }
    
    // cout << s[n] << endl;
    ll half = (s[n] & 1) ? (s[n]/2+1) : (s[n]/2);
    for (int i=1; i <=n ;i++) {
        if (s[i] >= half) {
            cout << i << endl;
            return 0;
        }
    }
	return 0;
}

