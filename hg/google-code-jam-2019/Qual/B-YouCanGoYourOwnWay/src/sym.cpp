#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t=1; t<=tc; t++) {
        int n; scanf("%d", &n);
        string s;
        cin >> s;
        printf("Case #%d: ", t);
        for (size_t i=0; i < s.length(); i++) {
            if (s[i] == 'S') putchar('E');
            else putchar('S');
        }
        putchar('\n');
    }
	return 0;
}

