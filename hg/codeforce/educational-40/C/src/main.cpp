#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1000000000LL;
ll arr[200005];
int main() {
    int n;
    cin >> n;
    ll prev;
    ll width = -1;
    
    scanf("%lld", &prev);
    arr[0] = prev;
    ll max_val = prev;
    
    for (int i=1; i < n; i++) {
        ll cur;
        scanf("%lld", &cur);
        arr[i] = cur;
        
        ll diff = abs(cur - prev);
        
        max_val = max(max_val, cur);
        
        if (diff != 1) {
            if (diff == 0) {
                cout << "NO\n"; return 0;
            }
            if (width == -1) {
                width = diff;
            } else if (width != diff) {
                cout << "NO\n"; return 0;
            }
        }
        prev = cur;
    }
    
    if (width == -1) {
        width = max_val;
    } else {
        for (int i=1; i < n; i++) {
            ll diff = abs(arr[i] - arr[i-1]);
            if (diff == 1) {
                ll l1 = (arr[i]-1) / width;
                ll l2 = (arr[i-1]-1) / width;
                if (l1 != l2) {
                    cout << "NO\n"; return 0;
                }
            }
        }
    }
    
    ll height = (max_val + width - 1) / width; // ceiling(max_val / width)
    
    
    if (width > mm || height > mm) {
        cout << "NO\n"; return 0;
    }
    cout << "YES\n";
    cout << height << ' ' << width << endl;
    return 0;
    
}

