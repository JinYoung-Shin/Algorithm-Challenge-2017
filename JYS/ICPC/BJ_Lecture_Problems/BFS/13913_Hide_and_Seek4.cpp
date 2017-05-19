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
bool visited[200010] = {false};
int ans[200010] = {0};
int from[200010] = {0}; // 어디에서 왔는지를 저장해둔다.
int Max = 200010;

queue<int> q;

void getFrom(int n, int k) {
    if(n == k) {
        return;
    }
    int temp = from[k];
    getFrom(n, temp);
    printf("%d ", k);
}

int main() {
    scanf("%d %d", &N, &K);
    visited[N] = true;
    ans[N] = 0;
    q.push(N);
    while(!q.empty()) {
        int val = q.front();
        q.pop();
        if(val - 1 >= 0) {
            if(visited[val - 1] == false) {
                q.push(val-1);
                visited[val-1] = true;
                ans[val-1] = ans[val] + 1;
                from[val-1] = val;
            }
        }
        if(val + 1 < Max) {
            if(visited[val + 1] == false) {
                q.push(val+1);
                visited[val+1] = true;
                ans[val+1] = ans[val] + 1;
                from[val+1] = val;
            }
        }
        if(val * 2 < Max) {
            if(visited[val * 2] == false) {
                q.push(val*2);
                visited[val*2] = true;
                ans[val*2] = ans[val] + 1;
                from[val*2] = val;
            }
        }
    }
    printf("%d\n", ans[K]);
    printf("%d ", N);
    getFrom(N, K);
    printf("\n");
    return 0;
}