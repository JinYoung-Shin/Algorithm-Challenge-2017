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

long long d[210][210];
long long mod = 1000000000;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    d[0][0] = 1;
    for (int i=1; i<=k; i++) {
        for (int j=0; j<=n; j++) {
            for (int l=0; l<=j; l++) {
                d[i][j] += d[i-1][j-l];
                d[i][j] %= mod;
            }
        }
    }
    printf("%lld\n", d[k][n]);
    return 0;
}