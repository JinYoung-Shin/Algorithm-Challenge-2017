#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

bool _binary_search(vector<int>::iterator start, vector<int>::iterator end, int val) {
	if (end - start == 1) {
		if (*start == val) return true;
		else return false;
	}
		
	if (end <= start) return false;
	int len = (end - start)/2;
	vector<int>::iterator mid = start + len;
	if (*mid == val) {
		return true;
	} else if (*mid < val) {
		return _binary_search(mid, end, val);
	} else {
		return _binary_search(start, mid, val);
	}
}
int main() {
	int n, m;
	//cin >> n;
	scanf("%d", &n);
	arr.reserve(n);
	for (int i=0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		//cin >> tmp;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(), arr.end());
	cin >> m;
	for (int i=0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		// cin >> tmp;
		if (_binary_search(arr.begin(), arr.end(), tmp)) {
			putchar('1');
			// cout << 1;
		} else {
			putchar('0');
			// cout << 0;
		}
		putchar('\n');
		// cout << endl;
	}
	
}