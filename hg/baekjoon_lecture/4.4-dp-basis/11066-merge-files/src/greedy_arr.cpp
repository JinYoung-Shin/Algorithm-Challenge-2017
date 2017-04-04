#include <iostream>
#include <vector>
using namespace std;

void dump_arr(vector<int>& arr) {
	for (int i=0 ; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int min_idx(vector<int>& arr) {
	int min = 987654321;
	int idx = -1;
	for (int i=0; i < arr.size() - 1; i++) {
		int a = arr[i];
		int b = arr[i+1];
		if (min > a+b) {
			min = a+b;
			idx = i;
		}
	}
	return idx;
}

int main() {
	int t;
	
	cin >> t;
	
	while (t--) {
		int n;
		vector<vector<int> > dp;
		vector<int> arr;
		vector<int> next_arr;
		cin >> n;
		int val = 0;
		arr.reserve(n);
		dp.reserve(n);
		for (int i=0; i < n ; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		
		dump_arr(arr);
		for (int i=0; i < n - 1;i++) {
			int index = min_idx(arr);
			cout << "min index = " << index << endl;
			for (int j=0; j < arr.size(); j++) {
				if (j == index) {
					next_arr.push_back(arr[j]+arr[j+1]);
					val+=arr[j] + arr[j+1];
				} else if (j == index + 1) {
					continue;
				} else {
					next_arr.push_back(arr[j]);
				}
			}
			dump_arr(next_arr);
			dp.push_back(next_arr);
			arr = next_arr;
			next_arr.clear();
			
			cout << " answer " << val << endl;
		}
	}
}