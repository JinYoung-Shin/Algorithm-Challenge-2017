#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    int limit = (int)sqrt(n);
    for (int i=2; i <= limit; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int gcd, lcm;
    cin >> gcd >> lcm;
    int k = lcm / gcd;
    int val = k;
    vector<int> factor;
    int divisor = 2;
    while(val > 1) {
        if (val % divisor == 0 and is_prime(divisor)) {
            int tmp = 1;
            while(val % divisor == 0) {
                val /= divisor;
                tmp *= divisor;
            };
            factor.push_back(tmp);
        }
        divisor++;
    }
    
    // for (size_t i=0; i < factor.size(); i++) {
    //     printf("%d\n", factor[i]);
    // }
    int sum = 987654321;
    int l, r;
    int sz = factor.size();
    for (int bitmask = 0; bitmask < (1<<sz); bitmask++) {
        int t1, t2;
        t1 = t2 = 1;
        for (int i=0; i < sz; i++) {
            if (bitmask & (1<<i)) {
                t1 *= factor[i];
            } else {
                t2 *= factor[i];
            }
        }
        // printf("%d %d\n", t1, t2);
        if (t1 + t2 < sum) {
            sum = t1 + t2;
            l = min(t1, t2);
            r = max(t1, t2);
        }
    }
    cout << (l*gcd) << ' ' << (r*gcd) << '\n';
    
  
	return 0;
}

