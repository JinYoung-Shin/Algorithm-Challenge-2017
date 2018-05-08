#include <bits/stdc++.h>
using namespace std;

bool is_prime(int val) {
    if (val == 1) return false;
    double limit = sqrt(val);
    int floored = (int)limit;
    for(int i=2; i <= floored; i++) {
        if (val % i == 0) return false;
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    int min_val = -1;
    for (int i=n; i<=m; i++) {
        if(is_prime(i)) {
            if (min_val == -1) min_val = i;
            sum += i;
        }
    }
    if (min_val == -1) {
        cout << min_val << '\n';
    } else {
        cout << sum << '\n' << min_val << '\n';    
    }
    
    return 0;
}