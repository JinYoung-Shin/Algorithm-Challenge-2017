#include <iostream>
#include <cstdio>
using namespace std;

char map[25][25];
int num_tc, H, W, num_white;
// # 까만칸(놓을 수 없는 곳) 
// . 흰칸(놓을 수 있는 곳)
#define is_in(x, y, H, W) ((x) >= 1 && (y) >= 1 && (x) <= (H) && (y) <= (W))
const int dx[4][3] = {
	{+0, +1, +0},
	{+0, +1, +1},
	{+0, +1, +1},
	{+0, +0, +1}
};
const int dy[4][3] = {
	{+0, +0, +1},
	{+0, +0, -1},
	{+0, +0, +1},
	{+0, +1, +1}
	
};

void dump_map() {
	for (int x = 0; x <= H+1 ; x++) {
			for (int y=0; y <= W+1; y++) {
				printf("%hhd", map[x][y]);
			}
			cout << endl;
		}
		cout << num_white << endl;
}
bool set_and_test(int x, int y, int type, int delta) {
	// printf("set and test called(%d, %d, %d, %d)\n", x, y, type, delta);
	bool ret = true;
	for (int i=0; i < 3; i++) {
		int nx = x + dx[type][i];
		int ny = y + dy[type][i];
		if (!is_in(nx, ny, H, W)) ret = false;
		map[nx][ny] += delta;
		if (map[nx][ny] > 1) ret = false;
	}
	return ret;
}

int count() {
	int x = -1, y = -1;
	for (int i=1; i <= H; i++) {
		for (int j=1; j<= W; j++) {
			if (map[i][j] == 0) {
				x = i;
				y = j;
				goto escape;
			}
		}
	}
	escape:
	// printf("put pos(%d, %d)\n", x, y);
	if (x == -1) return 1; //basis case
	int ret = 0;
	for (int i=0; i < 4; i++) {
		if (set_and_test(x, y, i, +1)) {
		// dump_map();
			ret += count();
		} else {
			// dump_map();
		}
		set_and_test(x, y, i, -1);
		// dump_map();
	}
	return ret;
}


int main() {
	cin >> num_tc;
	for (int i=0; i < num_tc; i++) {
		for (int i=0; i < 1; i++) {
			num_white = 0;
			cin >> H >> W;

			for (int x = 1; x <= H ; x++) {
				for (int y=1; y <= W; y++) {
					char ch;
					cin >> ch;
					if (ch == '#') {
						map[x][y] = 1;
					} else if (ch == '.') {
						map[x][y] = 0;
						num_white++;
					}
				}
			}

			if (num_white % 3 != 0) {
				cout << 0 << endl;
			} else {
				cout << count() << endl;
			}

		}
	}
}