#include <bits/stdc++.h>
using namespace std;

int sum[210]; // summation from 0 to i
int cnt[210];
int get_sum(int i) {
    if (i <= 0) return 0;
    else return sum[i];
}
int main() {
    int n, d;
    int ans = 987654321;
    cin >> n >> d;
    for (int i=0; i< n; i++) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    for (int i=1; i <= 200; i++) {
        sum[i] = sum[i-1] + cnt[i];
    }
    
    for (int i=-d; i <= 200 - d; i++) {
        // range (i ~ i+d)
        int range = get_sum(i+d) - get_sum(i-1);
        ans = min(ans, n - range);
    }
    cout << ans << endl;
	return 0;
}

