#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int arr[100005];
int main() {
    int t;
    int n;
    scanf("%d", &t);
    for (int tc=1; tc<=t; tc++) {
        scanf("%d", &n);
        for (int i=0; i < n; i++) {
            scanf("%d", arr+i);
        }
        
        sort(arr, arr+n, greater<int>());
        
        ll ans = 0;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            cnt++;
            if (cnt < 3) {
                ans += arr[i];
            } else {
                cnt = 0;
            }
            // printf("%d ", arr[i]);   
        }    
        printf("#%d %lld\n", tc, ans);
        // putchar('\n');
    }
    
    
	return 0;
}

