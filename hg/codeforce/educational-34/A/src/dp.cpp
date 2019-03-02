#include <bits/stdc++.h>
using namespace std;

bool chk[101];

void dd(int start) {
    if (start > 100) return;
    if (chk[start]) return;
    chk[start] = true;
    dd(start + 3);
    dd(start + 7);
}
int main() {
    dd(0);
    int n;
    cin >> n;
    while(n--) {
        int tmp;
        cin >> tmp;
        if (chk[tmp]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}