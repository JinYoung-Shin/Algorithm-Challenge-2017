#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, M, D; // 캔디수, 사람수, x최대값, 최대 도는회수
ll get_val(ll x) { //x로 나누었을때 A가 받게 되는 사탕 양
    // ll rot = n / x; //도는 양
    // ll times = (rot + k - 1) / k; //받는 회수
    ll times = (n/x + k - 1) / k;
    ll val = times * x;
    return val;
}
inline ll get_times(ll x) {
    return (n/x + k - 1) / k;
}
ll get_max_x(ll l, ll r, ll times) { //times번 받는 경우 중 가장 큰 x값을 구한다.
    while(l < r) {
        ll m = (l+r)/2;
        ll t = get_times(m);
        if (t >= times) {
            l = m+1;
        } else if (t < times) {
            r = m-1;
        } else if (t == times) {
            l = m;
        }
    }
    ll t = get_times(l);
    if (t > times) {
        l++;
    } else if (t < times) {
        l--;
    }
    return l;
}
int main() {
    
    cin >> n >> k >> M >> D;
    
    ll min_x = (n + k*D - 1) / (k*D);
    

    ll ans = get_val(M);
    

    ll cur_times = get_times(M); // 처음에는 제일 적게 받는다.
    ll max_times = get_times(min_x); //가장 여러번 받는 경우 받는 회수
    // printf("Times %Ld ~ %Ld\n", cur_times, max_times);
    for (ll t = cur_times; t <= max_times; t++) {
        ll xx = get_max_x(min_x, D, t);
        // printf("%Ld번 받을때 x=%Ld\n", t, xx);
            ll val = get_val(xx);
            ans = max(ans, val);    
        
    }
    cout << ans << endl;
	return 0;
}

