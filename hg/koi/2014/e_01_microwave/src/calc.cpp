#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	if (t % 10 != 0) {
		cout << -1 << endl;
		return 0;
	}
	int m300, m60, m10;
	m300 = m60 = m10 = 0;
	
	m300 = t/300;
	t %= 300;
	m60 = t/60;
	t %= 60;
	m10 = t/10;
	cout << m300 << ' ' << m60 << ' ' << m10 << endl;
	return 0;
}