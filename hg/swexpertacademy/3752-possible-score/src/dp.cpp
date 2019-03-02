#include <bits/stdc++.h>
using namespace std;

bool dp[10001];
int arr[101];
int main() {
    int t;
    scanf("%d", &t);
    for (int c=1; c <= t; c++) {
        int n;
        scanf("%d", &n);
        for (int i=0; i <n; i++) {
            scanf("%d", arr+i);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for (int i=0; i < n; i++) {
            vector<int> next_avail;
            next_avail.clear();
            for (int j=0; j <= 10000; j++) {
                if (dp[j]) {
                    int next = j + arr[i];
                    next_avail.push_back(next);
                }
            }
            for (size_t j=0; j < next_avail.size(); j++) {
                int pos = next_avail[j];
                dp[pos] = true;
            }
        }
        int ans = 0;
        for (int i=0; i <= 10000; i++) {
            if (dp[i]) ans++;
        }
        printf("#%d %d\n", c, ans);
    }
	return 0;
}

