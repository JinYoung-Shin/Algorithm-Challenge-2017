#include <iostream>
#include <algorithm>
using namespace std;

#define DAY 86400
// int a[101];
int main() {
	int n, t;
	cin >> n >> t;
	for (int i=0; i <= n; i++) {
		if (i == n) {
			cout << (i+1) << endl;
			return 0;
		}
		int tmp;
		cin >> tmp;
		int done = DAY - tmp;
		done = max(done, 0);
		t -= done;
		if (t <= 0 || i == n) {
			cout << (i+1) << endl;
			return 0;
		}
	}
}