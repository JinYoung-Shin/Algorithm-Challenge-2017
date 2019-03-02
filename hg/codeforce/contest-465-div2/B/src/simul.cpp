#include <bits/stdc++.h>
using namespace std;

#define POS 1 // y>x
#define NEG 0 // y<x
#define UND -1

int main() {
    int n;
    string seq;
    cin >> n;
    cin >> seq;
    int pos = UND;
    int x, y;
    x = y = 0;
    int ans = 0;
    for (int i=0; i < n; i++) {
        char ch = seq[i];
        if (ch == 'U') y++;
        else if (ch == 'D') y--;
        else if (ch == 'L') x--;
        else if (ch == 'R') x++;
        
        if (x != y) {
            if (pos == POS and y<x) {
                pos = NEG;
                ans++;
            } else if (pos == NEG and y>x) {
                pos = POS;
                ans++;
            } else if (pos == UND) {
                if (y<x) pos = NEG;
                else pos=POS;
            }
        }
    }
    cout << ans << '\n';
	return 0;
}

