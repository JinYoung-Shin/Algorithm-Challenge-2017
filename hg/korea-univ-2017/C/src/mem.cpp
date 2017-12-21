#include <bits/stdc++.h>
using namespace std;

int a[10], b[10];
const int n = 9;
int main() {
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    for (int i=0; i < n; i++) {
        cin >> b[i];
    }
    int as = 0, bs = 0;
    for (int i=0;i < n; i++) {
        as += a[i];
        if (as > bs) {
            cout << "Yes\n";
            return 0;
        }
        bs += b[i];
        
    }
    cout << "No\n";
    return 0;
    
}