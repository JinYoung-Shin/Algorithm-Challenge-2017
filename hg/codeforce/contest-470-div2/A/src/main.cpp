#include <bits/stdc++.h>
using namespace std;

string field[501];
const int dx[] = {+1, -1, +0, +0};
const int dy[] = {+0, +0, +1, -1};
int r, c;
inline bool is_in(int x, int y) {
    return x>=0 and y>=0 and x<r and y<c;
}
void is_ok(int x, int y) {
    int nx, ny;
    for (int k=0; k < 4; k++) {
        nx = x + dx[k];
        ny = y + dy[k];
        if (is_in(nx, ny)) {
            if (field[nx][ny] == 'S') {
                cout << "No" << endl;
                exit(EXIT_SUCCESS);
            }
        }
    }
}
int main() {
    
    cin >> r >> c;
    for (int i=0; i < r; i++) {
        cin >> field[i];
    }
    for (int x=0; x < r; x++) {
        for (int y=0; y <c; y++) {
            char& ch = field[x][y];
            if (ch == '.') {
                ch = 'D';
            } else if (ch == 'W') {
                is_ok(x, y);
            }
        }
    }
    
    cout << "Yes\n";
    for (int i=0; i < r; i++) {
        cout << field[i] << '\n';
        
    }
	return 0;
}

