#include <bits/stdc++.h>
using namespace std;

bool seat[2001][2001];
int garo[2002][2002];
int sero[2002][2002];
int bias;
int main() {
    int ans = 0;
    int n, m, k;
    scanf("%d %d %d\n", &n, &m, &k);
    bias=1;
    for (int i=0; i < n; i++) {
        int val = 0;
        for (int j=0; j < m; j++) {
            char ch;
            scanf("%c", &ch);
            if (ch == '*') {
                seat[i][j] = true;
                ans += max(0, val-k+bias);
                val = 0;
            } else {
                // garo[i][j+1] = garo[i][j] + 1;
                val++;
                sero[i+1][j] = sero[i][j] + 1;
            }
            
        }
        scanf("\n");
        ans += max(0, val-k+bias);
    }
    
    //garo check
    // for (int i=0; i < n; i++) {
    //     int val = 0;
    //     for (int j=1; j<= m; j++) {
    //         if (garo[i][j] > 0) {
    //             val = max(val, garo[i][j]);
    //         } else {
    //             ans += max(0, val-k+1);
    //             val = 0;
    //         }
    //     }
    //     ans += max(0, val-k+1);
    // }
    
    if (k != 1) {
        for (int j=0; j < m; j++) {
            int val = 0;
            for (int i=1; i <= n; i++) {
                if (sero[i][j] > 0) {
                    val = max(val, sero[i][j]);
                } else {
                    ans += max(0, val-k+bias);
                    val = 0;
                }
            }
            ans += max(0, val-k+bias);
        }
    }
    
    
    //dump
    // for (int i=0; i < n; i++) {
    //     for (int j=0; j < m; j++) {
    //         cout << seat[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "==============================" << endl;
    
    // for (int i=0; i < n; i++) {
    //     for (int j=1; j <= m; j++) {
    //         cout << garo[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "==============================" << endl;
    // for (int i=1; i <= n; i++) {
    //     for (int j=0; j < m; j++) {
    //         cout << sero[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    //dump
    
    cout << ans << '\n';
	return 0;
}

