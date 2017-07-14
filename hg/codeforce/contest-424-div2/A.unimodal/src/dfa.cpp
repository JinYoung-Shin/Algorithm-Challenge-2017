#include <iostream>

using namespace std;

int main() {
	int N;
	
	cin >> N;
	if (N == 1) {
		cout << "YES" << endl;
		return 0;
	}
	int state = 1;
	int prev;
	int delta;
	cin >> prev;
	for (int i=1; i < N; i++) {
		int cur;
		cin >> cur;
		delta = cur - prev; //  양수면 증가, 0이면 constant, 음수면 감소
		prev = cur;
		if (state == 1) {
			if (delta > 0) {
				
			} else if (delta == 0) {
				state = 2;
			} else if (delta < 0) {
				state = 3;
			}
		} else if (state == 2) {
			if (delta > 0) {
				cout << "NO" << endl;
				return 0;
			} else if (delta == 0) {
				
			} else if (delta < 0) {
				state = 3;
			}
		} else if (state == 3) {
			if (delta > 0) {
				cout << "NO" << endl;
				return 0;
			} else if (delta == 0) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
}