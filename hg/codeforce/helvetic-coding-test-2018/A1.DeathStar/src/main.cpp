#include <bits/stdc++.h>
using namespace std;

bool m1[11][11];
bool m2[11][11];
int n;

bool ok(int sx, int sy, int dx, int dy, bool mode) {
    int x = sx;
    int y = sy;
    
    for (int i=0; i < n; i++) {
        y = sy;
        for (int j=0; j < n; j++) {
            if (mode) {
                if (m1[i][j] != m2[x][y]) return false;    
            } else {
                if (m1[i][j] != m2[y][x]) return false;
            }
            y += dy;
        }   
        x += dx;
    }
    return true;
}
int main() {
    
    bool ans = 0;
    cin >> n;
    for (int i=0; i < n; i++) {
        string str;
        cin >> str;
        for (int j=0; j < n; j++) {
            char c = str[j];
            if (c == 'O') {
                m1[i][j] = true;
            }
        }
    }
    for (int i=0; i < n; i++) {
        string str;
        cin >> str;
        for (int j=0; j < n; j++) {
            char c = str[j];
            if (c == 'O') {
                m2[i][j] = true;
            }
        }
    }
    
    ans |= ok(0, 0, +1, +1, true);
    ans |= ok(0, n-1, +1, -1, true);
    ans |= ok(n-1, 0, -1, +1, true);
    ans |= ok(n-1, n-1, -1, -1, true);
    ans |= ok(n-1, n-1, -1, -1, true);
    
    ans |= ok(0, 0, +1, +1, false);
    ans |= ok(0, n-1, +1, -1, false);
    ans |= ok(n-1, 0, -1, +1, false);
    ans |= ok(n-1, n-1, -1, -1, false);
    ans |= ok(n-1, n-1, -1, -1, false);
    
    ///////////////
    // for (int i=0; i < n; i++) {
    //     for (int j=0; j < n; j++) {
    //         cout << m1[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    // for (int i=0; i < n; i++) {
    //     for (int j=0; j < n; j++) {
    //         cout << m2[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    cout << (ans ? "Yes" : "No") << endl;
	return 0;
}

