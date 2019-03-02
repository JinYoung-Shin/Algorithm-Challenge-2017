#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, M, D; // 캔디수, 사람수, x최대값, 최대 도는회수

int main() {
    
    cin >> n >> k >> M >> D;

    ll ans = 0;
    for (int d=1; d <= D; d++) {
        ll maxX = M;
        maxX = min( n / (k*(d-1) + 1), maxX);    
        
        if (maxX == 0) continue;
        
        ll realD = (n/maxX + k - 1) / k;
        if (realD != d)  continue;
        
        ans = max(ans, d * maxX);
    }
    
    
    
    cout << ans << endl;
	return 0;
}

