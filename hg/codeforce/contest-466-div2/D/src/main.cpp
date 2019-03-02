#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    vector<ll> arr;
    ll n;
    cin >> n;
    arr.reserve(n);
    ll l, r;
    l = -1e9;
    r = +1e9;
    
    for (int i=0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    int prev = 0;
    for (int i=0; i < n; i++) {
        int val;
        scanf("%1d", &val);
        if (val != prev) {
            if (prev == 1) { // 1 ~> 0
                ll next_r = min(arr[i], arr[i-1]);
                next_r = min(next_r, arr[i-2]);
                next_r = min(next_r, arr[i-3]);
                next_r = min(next_r, arr[i-4]);
                next_r -= 1;
                
                r = min(r, next_r);
            } else {
                ll next_l = max(arr[i], arr[i-1]);
                next_l = max(next_l, arr[i-2]);
                next_l = max(next_l, arr[i-3]);
                next_l = max(next_l, arr[i-4]);
                next_l += 1;
                
                l = max(l, next_l);
            }
            prev = val;
        }
    }
    

    cout << l << ' ' << r << endl;
	return 0;
}

