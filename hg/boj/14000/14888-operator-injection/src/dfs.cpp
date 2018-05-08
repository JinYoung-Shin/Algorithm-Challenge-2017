#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
int arr[12];
int n;

//returns (min, max) value
pll dfs(ll lval, int index, int plus, int minus, int mult, int div) {
    if (index >= n) return make_pair(lval, lval);
    ll rmin = 9876543210000LL;
    ll rmax = -9876543210000LL;
    
    ll rval = (ll)arr[index];
    if (plus > 0) {
        pll ret = dfs(lval + rval, index+1, plus-1, minus, mult, div);
        rmin = min(rmin, ret.first);
        rmax = max(rmax, ret.second);
    }
    if (minus > 0) {
        pll ret = dfs(lval - rval, index+1, plus, minus-1, mult, div);
        rmin = min(rmin, ret.first);
        rmax = max(rmax, ret.second);
    }
    if (mult > 0) {
        pll ret = dfs(lval * rval, index+1, plus, minus, mult-1, div);
        rmin = min(rmin, ret.first);
        rmax = max(rmax, ret.second);
    }
    if (div > 0) {
        pll ret = dfs(lval / rval, index+1, plus, minus, mult, div-1);
        rmin = min(rmin, ret.first);
        rmax = max(rmax, ret.second);
    }
    
    return make_pair(rmin, rmax);
}
int main() {
    
    cin >> n;
    for (int i=0; i <n; i++) {
        cin >> arr[i];
    }
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    pll ans = dfs(arr[0], 1, a, b, c, d);
    cout << ans.second << '\n' << ans.first << endl;
	return 0;
}

