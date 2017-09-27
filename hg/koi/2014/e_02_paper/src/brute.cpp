#include <iostream>

using namespace std;

int map[102][102];
int sz[101];
int n;
int main() {
	cin >> n;
	int sx, sy, dx, dy;
	for (int i=1; i <= n; i++) {
		cin >> sx >> sy >> dx >> dy;
		dx += sx;
		dy += sy;
		for (int x=sx; x < dx; x++) {
			for (int y=sy; y <dy; y++) {
				map[x][y] = i;
			}
		}
	}
	
	for (int i=0; i < 101; i++) {
		for (int j=0; j < 101; j++) {
			if (map[i][j]) {
				sz[ map[i][j] ]++;
			}
		}
	}
	for (int i=1; i <= n; i++) {
		cout << sz[i] << endl;
	}
}