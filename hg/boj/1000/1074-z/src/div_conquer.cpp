#include <bits/stdc++.h>

using namespace std;

int find(int sx, int sy, int len, int tx, int ty) {
    if (len < 2) return 1;
    // int dx = sx + len;
    //int dy = sy + len;
    int mx = sx + len/2;
    int my = sy + len/2;
    int qsize = len*len/4;
    if (tx < mx) { //상단 2개
        if (ty < my) { //상단 좌측
            return find(sx, sy, len/2, tx, ty);
        } else { //상단 우측
            return qsize + find(sx, my, len/2, tx, ty);
        }
    } else { //하단 2개
        if (ty < my) { //하단 좌측
            return 2*qsize + find(mx, sy, len/2, tx, ty);
        } else { //하단 우측
            return 3*qsize + find(mx, my, len/2, tx, ty);
        }
    }
}
int main() {
    int n, r, c;
    cin >> n >> r >> c;
    int len = (1 << n);
    
    // for (int i=0; i < len; i++) {
    //     for (int j=0; j < len; j++) {
    //         printf("%d ", find(0, 0, len, i , j)-1);
    //     }
    //     putchar('\n');
    // }
    cout << find(0, 0, len, r, c)-1 << '\n';
    return 0;
}