#include <cstdio>
#include <iostream>
using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int num;
int pos_first, pos_last;
bool is_cw() {
	return (pos_first + num) % 4 == pos_last;
}
bool is_ccw() {
	int val = pos_first - num;
	while (val < 0) {
		val += 10000000;
	}
	return val % 4 == pos_last;
}
int main() {
	char first, last;
	scanf("%c %c\n", &first, &last);
	cin >> num;
	if (first == 118) {
		pos_first = DOWN;
	} else if (first == 60) {
		pos_first = LEFT;
	} else if (first == 94) {
		pos_first = UP;
	} else if (first == 62) {
		pos_first = RIGHT;
	}
	
	if (last == 118) {
		pos_last = DOWN;
	} else if (last == 60) {
		pos_last = LEFT;
	} else if (last == 94) {
		pos_last = UP;
	} else if (last == 62) {
		pos_last = RIGHT;
	}
	
	//debug
	// printf("%d %d\n", pos_first, pos_last);
	// printf("%d %d\n", (pos_first+num) % 4, (pos_first - num) % 4  );
	if ( is_cw() && is_ccw() ) {
		cout << "undefined" << endl;
	} else {
		if ( is_cw() ) {
			cout << "cw" << endl;
		} else if ( is_ccw() ) {
			cout << "ccw" << endl;
		}	
	}
	
}