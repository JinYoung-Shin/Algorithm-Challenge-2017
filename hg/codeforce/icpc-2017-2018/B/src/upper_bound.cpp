#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > answer;
int main() {
	vector<int> arr;
	int n;
	cin >> n;
	for (int i=0; i < n; i++) {
		int x;
		cin >> x;
		auto it = upper_bound(arr.begin(), arr.end(), -x);
		if (it == arr.end()) {//not found
			arr.push_back(-x);
			answer.push_back({x});
		} else {
			int offset = it - arr.begin();
			arr[offset] = -x;
			answer[offset].push_back(x);
		}
	}
	
	for (int i=0; i < answer.size(); i++) {
		for (int j=0; j < answer[i].size(); j++) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
}