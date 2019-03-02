#include <bits/stdc++.h>
using namespace std;

char str[105];
int main() {
    int n, m;
    cin >> n >> m;
    scanf("%s", str+1);
    for (int i=0;i <m; i++) {
        int l, r;
        char c1, c2;
        cin >> l >> r >> c1 >> c2;
        for (int j=l; j<=r; j++) {
            if (str[j] == c1) {
                str[j] = c2;
            }
        }
    }
    printf("%s\n", str+1);
    return 0;
}