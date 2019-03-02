#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, a , b;
    cin >> m >> n;
    a= m;
    b= n;
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    int gcd = a;
    int lcm = m * n / a;
    cout << gcd << '\n' << lcm << endl;
    
	return 0;
}

