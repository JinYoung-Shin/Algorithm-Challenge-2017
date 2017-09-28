#include <iostream>

using namespace std;
int dp[16][16];

int n, m, k;

int get(int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (x == 0 && y == 0) return 1;
	if (dp[x][y]) return dp[x][y];
	
	return dp[x][y] = get(x-1, y) + get(x, y-1);
}

int get2(int x, int y, int limitx, int limity) {
	if (x < limitx || y < limity) return 0;
	if (dp[x][y]) return dp[x][y];
	
	return dp[x][y] = get2(x-1, y, limitx, limity) + get2(x, y-1, limitx, limity);
}
int main() {
	cin >> n >> m >> k;
	
	if (!k) {
		cout << get(n-1, m-1) << endl;
	} else {
		int xpos = (k-1) / m;
		int ypos = (k-1) % m;
		get(xpos, ypos);
		cout << get2(n-1, m-1, xpos, ypos) << endl;
	}
}