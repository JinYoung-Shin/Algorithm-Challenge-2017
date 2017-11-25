#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll arr[20005];
int n;

ll solve(int start, int end) {
	ll ret = -9876543210;
	if (start == end) {
		return arr[start];
	}
	int mid = (start+end)/2;
	ret = max(solve(start, mid), solve(mid+1, end));
	int li = mid;
	int hi = mid+1;
	ll width = 2;
	ll height = min(arr[li], arr[hi]);
	while (true) {
		ret = max(ret, height * width);
		if (li <= start && hi >= end) break;
		if (li > start && hi < end) {
			//both case
			if (arr[li-1] > arr[hi+1]) {
				li--;
				height = min(height, arr[li]);
			} else {
				hi++;
				height = min(height, arr[hi]);
			}
		} else if (li > start) {
			li--;
			height = min(height, arr[li]);
		} else {
			hi++;
			height = min(height, arr[hi]);
		}
		width++;
	}
	return ret;
}
int main() {
	int c;
	cin >> c;
	while(c--) {
		cin >> n;
		for (int i=0; i < n; i++) {
			cin >> arr[i];
		}
		cout << solve(0, n-1) << '\n';
	}
	return 0;
}