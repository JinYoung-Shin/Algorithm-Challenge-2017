#include <bits/stdc++.h>
using namespace std;

void fail() { cout << "No\n"; exit(EXIT_SUCCESS); }
inline int abs(int a) {
    if (a<0) return -a;
    return a;
}
int x, y, t;
int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        int tt, tx, ty;
        cin >> tt >> tx >> ty;
        int dist = abs(tx-x) + abs(ty-y); //manhattan distance
        int t_diff = tt - t;
        t = tt;
        x = tx;
        y = ty;
        if (dist > t_diff) fail();
        if ( (t_diff - dist) & 1 ) fail();
    }
    
    cout << "Yes\n";
	return 0;
}

