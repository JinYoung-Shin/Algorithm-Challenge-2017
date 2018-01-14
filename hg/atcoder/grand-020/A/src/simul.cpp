#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if ( (b-a) & 1 ) {
        //홀수
        cout << "Borys\n";
    } else {
        cout << "Alice\n";
    }
	return 0;
}

