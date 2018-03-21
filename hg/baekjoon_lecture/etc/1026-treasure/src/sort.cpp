#include <bits/stdc++.h>
using namespace std;

int a[100];
int b[100];
int main() {
    int n;
    cin >> n;
    for (int i=0;i < n; i++) {
        cin >> a[i];
    }
    for (int i=0;i < n; i++) {
        cin >> b[i];
    }
    
    sort(a, a+n);
    sort(b, b+n);
    int ans = 0;
    for (int i=0; i < n; i++) {
        ans += a[i] * b[n-i-1];
    }
    cout << ans << endl;
	return 0;
}

