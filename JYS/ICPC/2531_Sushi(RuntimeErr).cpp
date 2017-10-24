//
//  main.cpp
//  AlgoKing
//
//  Created by 신진영 on 2017. 10. 21..
//  Copyright © 2017년 신진영. All rights reserved.
//

// 회전 초밥

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, d, k, c; // k가 쿠폰
bool visited[3010] = {false};
int arr[30010];
int answer = 0;
int temp = 0;
int cnt = 0;

int main(int argc, const char * argv[]) {
    cin >> N >> d >> k >> c;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int end = N + k;
    for(int i = 0; i < end; i++) {
        if(visited[arr[i%N]] == false) {
            cnt++;
            visited[arr[i%N]] = true;
        }
        
        if(i >= k) {
            temp = cnt;
            if(visited[i] == false) temp++;
            if(answer < temp) answer = temp;
            //if(--check[a[i-k+1]]==0) cnt--;
            if(visited[i-k+1] == false) cnt--;
        }
    }
    
    cout << answer;
    
    return 0;
}