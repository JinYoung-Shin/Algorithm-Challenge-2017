//
//  main.cpp
//  icpc
//
//  Created by Spiritsensor on 2017. 5. 7..
//  Copyright © 2017년 JYS. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[1010][1010];
long long DP[1010][1010];

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    DP[1][1] = arr[1][1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if( i == 1 || j == 1) {
                if(i == 1) DP[i][j] = DP[i][j-1] + arr[i][j];
                if(j == 1) DP[i][j] = DP[i-1][j] + arr[i][j];
            }
            else {
                DP[i][j] = max(DP[i-1][j] + arr[i][j], DP[i][j-1] + arr[i][j]);
            }
        }
    }
    printf("%lld\n", DP[N][M]);
    return 0;
}