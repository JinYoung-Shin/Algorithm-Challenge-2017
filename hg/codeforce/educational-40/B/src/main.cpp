#include <bits/stdc++.h>
using namespace std;

string str;

bool ok(int mid) {
    for (int i=0; i < mid; i++) {
        if (str[i] != str[mid+i])
            return false;
    }
    return true;
}
int main() {
    int n;
    
    cin >> n >> str;
    int ans = n;
    for (int mid = n / 2; mid > 0; mid--) {
        if (ok(mid)) {
            ans += 1 - mid;
            break;
        }
    }
    
    cout << ans << endl;
	return 0;
}

