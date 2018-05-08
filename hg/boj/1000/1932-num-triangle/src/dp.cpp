#include <bits/stdc++.h>
using namespace std;

int trig[501][501];
int dp[501][501]; // dp[i][j] 최상단 꼭지점이 i,j 삼각형의 합 중 최대가 되는 값
int n;
int main() {
    cin >> n;
    for (int i=0; i< n; i++) {
        for (int j=0; j < i+1 ;j++) {
            cin >> trig[i][j];
        }
    }
    
    for (int i=0; i < n; i++) {
        dp[n-1][i] = trig[n-1][i];
    }
    for (int i=n-2; i>=0 ;i--) {
        for (int j=0; j < i+1; j++) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + trig[i][j];
        }
    }
    //debug
    // for (int i=0; i< n; i++) {
    //     for (int j=0; j < i+1 ;j++) {
    //         cout << trig[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // for (int i=0; i< n; i++) {
    //     for (int j=0; j < i+1 ;j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[0][0] << '\n';
    return 0;
}