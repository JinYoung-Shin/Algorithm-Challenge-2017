// Distance마다 큐를 추가로 선언하며 답을 찾아가는 풀이법..
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
bool visited[1000010] = {false};
int ans[1000010] = {0};
int Max = 1000010;

queue<int> q;
queue<int> next_q;

int main() {
    scanf("%d %d", &N, &K);
    q.push(N);
    ans[N] = 0;
    visited[N] = true;
    int val;
    while(!q.empty()) {
        val = q.front();
        q.pop();
        if(val*2 < Max) {
            if(visited[val*2] == false) {
                q.push(val*2);
                visited[val*2] = true;
                ans[val*2] = ans[val];
            }
        }
        if(val+1 < Max) {
            if(visited[val+1] == false) {
                next_q.push(val+1);
                visited[val+1] = true;
                ans[val+1] = ans[val]+1;
            }
        }
        if(val-1 >= 0) {
            if(visited[val-1] == false) {
                next_q.push(val-1);
                visited[val-1] = true;
                ans[val-1] = ans[val]+1;
            }
        }
        
        if(q.empty()) {
            q=next_q;
            next_q = queue<int>(); // 새 큐 선언하는 것 !!! queue<int>()
        }
    }
    printf("%d\n", ans[K]);
    return 0;
}

/*
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[1000010] = {false};
int ans[1000010] = {0};
int Max = 1000010;

queue<int> q;

int main() {
    scanf("%d %d", &N, &K);
    visited[N] = true;
    ans[N] = 0;
    q.push(N);
    int val = N;
    while(val < K) {
        val = val * 2;
        q.push(val);
        visited[val] = true;
    }
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        //t+1
        if(t+1 < Max) {
            if(!visited[t+1]) {
                ans[t+1] = ans[t] + 1;
                q.push(t+1);
                visited[t+1] = true;
            }
        }
        //t-1
        if(t-1 > 0) {
            if(!visited[t-1]) {
                ans[t-1] = ans[t] + 1;
                q.push(t-1);
                visited[t-1] = true;
            }
        }
    }
    printf("%d\n", ans[K]);
    return 0;
}
*/