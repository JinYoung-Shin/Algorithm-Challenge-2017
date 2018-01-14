#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> arr;
int k;
void fail() {
    // cout << "failed T.T" << endl;
    cout << -1 << '\n';
    exit(EXIT_SUCCESS);
}
bool ok(int x) {
    for (int i=0; i< k; i++) {
        if (x >= arr[i]) {
            x -= x%arr[i];
        } else {
            return false;
        }
         
    }
    return x == 2;
}
int main() {
    
    ll min_range = 0;
    ll max_range = 2;
    cin >> k;
    arr.reserve(k);
    for (int i=0; i < k; i++) {
        ll tmp;
        cin >> tmp;
        max_range += max(tmp-1, 0LL);
        min_range = max(min_range, tmp);
        arr.push_back(tmp);
        
    }
    if (min_range > max_range) fail();
    
    ll min_ans, max_ans;
    min_ans = -1;
    for (ll x=min_range; x <= max_range; x++) {
        if (ok(x)) {
            if (min_ans == -1) {
                min_ans = max_ans = x;
            }
            max_ans = x;
        }
    }
    if (min_ans == -1) fail();
    cout << min_ans << ' ' << max_ans << endl;
    return 0;
    
}

