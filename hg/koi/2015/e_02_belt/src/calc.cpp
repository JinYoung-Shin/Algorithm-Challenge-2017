#include <iostream>

using namespace std;

int main() {
	int M;
	bool direction = false;
	int rot = 1;
	cin >> M;
	
	while (M--) {
		int a, b;
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