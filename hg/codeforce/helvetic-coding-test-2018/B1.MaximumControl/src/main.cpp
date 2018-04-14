#include <bits/stdc++.h>
using namespace std;

int cnt[1001];
int main() {
    int n;
    cin >> n;
    for (int i=0; i <n-1; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    int ans = 0;
    for (int i=0; i <= 1000; i++) {
        if (cnt[i] == 1) ans++;
    }
    cout << ans << endl;
	return 0;
}

