#include <iostream>
#include <cstdio>
using namespace std;

char map[21][21];
int num_tc, H, W, num_white;
// # 까만칸(놓을 수 없는 곳) 
// . 흰칸(놓을 수 있는 곳)
#define is_in(x, y, H, W) ((x) >= 0 && (y) >= 0 && (x) < (H) && (y) < (W))
const int dx[4][3] = {
	{+0, +1, +0},
	{+0, +0, +1},
	{+0, +0, -1},
	{+0, +0, -1}
};
const int dy[4][3] = {
	{+0, +0, +1},
	{+0, -1, +0},
	{+0, -1, +0},
	{+0, +1, +0}
	
};
bool test(int x, int y, int type) {
	bool ret = true;
	for (int i=0; i < 3; i++) {
		int nx = x + dx[type][i];
		int ny = y + dy[type][i];
		if (!is_in(nx, ny, H, W) || map[nx][ny] != 0) {
			//do nothing
			return false;
		}
	}
	return true;
}
void set(int x, int y, int type, int delta) {
	for (int i=0; i < 3; i++) {
		int nx = x + dx[type][i];
		int ny = y + dy[type][i];
		map[nx][ny] += delta;
	}
}

void dump_map() {
	for (int x = 0; x < H ; x++) {
			for (int y=0; y < W; y++) {
				cout << (map[x][y] == 10 ? '#' : '.');
			}
			cout << endl;
		}
		cout << num_white << endl;
}

int get_ans(int x, int y) {
	printf("(%d, %d) called\n", x, y);
	int ret = 0;
	for (int i=0; i < 3; i++) {
		if (test(x, y, i)) {
			set(x, y, i, +10);
			num_white -= 3;
			if (num_white == 0) {
				ret++;
			}
			num_white += 3;
			set(x, y, i, -10);
		}
		
		int nx = x+1;
		int ny = y;
		if (nx > H) {
			nx = 0;
			ny++;
		}
		if (ny < W) {
			ret += get_ans(nx, ny);
		}
	}
	return ret;
}

int main() {
	cin >> num_tc;
	// for (int i=0; i < num_tc; i++) {
	for (int i=0; i < 1; i++) {
		num_white = 0;
		cin >> H >> W;
		
		for (int x = 0; x < H ; x++) {
			for (int y=0; y < W; y++) {
				char ch;
				cin >> ch;
				if (ch == '#') {
					map[x][y] = 10;
				} else if (ch == '.') {
					map[x][y] = 0;
					num_white++;
				}
			}
		}
		if (num_white % 3 != 0) {
			cout << 0 << endl;
		} else {
			cout << get_ans(0, 0) << endl;
		}
		//dump
		dump_map();
		//dump end
	}
}