#include <bits/stdc++.h>
using namespace std;

#define UP      0 //arr에선 위에위치, dp에선 위에것만 선택 가능할 시
#define DOWN    1
#define BOTH    2


int dp[100000][3]; //시작 x좌표와 선택할 수 있는 상태
int arr[100000][2];
int n;
int solve(int len, int stat) {
    if (len < 0 or len >= n or stat < 0 or stat >= 3) return 0;
    if (dp[len][stat] != -1) return dp[len][stat];
    int ans = 0;
    if (stat != DOWN) { //위에걸 선택할 수 있는 상태이면(UP or BOTH)
        ans = max(ans, arr[len][UP] + solve(len+1, DOWN)); //위에걸 선택
        ans = max(ans, solve(len+1, BOTH)); //그냥 안선택
    }
    if (stat != UP) { //아래걸 선택할 수 있는 상태이면(DOWN or BOTH)
        ans = max(ans, arr[len][DOWN] + solve(len+1, UP)); //위에걸 선택
        ans = max(ans, solve(len+1, BOTH)); //그냥 안선택
    }
    return dp[len][stat] = ans;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        
        cin >> n;
        for (int i=0; i < n; i++) {
            cin >> arr[i][UP];
        }
        for (int i=0; i < n; i++) {
            cin >> arr[i][DOWN];
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(0, BOTH) << '\n';
    }
	return 0;
}

