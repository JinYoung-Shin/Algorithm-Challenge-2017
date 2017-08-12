#include <iostream>
using namespace std;

int main() {
	int n, k;
	int arya = 0;
	int bran = 0;
	
	cin >> n >> k;
	for (int i=1; i <= n;i++) {
		int get;
		cin >> get;
		arya += get;
		if (arya >= 8) {
			arya -= 8;
			bran += 8;
		} else {
			bran += arya;
			arya = 0;
		}
		if (bran >= k) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}