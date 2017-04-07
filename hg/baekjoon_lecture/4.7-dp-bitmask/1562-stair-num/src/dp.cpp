#include <iostream>
#include <cstdio>

using namespace std;
typedef long long int lli;

const lli mod = 1000000000LL;
// const lli mod = 1000000000000LL;

lli dp[105][12][1050]; //길이, 마지막수, 비트마스크
bool c[105][12][1050];

lli get(int n,int k,int bm) {
	// printf("(%d, %d, %d) - called\n", n,k,bm);
	
	if (k<0 || n<0 || bm<0 || k>9) {
		return 0LL;
	}
	if ( (bm & (1<<k)) == 0) {
		return 0LL;
	}
	if (c[n][k][bm] == true) {
		return dp[n][k][bm];
	}
	
	lli val = 0LL;
	
	// if ( k >= 1 && (bm & (1 << (k-1)) ) != 0) {
		val += get(n-1, k-1, bm) % mod;
		val += get(n-1, k-1, bm & ~(1<<k)) % mod;
	// }

	// if ( (bm & (1 << (k+1))) != 0) {
		val += get(n-1, k+1, bm) % mod;
		val += get(n-1, k+1, bm & ~(1<<k)) % mod;
	// }
	
	dp[n][k][bm] = val;
	c[n][k][bm] = true;
	return val;
}

lli get_ans(int n) {
	lli ans = 0;
	for (int i=0;i<10;i++) {
		ans += get(n, i, ((1<<10) - 1));
		ans %= mod;
	}
	
	return ans;
}

int main() {
	int N;
	
	cin >> N;
		
	//0으로 시작하는 건 없다.
	dp[1][0][1] = 0LL;
	c[1][0][1] = true;
	//초기화
	for (int i=1;i<10;i++) {
		dp[1][i][(1<<i)] = 1LL;
		c[1][i][(1<<i)] = true;
	}
	
	cout << get_ans(N) << endl;
	
	// cout << "------------------------------------------" << endl;
	// lli ans = 0;
	// lli summation = 0;
	// for (int i=1; i<=40;i++) {
	// 	ans = get_ans(i);
	// 	cout << "(" << i << " = " << ans << ")" << endl;
	// 	summation += ans;
	// 	summation %= mod;
	// }
	// cout << "sum - " << summation << endl;
	
	
}