#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int ldp[100005];
int rdp[100005];
int main() {
    int n;
    cin >> n;
    for (int i=1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (int i=1; i <= n; i++) {
        if (ldp[i-1] + arr[i] > arr[i]) {
            ldp[i] = ldp[i-1] + arr[i];
        } else {
            ldp[i] = arr[i];
        }
    }
    for (int i=n; i> 0; i--) {
        if (rdp[i+1] + arr[i] > arr[i]) {
            rdp[i] = rdp[i+1] + arr[i];
        } else {
            rdp[i] = arr[i];
        }
    }
    int ans = ldp[1];
    for (int i=1; i <= n; i++) {
        ans = max(ans, ldp[i]);
        ans = max(ans, rdp[i]);
        ans = max(ans, ldp[i-1] + rdp[i+1]);
    }
    cout << ans << endl;

    
	return 0;
}

