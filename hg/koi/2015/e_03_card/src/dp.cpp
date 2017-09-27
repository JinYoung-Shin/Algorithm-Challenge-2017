#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> L, R;
int n;

int dp[2001][2001];
bool chk[2001][2001];

int get(int l, int r) {
	if (l <= 0 || r <= 0) {
		return 0;
	}
	if (chk[l][r]) return dp[l][r];

	int ret;
	
	ret = max(get(l-1, r-1), get(l-1, r));
	int left_top_card_val = L[n-l];
	int right_top_card_val = R[n-r];
	if (left_top_card_val > right_top_card_val) {
		ret = max(ret, get(l, r-1) + right_top_card_val);
	}
	chk[l][r] = true;
	return dp[l][r] = ret;
}
int main() {
	cin >> n;
	L.reserve(n);
	R.reserve(n);

	for (int i=0; i < n; i++) {
		int tmp;
		cin >> tmp;
		L.push_back(tmp);
	}
	for (int i=0; i < n; i++) {
		int tmp;
		cin >> tmp;
		R.push_back(tmp);
	}
	cout << get(n, n) << endl;
}