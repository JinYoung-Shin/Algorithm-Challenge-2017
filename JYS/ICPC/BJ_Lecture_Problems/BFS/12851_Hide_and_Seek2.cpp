//
//  main.cpp
//  icpc
//
//  Created by Spiritsensor on 2017. 5. 17.
//  Copyright © 2017년 JYS. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> Que;
int M = 200010;
bool visited[200010];
int ans[200010];
int cnt[200010];

int main() {
    scanf("%d %d", &N, &K);
    visited[N] = true;
    ans[N] = 0;
    cnt[N] = 1;
    Que.push(N);
    while(!Que.empty()) {
        int now = Que.front();
        Que.pop();
        if(now-1 >= 0) {
            if(visited[now-1] == false) {
                Que.push(now-1);
                visited[now-1] = true;
                ans[now-1] = ans[now] + 1;
                cnt[now-1] = cnt[now];
            } else if(ans[now-1] == ans[now] + 1) {
                cnt[now-1] += cnt[now];
            }
        }
        if(now+1 < M) {
            if(visited[now+1] == false) {
                Que.push(now+1);
                visited[now+1] = true;
                ans[now+1] = ans[now] + 1;
                cnt[now+1] = cnt[now];
            } else if(ans[now+1] == ans[now] + 1) {
                cnt[now+1] += cnt[now];
            }
        }
        if(now*2 < M) {
            if(visited[now*2] == false) {
                Que.push(now*2);
                visited[now*2] = true;
                ans[now*2] = ans[now] + 1;
                cnt[now*2] = cnt[now];
            } else if(ans[now*2] == ans[now] + 1) {
                cnt[now*2] += cnt[now];
            }
        }
    }
    printf("%d\n", ans[K]);
    printf("%d\n", cnt[K]);
    return 0;
}