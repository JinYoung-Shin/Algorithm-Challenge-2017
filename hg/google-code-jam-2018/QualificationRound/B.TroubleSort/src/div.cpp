#include <bits/stdc++.h>
using namespace std;

int arr1[100005]; //even. arr1[i] => arr[i*2];
int arr2[100005]; //odd. arr2[i] => arr[i*2+1];
int main() {
    int t;
    
    cin >> t;
    for (int tc=1; tc <= t ; tc++) {
        int n;
        cin >> n;
        int len1 = (n+1)/2;
        int len2 = n/2;
        for (int i=0; i < n; i++) {
            if (i & 1) {
                scanf("%d", &arr2[i/2]);
            } else {
                scanf("%d", &arr1[i/2]);
            }
        }
        sort(arr1, arr1+len1);
        sort(arr2, arr2+len2);
        
        int ans = -1;
        int prev = arr1[0];
        for (int i=1; i < n; i++) {
            int curr; 
            if (i & 1) {
                curr = arr2[i/2];
            } else {
                curr = arr1[i/2];
            }
            if (prev > curr) {
                ans = i-1;
                break;
            }
            prev = curr;
        }
        
        printf("Case #%d: ", tc);
        if (ans != -1) {
            cout << ans << '\n';
        } else {
            cout << "OK\n";
        }
    }
    
	return 0;
}

