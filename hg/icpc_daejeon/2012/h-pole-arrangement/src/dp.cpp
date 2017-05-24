#include <iostream>

using namespace std;

long long dp[25][25][25];
bool chk[25][25][25];
long long bic[45][25]; //bicofficient
bool bc[45][25]; //bicofficient checker

long long C(int n, int r) {
	if (bc[n][r]) {
		return bic[n][r];
	}
	if (n == 0 && r == 0) {
		return 1;
	}
	if (r == 0 || r == n) {
		return 1;
	}
	if (r == 1 || r == n-1) {
		return n;
	}
	
	long long val = C(n-1, r) + C(n-1, n-1);
	bic[n][r] = val;
	bc[n][r] = true;
	return val;
}
long long get(int n, int l, int r) {
	if (n <0 || l < 0 || r < 0) {
		return 0;
	}
	if (n==0 && l==0 && r==0) {
		return 1;
	}
	if (n==1 && l==1 && r==1) {
		return 1;
	}
	if (n == r && l == 1) {
		return 1;
	}
	if (n == l && r == 1) {
		return 1;
	}
	
	if (chk[n][l][r]) 
		return dp[n][l][r];
	long long val = 0;
	val += get(n -1, 1, r - 1);
	val += get(n -1, l - 1, 1);
	
	
	int l1 = l -1;
	int r2 = r - 1;
	for (int n1 = 1; n1 < n -1 ; n1++) {
		int n2 = n - 1 - n1;
		for (int r1 = 1; r1 < n1; r1++) {
			for (int l2 = 1; l2 < n2; l2++) {
				val += get(n1,l1,r1) * get(n2,l2,r2) * C(n1+n2, n1);
			}
		}
	}
}

int main() {
	int t, n, l, r;
	
	cin >> t;
	
	/*
	for (int n1 = 1; n1 < 21; n1++) {
		for (int l1 = 1; l1 <= n1; l1++) {
			for (int r1 = 1; r1 <= n1; r1++) {
				dp[n1 + 1][1][r1 + 1] += get(n1,l1,r1); //맨 왼쪽에 새우는 경우 - n1블록만 고려
				dp[n1 + 1][l1 + 1][1] += get(n1,l1,r1); //맨 오른쪽에 새우는 경우 - n1블록만 고려
				for (int n2 = 1; n2 < 21-n1; n2++) {
					for (int l2 = 1; l2 <= n2; l2++) {
						for (int r2 = 1; r2 <= n2; r2++) {
							dp[n1 + n2 + 1][l1 + 1][r2 + 1] += (get(n1,l1,r1) * get(n2,l2,r2) * C(n1+n2, n1)); //중간에 새우는 경우
						}
					}
				}
			}
		}
	}
	*/
	while (t--) {
		
		cin >> n >> l >> r;
		cout << get(n,l,r) << endl;
	};
	
	cout << "(3,2,1) " << get(3,2,1) << endl;
	cout << "(3,3,1) " << get(3,3,1) << endl;
	cout << "(2,1,2) " << get(2,1,2) << endl;
}