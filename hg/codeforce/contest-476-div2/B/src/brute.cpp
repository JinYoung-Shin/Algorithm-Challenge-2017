#include <bits/stdc++.h>
using namespace std;

string mm[105];
int field[105][105];
int ans;
int n, k;
void chk(int x, int y) {
    // printf("(%d, %d)\n", x, y);
    
    bool gap = true;
    for (int i=0; i < k; i++) {
        if ((x+i) >= n || mm[x+i][y] == '#') {
            gap = false;
            break;
        }
    }
    
    if (gap) {
        for (int i=0; i < k; i++) {
            field[x+i][y]++;
        }    
    }
    gap = true;
    
    
    for (int i=0; i < k; i++) {
        if ((y+i) >= n || mm[x][y+i] == '#') {
            gap=false;
            break;
        }
    }
    if (gap) {
        for (int i=0; i < k; i++) {
            field[x][y+i]++;
        }    
    }
    
    
}
int main() {
    
    cin >> n >> k;
    for (int i=0; i < n; i++) {
        cin >> mm[i];
    }
    
    //
    if (k == 1) {
        for (int i=0; i < n; i++) {
            for (int j=0;j < n; j++) {
                if (mm[i][j] == '.') {
                    cout << (i+1) << ' ' << (j+1) << endl;
                    return 0;
                }
            }
        }
    }
    
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (mm[i][j] == '.')
                chk(i, j);
        }
    }
    
    int val = 0;
    int row = 0;
    int col = 0;
    for (int i=0; i < n; i++) {
        for (int j=0; j < n;j++) {
            if (val < field[i][j]) {
                val = field[i][j];
                row = i;
                col = j;
            }
        }
    }
    
    //dump
    // for (int i=0; i < n; i++) {
    //     for (int j=0; j < n;j++) {
    //         cout << mm[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    // for (int i=0; i < n; i++) {
    //     for (int j=0; j < n;j++) {
    //         cout << field[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << (row+1) << ' ' << (col+1) << endl;
	return 0;
}

