#include <iostream>
#include <string>

using namespace std;

typedef enum {
	NopeX, NopeY, RX, RY
} State;

int main() {
	int T;
	
	cin >> T;
	bool x, y;
	State state;
	while(T--) {
		string seq;
		x = true;
		y = true;
		state = NopeX;
		cin >> seq;
		int len = seq.length();
		
		if (seq[len-1] == 'R')
			state = RX;
		
		for (int i=0; i < seq.length(); i++) {
			if (seq[i] == 'L') {
				if (state == RX) {
					state = NopeY;
				} else if (state == RY) {
					state = NopeX;
				} else if (state == NopeX) {
					state = NopeY;
				} else if (state == NopeY) {
					state = NopeX;
				}
			} else if (seq[i] == 'R') {
				if (state == NopeX) {
					state = RY;
				} else if (state == NopeY) {
					state = RX;
				} else if (state == RX) {
					state = RY;
					x = false;
				} else if (state == RY) {
					state = RX;
					y = false;
				}
			}
		}
		
		cout << (x&&y ? 2 : (!x && !y) ? 0 : 1) << endl;
	}
}