#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll a, b;
    cin >> a >> b;
    while (a != 0 and b != 0) {
        if ( a >= 2 * b ) {
            ll number = a / (2*b);
            
            a -= number * 2 * b;
            continue;
        }
        if ( b >= 2 * a ) {
            ll number = b / (2*a);
            b -= number * 2 * a;
        } else {
            break;
        }
    }
    
    cout << a << ' ' << b << endl;
	return 0;
}

