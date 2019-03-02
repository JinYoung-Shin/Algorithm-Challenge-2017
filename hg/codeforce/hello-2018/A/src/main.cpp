#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll n, m;
    ll a = 2;
    cin >> n >> m;
    while (n > 1 && a <= m) {
        n--;
        a *= 2;
    }
    if (a > m) {
        cout << m << endl;
        return 0;
    } else if (a == m) {
        cout << 0 << endl;
        return 0;
    } else {
        cout << (m % a) << endl;
        return 0;
    }
    
}