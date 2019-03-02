#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;//길이, tap갯수
        cin >> n >> k;
        vector<int> arr;
        arr.clear();
        for (int i=0; i < k; i++) {
            int idx;
            cin >> idx;
            arr.push_back(idx);
        }
        int ans = 0;
        ans = max(ans, arr[0]);
        ans = max(ans, n - arr[arr.size() - 1] + 1);
        int prev = arr[0];
        for (int i=1; i < k; i++) {
            int dist = arr[i] - prev;
            ans = max(ans, dist/2+1);
            prev = arr[i];
        }
        cout << ans << '\n';
    }
	return 0;
}

