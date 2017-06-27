#include <iostream>
#include <algorithm>
#define GET(x, y) ( ( ((x)+1) * ((y)+1) * ((x)+(y)) ) / 2)
using namespace std;

int m, b;
int x_slice;
//x절편은 m*b
int main() {
	cin >> m >> b;
	x_slice = m*b;
	long long ans = 0;
	for (int x=0; x <= x_slice; x++) {
		long long y = b;
		if (x % m == 0) {
			y -= (x/m);
		} else {
			y -= ((x/m) + 1);
		}
		ans = max(ans, GET(x, y));
	}
	
	cout << ans << endl;
}