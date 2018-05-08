#include <bits/stdc++.h>
using namespace std;

int arr[102];
int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        int m;
        long long ans = 0;
        cin >> m;
        for (int i=0; i < m; i++) {
            cin >> arr[i];
        }
        for (int i=0; i < m-1; i++) {
            for (int j=i+1; j <m; j++) {
                ans += gcd(arr[i], arr[j]);
            }
        }
        cout << ans << '\n';
    }
	return 0;
}

