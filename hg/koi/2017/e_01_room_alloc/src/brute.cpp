#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, total;
    cin >> a >> b >> c >> total;
    
    int a_lim = total/a;
    int b_lim = total/b;
    int c_lim = total/c;
    for (int i=0; i <= c_lim; i++) {
        int cur = c * i;
        for (int j=0; j <= b_lim; j++) {
            int cur2 = cur + j*b;
            for (int k=0; k <= a_lim; k++) {
                int cur3 = cur2 + k*a;
                if (cur3 == total) {
                    cout << 1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << 0 << '\n';
	return 0;
}

