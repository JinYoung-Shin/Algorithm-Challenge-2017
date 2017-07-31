#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int map[101][101][11]; //x좌표 / y좌표 / 시작밝기 -> 누적합 버전
int main() {
	int n, q, c; //별의 개수, 별 바라보는 회수, 별의 최대밝기
	
	cin >> n >> q >> c;
	for (int i=0; i < n; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		map[a][b][c]++;
	}
	
	for (int s=0; s < 11; s++) {
		for (int x=0; x < 101; x++) {
			for (int y=0; y < 100; y++) {
				map[x][y+1][s] += map[x][y][s];
			}
		}
	}
	for (int s=0; s < 11; s++) {
		for (int x=0; x < 101; x++) {
			for (int y=0; y < 100; y++) {
				map[y+1][x][s] += map[y][x][s];
			}
		}
	}
	
	while(q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		int sum=0;
		
		for (int src_bright = 0; src_bright < 11; src_bright++) {
			int add = (src_bright + t) % (c+1);
			int num = map[x2][y2][src_bright] - map[x1-1][y2][src_bright] - map[x2][y1-1][src_bright] + map[x1-1][y1-1][src_bright];
			sum += add*num;
		}
		cout << sum << endl;
	}
}