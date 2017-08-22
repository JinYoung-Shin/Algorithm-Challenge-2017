#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> Data;


int main() {
	int n;
	cin >> n;
	int cnt = 0;
	vector<Data> arr;
	arr.reserve(2*n);
	
	for (int i=0; i < n; i++) {
		int left, right;
		cin >> left >> right;
		Data tmp;
		tmp.first = left;
		tmp.second = 1;
		arr.push_back(tmp);
		
		tmp.first = right+1;
		tmp.second = -1;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(), arr.end());
	
	for (int i=0; i < n*2; i++) {
		cnt += arr[i].second;
		if (cnt > 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}