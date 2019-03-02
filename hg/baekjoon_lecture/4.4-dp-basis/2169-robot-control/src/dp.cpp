#include <bits/stdc++.h>
using namespace std;

int A[1005][1005];
int dp[1005][1005][3];
#define FROM_UP 0
#define FROM_LEFT 1
#define FROM_RIGHT 2
const int INF = 1100000000;
#define MAX(a,b,c) max(a,max(b,c))
/*
dp[i][j][k] => (i, j)까지 가는 데에 있어서 최근에 k방향에서 온 최대값 경우
위에서 오거나 오른쪽에서 오거나 왼쪽에서 오거나 3가지 가능성 밖에 존재하지 않는다.
한번 간 곳을 다시 방문하지 않는다는 특성은 왼쪽으로 갔으면 다시 오른쪽으로 가진 앟ㄴ고
왼쪽으로 계속가거나 아래로 내려가야 한다.
마찬가지로 오른쪽도 한번 가면 계속 오른쪽으로 가거나 아래로 내려가야 한다.
이러한 특성을 이용해서 dp점화식을 돌리면 된다.
*/
int main() {
    int N, M; 
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    for (int i=1; i <= N; i++) {
        for (int j=1; j <= M; j++) {
            cin >> A[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF;
        }
    }
    

    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = A[1][1];
    for (int i=1; i <= M; i++) {
        dp[1][i][FROM_LEFT] = dp[1][i-1][FROM_LEFT] + A[1][i];
    }
    for (int i=1; i<= N; i++) {
        if (i != 1) {
            for (int j=1; j <= M; j++) {
                dp[i][j][FROM_UP] = MAX(dp[i-1][j][FROM_UP], dp[i-1][j][FROM_LEFT], dp[i-1][j][FROM_RIGHT]) + A[i][j];
            }    
        }
        for (int j=2; j <=M; j++) {
            dp[i][j][FROM_LEFT] = max(dp[i][j-1][FROM_UP], dp[i][j-1][FROM_LEFT]) + A[i][j];
        }   
        for (int j=M-1; j>=1; j--) {
            dp[i][j][FROM_RIGHT] = max(dp[i][j+1][FROM_UP], dp[i][j+1][FROM_RIGHT]) + A[i][j];
        }
    }
    auto& a = dp[N][M];

    cout << MAX(a[0], a[1], a[2]) << endl;
    
}