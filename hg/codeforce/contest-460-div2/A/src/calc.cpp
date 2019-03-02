#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
int main() {
    int n, k;
    cin >> n >> k;
    ld price = 9876546312;
    int aa, bb;
    for (int i=0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (price > ((ld)a)/b ) {
            price = ((ld)a)/b;
            aa = a;
            bb = b;
        }
    }
    ld ans = ((ld)(aa*k)) / bb;
    printf("%.12Lf\n", ans);
	return 0;
}

