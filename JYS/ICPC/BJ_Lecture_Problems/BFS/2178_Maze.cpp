//
//  main.cpp
//  icpc
//
//  Created by Spiritsensor on 2017. 5. 17.
//  Copyright © 2017년 JYS. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int N,M;
int arr[110][110];
bool visited[110][110] = {false};
int ans[110][110] = {0};

struct Point {
    int x;
    int y;
};

Point Q[110*110*100];

int fp = 0, lp = 0;
int r, c, rr, cc;

void bfs() {
    lp++;
    while(lp > fp) {
        r = Q[fp].x;
        c = Q[fp++].y;
        for(int i = 0 ; i < 4; i++) {
            rr = r+dx[i];
            cc = c+dy[i];
            if(rr >= 1 && rr <= N && cc >= 1 && cc <= M) {
                if(arr[rr][cc] == 1 && visited[rr][cc] == false) {
                    // push to Q
                    Q[lp].x = rr;
                    Q[lp++].y = cc;
                    // set visited, ans
                    visited[rr][cc] = true;
                    ans[rr][cc] = ans[r][c] + 1;                }
            }
        }
    }
    return;
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    Q[0].x = 1, Q[0].y = 1;
    visited[1][1] = true;
    ans[1][1] = 1;
    bfs();
    printf("%d\n", ans[N][M]);
    
    return 0;
}