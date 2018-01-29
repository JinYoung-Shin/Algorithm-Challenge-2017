#include <bits/stdc++.h>
using namespace std;

int cnt;
int a,b;
int next() {
    cnt++;
    if (cnt == 1 or cnt == 2) return 1;
    int tmp = a+b;
    a = b;
    b = tmp;
    return b;
}
int main() {
    int n;
    cin >> n;
    a=b=1;
    int hi = next();
    for (int i=1; i <= n; i++) {
        while(hi < i) {
            hi = next();
        }
        if (hi == i) {
            putchar('O');
            hi = next();
        } else {
            putchar('o');
        }
    }
    putchar('\n');
	return 0;
}

