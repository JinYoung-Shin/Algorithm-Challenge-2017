#include <bits/stdc++.h>

using namespace std;

int score[302];
int dp[305][2]; //dp[i][j] -> i번째 계단까지 오르고, j번 연속 밟았을때 점수의 최대값.
int main() {
    int n;
    cin >> n;
    for (int i=1;i <= n; i++) {
        cin >> score[i];
    }
    dp[1][0] = score[1];
    for (int i=0; i <n; i++) {
        dp[i+1][1] = max(dp[i+1][1], dp[i][0] + score[i+1]); //한칸 걷는 경우
        dp[i+2][0] = max(dp[i+2][0], dp[i][0] + score[i+2]); //두칸 걷는 경우
        dp[i+2][0] = max(dp[i+2][0], dp[i][1] + score[i+2]); 
    }
    int ans = max(dp[n][0], dp[n][1]);
    cout << ans << '\n';
    // for (int i=0; i <= n; i++) {
    //     printf("dp[%d][%d]=%d | dp[%d][%d]=%d\n", i,0, dp[i][0], i, 1, dp[i][1]);
    // }
    return 0;
}