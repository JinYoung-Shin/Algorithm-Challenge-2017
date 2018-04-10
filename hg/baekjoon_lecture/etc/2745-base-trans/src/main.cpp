#include <bits/stdc++.h>
using namespace std;

int char2val(char c) {
    if (c >= '0' and c <= '9') {
        return c - '0';
    } else if (c >= 'A' and c <='Z') {
        return c - 'A' + 10;
    }
    exit(EXIT_FAILURE);
    return 1;
}
int main() {
    string n;
    int b;
    cin >> n >> b;
    int ans = 0;
    int base = 1;
    for (int i=n.length()-1; i >=0; i--) {
        ans += char2val(n[i]) * base;
        base *= b;
    }
    cout << ans << endl;
	return 0;
}

