#include <bits/stdc++.h>
using namespace std;

inline bool can_climb(int v, int a) {
    return v <= a;
}
inline bool do_like(int v, int a) {
    return ((2*v) >= a);
}
int main() {
    int v1, v2, v3, vm;
    cin >> v1 >> v2 >> v3 >> vm;
    for (int i=1; i <= 198; i++) {//smallest
        for (int j=i+1; j <= 199; j++) {//middle
            for (int k=j+1; k <= 200; k++) {//largest
                if (can_climb(v1, k) && do_like(v1, k) && can_climb(v2, j) && do_like(v2, j) && can_climb(v3, i) && do_like(v3, i)) {
                    if (can_climb(vm, i) && do_like(vm, i) && !do_like(vm, j) && !do_like(vm, k)) {
                        cout << k << '\n' << j << '\n' << i << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}