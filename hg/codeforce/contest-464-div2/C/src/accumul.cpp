#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[100005];
ll sum[100005];

inline ll get_range(int s, int f) {
    return sum[f] - sum[s-1];
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
    }
    
    int s, f;
    cin >> s >> f;
    int ans = 0;
    ll mx = -1;
    for (int i=1; i <= n; i++) {
        int start = s - i + 1;
        int end = f - i;
        
        if (start < 1) {
            start += n;
            end += n;
        }
        
        ll v;
        if (end <= n) {
            v = get_range(start, end);
        } else {
            v = sum[n] - get_range(end-n+1, start-1);
        }
        
        if (mx < v) {
            mx = v;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}