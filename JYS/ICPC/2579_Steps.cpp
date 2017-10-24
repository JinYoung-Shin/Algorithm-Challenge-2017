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

int n;
int arr[310];
int dp[310];

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    // 1 1 1 / 2 2 2 안된다.
    // 112112... 12112112
    dp[0] = arr[0];
    for(int i=1; i<3; i++){
        if(i==1) {
            dp[i] = max(arr[i-1]+arr[i], arr[i]);
        } else {
            dp[i] = max(arr[i-2]+arr[i], arr[i-1]+arr[i]);
        }
    }
    for(int i = 3; i < n; i++) {
        dp[i] += max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
    }
    
    cout << dp[n-1];

    return 0;
}