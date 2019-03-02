#include <bits/stdc++.h>
using namespace std;
int arr[5001];
int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int ans = 1;
    int cnt = 1;
    int val = arr[0];
    for (int i=1; i < n; i++) {
        if (arr[i] == val) {
            cnt++;
            ans = max(ans, cnt);
        } else {
            val = arr[i];
            cnt = 1;
        }
    }
    cout << ans << '\n';
}