#include <iostream>

using namespace std;

int main() {
	int l, r;
	int answer = 2;
	
	cin >> l >> r;
	
	if (r - l < 2) {
		answer = l;
	}
	
	cout << answer << endl;
}