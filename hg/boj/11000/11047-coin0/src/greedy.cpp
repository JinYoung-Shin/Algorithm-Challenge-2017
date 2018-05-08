#include <bits/stdc++.h>

using namespace std;

int val[10];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n ;i++){
        cin >> val[i];
    }
    int ans=0;
    for (int i=n-1; i >=0; i--) {
        ans += k/val[i];
        k %= val[i];
    }
    cout << ans << '\n';
    
}