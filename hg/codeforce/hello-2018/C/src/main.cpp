#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, l;

ll cost[31];
//cost[0] -> 1L
//cost[1] -> 2L
static int cnt;
inline ll get_liter(int i) {
    if (i == 0) return 1;
    else return (1 << i);
}

ll get_ans(const ll rest, const int idx) {
    cnt++;
    if (rest <= 0) return 0;
    //int idx = n-1;
    ll subtr = get_liter(idx);
    ll iter = rest / subtr;
    ll remain = rest - iter*subtr;

    ll ret = cost[idx]*iter + cost[idx];
    if (remain == 0) {
        ret -= cost[idx];
    }
    if (idx > 0) {
        ll ccc = get_ans(remain, idx-1);
        ret = min( ret, cost[idx] * iter + ccc );
        
        // ll ddd;
        // if (remain == rest) {
        //     ddd = ccc;
        // }
        // ddd = get_ans(rest, idx-1);
        // ret = min( ret, ddd );
    }
    return ret;
}

int main() {
    
    cin >> n >> l;
    cin >> cost[0];
    ll prev = cost[0];
    for (int i=1; i < n; i++) {
        prev *= 2;
        cin >> cost[i];
        prev = cost[i] = min(cost[i], prev);
    }
    
    // DUMP
    // for(int i=0; i < n; i++) {
    //     cout << cost[i] << ' ';
    // }
    // cout << endl;
    
    cout << get_ans(l, n-1) << '\n';
    // cout << cnt << endl;
    return 0;
}