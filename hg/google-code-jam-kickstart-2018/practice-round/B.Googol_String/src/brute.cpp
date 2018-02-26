#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool preset[] = {false, false, true, false, false, true, true};
ll get_boundary(ll val) {
    ll ret = 0;
    while (ret < val) {
        ret <<= 1;
        ret += 1;
    }
    
    // ll mid = max(ret/2, 1LL);
    // ll mid1 = min(mid+1, ret);
    // ll mid2 = min(mid+2, ret);
    // printf("%lld ~ %lld / %lld / %lld ~ %lld\n", 1LL, mid, mid1, mid2, ret);
    return ret;
}
bool get(ll index) {
    ll right_border = get_boundary(index);
    ll left_border = max(right_border/2, 1LL);
    ll median = min(left_border+1, right_border);
    ll median2 = min(left_border+2, right_border);
    
    if (index <= 7) {
        return preset[index-1];
    }
    
    if (index >= 1LL and index <= left_border) {
        cout << "ERROR!" << '\n';
        return 0;
    } else if (index == median) {
        return false;
    } else if (index >= median2 and index <= right_border) {
        return !get(right_border - index + 1);
    } else {
        cout << "ERROR!" <<'\n';
        return 0;
    }
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        ll tmp;
        cin >> tmp;
        cout << get(tmp) << '\n';
    }
	return 0;
}

