#include <bits/stdc++.h>
using namespace std;

inline int abs(int n) {
    if (n<0) return -n;
    return n;
}
int main() {
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    
    int ans = 0;
    
    if (l > 1) {
        if (r < n) {
            //both side
            if (pos < l) {
                ans += 2 + abs(r-pos);
            } else if (pos > r) {
                ans += 2 + abs(pos-l);
            } else {
                //middle case
                ans += 2 + abs(r-l) + min(abs(pos-l), abs(r-pos));
            }
        } else {
            ans += 1 + abs(pos-l);
            //only left side
        }
    } else if (r < n) {
        //only right side
        ans += 1 + abs(r-pos);
    }
    

    cout << ans << endl;
	return 0;
}

