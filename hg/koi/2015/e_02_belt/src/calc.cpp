#include <iostream>

using namespace std;

typedef long long ll;
int main() {
	int M;
	bool direction = false;
	ll rot = 1;
	cin >> M;
	
	while (M--) {
		ll a, b;
		int dir;
		cin >> a >> b >> dir;
		rot *= b;
		rot /= a;
		if (dir == 1) {
			direction = !direction;
		}
	}
	cout << (direction == true ? "1" : "0") << " " << rot << endl;
}