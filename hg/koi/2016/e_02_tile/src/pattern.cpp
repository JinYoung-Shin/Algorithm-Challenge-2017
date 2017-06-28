#include <iostream>

using namespace std;
typedef long long ll;
int main() {
	ll x = 1, y = 1;
	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		if (i & 1) {
			y += x;
		} else {
			x += y;
		}
	}
	
	cout << ((x+y)<<1) << endl;
}