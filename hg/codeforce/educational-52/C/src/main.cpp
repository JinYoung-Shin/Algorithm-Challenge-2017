#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define CNT 200005
int H[CNT];

int main() {
    int n, k;
    int low = CNT;
    int high = 0;
    cin >> n >> k;
    for (int i=0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        H[0]++;
        H[tmp]--;
        low = min(low, tmp);
        high = max(high, tmp);
    }

    for (int i=1; i <= high; i++) {
        H[i] = H[i-1] + H[i];
    }
    
    int cut = 0;
    int ans = 0;
    for (int i=high; i >= low; i--) {
        cut += H[i];
        if (cut > k) {
            ans++;
            cut = H[i];
        }
    }
    if (cut > 0) ans++;
    cout << ans << endl;
    
	return 0;
}

