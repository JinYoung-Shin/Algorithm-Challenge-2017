#include <iostream>
#include <vector>

using namespace std;

long long int dp[101][21];
int N, goal;
vector<int> num;

long long int get(int i, int j) {
	if (j<0 || j > 20) {
		return 0;
	}
	if (dp[i][j] != -1) {
		 return dp[i][j];
	}
	long long int val = get(i-1, j - num[i]) + get(i-1, j + num[i]);
	dp[i][j] = val;
	return val;
}
int main() {
	cin >> N;
	num.reserve(N);
	
	for (int i=0;i<N;i++) {
		for (int j=0;j<21;j++) {
			dp[i][j] = -1;
		}
	}
	
	
	for (int i=0;i<N-1;i++) {
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	cin >> goal;
	for (int i=0;i<21;i++) {
		dp[0][i] = 0;
	}
	dp[0][num[0]] = 1;
	
	cout << get(N-2, goal) << endl;
	//cout << "answer - " << get(9, 8) << endl;
	//cout << "goal - " << goal << endl;
	
}