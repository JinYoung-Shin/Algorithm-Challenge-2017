#include <bits/stdc++.h>
using namespace std;

bool field[32][32][32];
bool chk[32][32][32];
typedef struct _Pos {
    int x, y, z;
    int min;
} Pos;
int x, y, z;
inline void fail() {puts("Trapped!");};
inline bool is_in(int a, int b, int c) {
    return a>=0 && b>=0 && c>=0 && a < x && b < y && c < z;
}

const int dx[] = {+0, +0, +0, +0, -1, +1};
const int dy[] = {+0, +0, -1, +1, +0, +0};
const int dz[] = {+1, -1, +0, +0, +0, +0};

int main() {
    while(true) {

        int sx, sy, sz;
        int fx, fy, fz;
        cin >> x >> y >> z;
        if (!x and !y and !z) break;
        string str;
        for (int i=0; i < x; i++) {
            for (int j=0; j < y; j++) {
                cin >> str;
                for (int k=0; k < z; k++) {
                    char c = str[k];
                    if (c == '#') {
                        field[i][j][k] = false; //blocked!
                    } else {
                        field[i][j][k] = true; //passable
                        if (c == 'S') {
                            sx = i;
                            sy = j;
                            sz = k;
                        } else if (c == 'E') {
                            fx = i;
                            fy = j;
                            fz = k;
                        }
                    }
                }
            }
        }
        
        Pos pos;
        pos.x = sx;
        pos.y = sy;
        pos.z = sz;
        pos.min = 0;
        queue<Pos> q;
        q.push(pos);
        chk[sx][sy][sz] = true; //visited check
        bool escaped = false;
        while(!q.empty()) {
            Pos v = q.front(); q.pop();
            for (int k=0; k < 6; k++) {
                int nx = v.x + dx[k];
                int ny = v.y + dy[k];
                int nz = v.z + dz[k];
                
                if (is_in(nx, ny, nz) && field[nx][ny][nz] && chk[nx][ny][nz] == false) {
                    if (nx == fx and ny == fy and nz == fz) {
                        printf("Escaped in %d minute(s).\n", v.min+1);
                        escaped = true;
                    }
                    chk[nx][ny][nz] = true;
                    Pos tmp;
                    tmp.x = nx;
                    tmp.y = ny;
                    tmp.z = nz;
                    tmp.min = v.min + 1;
                    q.push(tmp);
                }
            }
        }
        
        if (!escaped) fail();
        memset(chk, 0, sizeof(chk));
    }
    
    
    
	return 0;
}

