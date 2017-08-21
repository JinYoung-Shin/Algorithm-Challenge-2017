#include <vector>
#include <cstdio>

using namespace std;

int MOD = 20170805;

#define GARO 0
#define SERO 1

int dp[501][501][2];

struct state {
	int x, y;
	bool right; // true->right / false->down
};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
	//초기화
	for (int i=0; i < m; i++) {
		for (int j=0; j < n; j++) {
			dp[i][j][0] = dp[i][j][1] = 0;
		}
	}
	//시작부분 초기화
	dp[0][0][GARO] = 1;
	//맨윗줄 dp 초기화
	for (int i=0; i < n-1; i++) {
		if (city_map[0][i+1] == 1) continue;
		if (city_map[0][i] == 0) {
			dp[0][i+1][GARO] = dp[0][i][GARO] + dp[0][i][SERO];
			dp[0][i+1][GARO] %= MOD;
		} else if (city_map[0][i] == 2) {
			dp[0][i+1][GARO] = dp[0][i][GARO];
			dp[0][i+1][GARO] %= MOD;
		}
	}
	//맨 왼쪽줄 dp 초기화
	for (int j=0; j < m-1; j++) {
		if (city_map[j+1][0] == 1) continue;
		if (city_map[j][0] == 0) {
			dp[j+1][0][SERO] = dp[j][0][GARO] + dp[j][0][SERO];
			dp[j+1][0][SERO] %= MOD;
		} else if (city_map[j][0] == 2) {
			dp[j+1][0][SERO] = dp[j][0][SERO];
			dp[j+1][0][SERO] %= MOD;
		}
	}
	for (int i=1; i < m; i++) {
		for (int j=1; j < n; j++) {
			int current = city_map[i][j];
			int left_prev = city_map[i][j-1];
			int up_prev = city_map[i-1][j];
			if (current == 1) continue;
			if (up_prev == 0) {
				dp[i][j][SERO] += dp[i-1][j][SERO] + dp[i-1][j][GARO];
				dp[i][j][SERO] %= MOD;
			} else if (up_prev == 2) {
				dp[i][j][SERO] += dp[i-1][j][SERO];
				dp[i][j][SERO] %= MOD;
			}
			if (left_prev == 0) {
				dp[i][j][GARO] += dp[i][j-1][SERO] + dp[i][j-1][GARO];
				dp[i][j][GARO] %= MOD;
			} else if (left_prev == 2) {
				dp[i][j][GARO] += dp[i][j-1][GARO];
				dp[i][j][GARO] %= MOD;
			}
		}
	}
	/////
	// for (int i=0; i < m; i++) {
	// 	for (int j=0; j < n; j++) {
	// 		printf("(%d, %d) ", dp[i][j][0], dp[i][j][1]);
	// 	}
	// 	printf("\n");
	// }
	/////
	answer = (dp[m-1][n-1][GARO] + dp[m-1][n-1][SERO]) % MOD;
    return answer;
}