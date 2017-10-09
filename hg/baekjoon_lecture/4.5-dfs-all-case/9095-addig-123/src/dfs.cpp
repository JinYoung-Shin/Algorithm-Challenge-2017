#include <iostream>

using namespace std;

int n;
int dfs(int remain) {
	int sum = 0;
	if (remain == 0) {
		//cout << "한가지 찾음" << endl;
		return 1;
	}
	if (remain >= 1) {
		sum += dfs(remain-1);
	}
	if (remain >= 2) {
		sum += dfs(remain-2);
	}
	if (remain >= 3) {
		sum += dfs(remain-3);
	}
	return sum;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dfs(n) << endl;
	}
}