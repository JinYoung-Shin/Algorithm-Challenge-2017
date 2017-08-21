#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> arr;
	n <<= 1;
	arr.reserve(n);
	for (int i=0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(), arr.end());
	
	if (arr[n/2-1] < arr[n/2]) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	// for (int i=0; i < n; i++) {
	// 	cout << arr[i] << ' ';
	// }
}