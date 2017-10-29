#include <iostream>

using namespace std;

int main() {
	int n, x, acc = 0;
	cin >> n >> x;
	for (int i=0; i < n ;i++) {
		int tmp;
		cin >> tmp;
		acc += tmp;
	}
	int min = acc + (n-1);
	if (x == min) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	cout << '\n'; return 0;
}