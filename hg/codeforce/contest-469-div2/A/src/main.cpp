#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r, a;
    cin >> l >> r >> a;
    if (l > r) {
        int diff = l - r;
        int complement = min(diff, a);
        a -= complement;
        r += complement;
    } else if (l < r) {
        int diff = r - l;
        int complement = min(diff, a);
        a -= complement;
        l += complement;
    }
    
    if ( a > 0 ) {
        int half = a/2;
        l += half;
        r += half;
        a -= half;
        a -= half;
    }
    // cout << l << ' ' << r << ' ' << a << endl;
    cout << (min(l, r) * 2) << endl;
	return 0;
}

