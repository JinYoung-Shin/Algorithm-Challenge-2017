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

int N;
long long DP[100][2];
long long ans = 0;

int main() {
    scanf("%d", &N);
    DP[1][0] = 0;
    DP[1][1] = 1;
    for(int i = 2; i <= N; i++) {
        DP[i][0] = DP[i-1][0] + DP[i-1][1];
        DP[i][1] = DP[i-1][0];
    }
    ans = DP[N][0] + DP[N][1];
    printf("%lld\n", ans);
    return 0;
}

/*
D[i][0] : 0으로 끝나는 것의 개수, 앞에 0 또는 1일 갈 수 있다. D[i-1][0] + D[i-1][1]
D[i][1] : 1로 끝나는 것의 개수, 앞에 무조건 0 뿐이 올 수 없다. D[i-1][0]
*/