#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k, t;
	int ret = 0;
	
	cin >> n >> k >> t;
	if (t >= 0 && t <= k) {
		ret = t;
	} else if ( t <= n ) {
		ret = k;
	} else if ( t > n ) {
		ret = k - (t-n);
	} 
	
	cout << max(0, ret) << endl;
	return 0;
}