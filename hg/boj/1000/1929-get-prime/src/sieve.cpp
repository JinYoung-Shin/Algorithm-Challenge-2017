#include <bits/stdc++.h>
using namespace std;

bool isp[1000005];
bool p(int n) {
    if (n <= 1) return false;
    int l = (int)sqrt(n);
    for (int i=2; i <=l; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int m, n;
    cin >> m >> n;

    isp[0] = isp[1] = true;
    
    int ll = (int)sqrt(n);
    for (int i=2; i <= ll; i++) {
        if (isp[i] == false && p(i)) {
            int v = i*2;
            while (v <= n) {
                isp[v] = true;
                v += i;
            }
        }
    }
    
    for (int i=m; i <= n; i++) {
        if (isp[i] == false) {
            cout << i << '\n';
        }
    }
    
	return 0;
}

