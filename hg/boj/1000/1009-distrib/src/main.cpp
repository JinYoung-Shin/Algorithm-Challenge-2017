#include <iostream>
#include <cstdio>

using namespace std;

#define MOD 10
int bin_split(int a, int b) {
    if (b == 1) return a % MOD;
    if (b == 0) return 1;
    if (b & 1) {
        return (bin_split(a, b-1) * a) % MOD;
    } else {
        int half = bin_split(a, b/2);
        return half * half % MOD;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int val = bin_split(a, b);
        if (val) {
            cout << val;
        } else {
            cout << 10;
        }
        cout << '\n';
    }
    return 0;
}