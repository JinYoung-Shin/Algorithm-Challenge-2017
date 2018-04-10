#include <bits/stdc++.h>
using namespace std;

bool field[25][25];

int count(int x, int y) { //count number of un-prepareud for 3x3
    int ans = 9;
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            if (field[x+i][y+j]) ans--;
        }
    }
    return ans;
}
bool task(int x, int y) {
    cout << (x+1) << ' ' << (y+1) << endl;
    int a, b;
    cin >> a >> b;
    if (a == 0 and b == 0) {
        for (int i=x; i <= x+2; i++) {
            for (int j=y; j <= y+2; j++) {
                if (field[i][j] == false) {
                    field[i][j] = true;
                    return false;
                }
            }
        }
    }

    if (field[a][b] == false) {
        field[a][b] = true;
        return false;
    } else {
        return true; // failed. need more!
    }
}
bool is_it_clear(int srcx, int srcy, int dstx, int dsty) {
    for (int i=srcx; i <= dstx; i++) {
        for (int j=srcy; j <= dsty; j++) {
            if (field[i][j] == false) return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    for (int tc=1; tc <= t; tc++) {
        int A; //Area size
        memset(field, 0, sizeof(field));
        cin >> A;
        int height, width;
        if (A <= 9) {
            height = width = 3;
        } else {
            height = width = ceil(sqrt(A));
        }
 
        for (int k=9; k >= 1; k--) {
            for (int i=1; i <= width-2; i++) {
                for (int j=1; j <= height-2; j++) {
                    if (count(i, j) == k) {
                        while(task(i, j));
                    }
                }
            }
        }
        
    }
	return 0;
}

