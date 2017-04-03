#include <iostream>

using namespace std;

long long int dp[100][2];

long long int N;

long long int get(long long int a, long long int b) {
	if (dp[a][b] != -1) {
		return dp[a][b];
	}
	
	long long int val;
	
	if (b==0) {
		val = get(a-1, 0) + get(a-1, 1);
		dp[a][b] = val;
		return val;
	} else if (b==1) {
		val = get(a-1, 0);
		dp[a][b] = val;
		return val;
	}
	
}
int main() {
	for (int i=0;i<100;i++) {
		dp[i][0] = dp[i][1] = -1;
	}
	
	cin >> N;
	dp[0][0] = 0;
	dp[0][1] = 0;
	 dp[1][0] = 0;
	dp[1][1] = 1;
	
	 cout << get(N, 0) + get(N, 1) << endl;

}