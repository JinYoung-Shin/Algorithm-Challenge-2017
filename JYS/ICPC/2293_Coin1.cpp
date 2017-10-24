//
//  main.cpp
//  AlgoKing
//
//  Created by 신진영 on 2017. 10. 19..
//  Copyright © 2017년 신진영. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, k;
int nn[110];
int dp[10010] = {0};

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> nn[i];
    }
    
    // 동전의 합이 k가 되는 경우의 수라 ...
    // DP...
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(nn[i] <= j) dp[j] += dp[j-nn[i]];
        }
    }
    cout << dp[k];
    return 0;
}
