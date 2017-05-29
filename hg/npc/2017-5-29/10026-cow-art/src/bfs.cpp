#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

typedef pair<int, int> pos;

char map[100][100];
bool chk[100][100];
int N;
int remain;

const int dx[] = {+0, +0, -1, +1};
const int dy[] = {-1, +1, +0, +0};

queue<pos> Q;

void dump(int a) {
	if (a) {
		for(int i=0;i<N;i++) {
			for (int j=0;j<N;j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
	} else {
		for(int i=0;i<N;i++) {
			for (int j=0;j<N;j++) {
				cout << chk[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}

pos find() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (chk[i][j] == false) {
				return pos(i, j);
			}
		}
	}
}
bool is_out(int x, int y) {
	return x<0 || y<0 || x>=N || y>=N;
}

void clear(char color) {
	while(!Q.empty()) {
		int cx = Q.front().first;
		int cy = Q.front().second;
		Q.pop();
		remain--;
		for (int k = 0; k<4;k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (is_out(nx, ny)) continue;
			if (chk[nx][ny] == false && map[nx][ny] == color) {
				chk[nx][ny] = true;
				Q.push(pos(nx, ny));
			}
		}
	}
}

void clear2(char color) {
	if (color == 'R' || color == 'G') {
		while(!Q.empty()) {
			int cx = Q.front().first;
			int cy = Q.front().second;
			Q.pop();
			remain--;
			for (int k = 0; k<4;k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (is_out(nx, ny)) continue;
				if (chk[nx][ny] == false && (map[nx][ny] == 'R' || map[nx][ny] == 'G')) {
					chk[nx][ny] = true;
					Q.push(pos(nx, ny));
				}
			}
		}
	} else {
		clear(color);
	}
}
int count_area2() {
	int cnt = 0;
	while (remain > 0) {
		pos start = find();
		char color = map[start.first][start.second];
		//printf("(%d, %d)에서 시작함 - 색은 %c, 남은건 (%d) \n", start.first, start.second, color, remain);
		cnt++;
		// remain--;
		chk[start.first][start.second] = true;
		Q.push(start);
		clear2(color);
		//dump(0);
	}
	return cnt;
}
int count_area() {
	int cnt = 0;
	while (remain > 0) {
		pos start = find();
		char color = map[start.first][start.second];
		//printf("(%d, %d)에서 시작함 - 색은 %c, 남은건 (%d) \n", start.first, start.second, color, remain);
		cnt++;
		// remain--;
		chk[start.first][start.second] = true;
		Q.push(start);
		clear(color);
		//dump(0);
	}
	return cnt;
}

void init() {
	remain = N*N;
	for(int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			chk[i][j] = false;
		}
	}
}

int main() {
	cin >> N;
	remain = N*N;
	for (int i=0; i<N;i++) {
		for (int j=0;j<N;j++) {
			cin >> map[i][j];
		}
	}
	
	//dump(1);
	
	cout << count_area() << " ";
	init();
	cout << count_area2() << endl;
}