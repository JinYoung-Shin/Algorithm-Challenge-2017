#include <vector>
#include <iostream>
// #include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int t, n;

void dump_arr(vector<int>& arr) {
	for (int i=0 ; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	cin >> t;
	while(t--) {
		// vector<int> arr;
		cin >> n;
		// arr.reserve(n);
		priority_queue<int, vector<int>, greater<int> > arr;
		int val = 0;
		
		while(n--) {
			int temp;
			cin >> temp;
			arr.push(temp);
		}
		
		// cout << "size " << arr.size() << endl;
		while (!arr.empty()) {
			int a = arr.top(); arr.pop();
			if (arr.empty()) {
				break;
			}
			int b = arr.top(); arr.pop();
			val += (a+b);
			arr.push(a+b);
		}
		
		cout << val << endl;
		
	}
}