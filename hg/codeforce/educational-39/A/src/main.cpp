#include <bits/stdc++.h>
using namespace std;

inline int abs(int n) {
    if (n < 0) return -n;
    return n;
}
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i=0; i <n; i++) {
        int tmp;
        cin >> tmp;
        ans += abs(tmp);
    }
    
    cout << ans << endl;
	return 0;
}

