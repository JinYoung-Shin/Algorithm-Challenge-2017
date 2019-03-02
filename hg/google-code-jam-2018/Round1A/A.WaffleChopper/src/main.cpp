#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > garo_slice, sero_slice;

int field[101][101];
int accu[105][105];
inline int range(int sx, int sy, int dx, int dy) {
    return accu[dx][dy] - accu[sx-1][dy] - accu[dx][sy-1] + accu[sx-1][sy-1];
}
int main() {
    int t;
    cin >> t;
    for (int tc=1; tc <= t; tc++) {
        bool ans = true;
        // cout << "Case " << tc << endl;
        int R, C, H, V;
        cin >> R >> C >> H >> V;
        for (int i=1; i <= R; i++) {
            string str;
            cin >> str;
            // cout << str << endl;
            for (int j=0; j < C; j++) {
                char ch = str[j];;
                if (ch == '@') {
                    field[i][j+1] = 1;
                } else {
                    field[i][j+1] = 0;
                }
                
            }
        }
        
        //dump map
        // for (int i=1; i <= R; i++) {
        //     for (int j=1;j <= C; j++) {
        //         cout << field[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        
        
        
        //garo sum
        for (int i=1; i <= R; i++) {
            for (int j=1; j <= C; j++) {
                accu[i][j] = accu[i][j-1] + field[i][j];
            }
        }
        
        //sero sum
        for (int i=1; i <= C; i++) {
            for (int j=1; j <= R; j++) {
                accu[j][i] = accu[j-1][i] + accu[j][i];
            }
        }
        
        // cout << "===================" << endl;
        // for (int i=1; i <= R; i++) {
        //     for (int j=1;j <= C; j++) {
        //         cout << accu[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        
        int choco_num = accu[R][C];
        int row_num = H+1;
        int col_num = V+1;
        int sec_num = (H+1) * (V+1);
        if (choco_num % sec_num || choco_num % row_num || choco_num % col_num || choco_num % sec_num) {
            ans = false;
        }
        
        int choco_per_row = choco_num / row_num;
        int choco_per_col = choco_num / col_num;
        int choco_per_sec = choco_num / sec_num;
        
        
        
        int prev_index = 1;
        int cnt = choco_num;
        for (int i=1; i <= R; i++) {
            int val = range(prev_index, 1, i, C);
            if (val < choco_per_row) continue;
            if (val == choco_per_row) {
                sero_slice.push_back(make_pair(prev_index, i));
                prev_index = i+1;
                cnt -= choco_per_row;
                continue;
            }
            if (val > choco_per_row) {
                break;
            }
        }
        
        if (cnt) {
            ans = false;
        }
        
        prev_index = 1;
        cnt = choco_num;
        for (int i=1; i <= C; i++) {
            int val = range(1, prev_index, R, i);
            if (val < choco_per_col) continue;
            if (val == choco_per_col) {
                garo_slice.push_back(make_pair(prev_index, i));
                prev_index = i+1;
                cnt -= choco_per_col;
                continue;
            }
            if (val > choco_per_col) {
                break;
            }
        }
        if (cnt) {
            ans = false;
        }
        
        for (int i=0; i < (int)sero_slice.size(); i++) {
            auto& x = sero_slice[i];
            if (ans == false) break;
            for (int j=0; j < (int)garo_slice.size(); j++) {
                auto& y = garo_slice[j];
                int val = range(x.first, y.first, x.second, y.second);
                if (val != choco_per_sec) {
                    ans = false;
                    break;
                    
                }
            }
        }
        
        printf("Case #%d: %s\n", tc, ans ? "POSSIBLE" : "IMPOSSIBLE");
        garo_slice.clear();
        sero_slice.clear();
        memset(accu, 0, sizeof(accu));
    }
	return 0;
}

