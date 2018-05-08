#include <bits/stdc++.h>
using namespace std;

int arr[10005];
int main() {
    int n, m;
    cin >> n >> m;
    int l = 0, r = 0;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }
    int s = arr[0];
    int ans = 0;
    while (r < n) {
        if (s == m) {
            ans++;
            s -= arr[l];
            l++;
        } else if (s > m) {
            s -= arr[l];
            l++;
        } else if (s < m) {
            r++;
            s += arr[r];
        }
    }
    cout << ans << endl;
	return 0;
}

