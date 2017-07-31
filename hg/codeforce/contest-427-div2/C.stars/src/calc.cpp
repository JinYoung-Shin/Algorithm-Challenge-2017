#include <iostream>
#include <vector>
using namespace std;

int map[101][101][11]; //x좌표 / y좌표 / 시작밝기 -> 개수
int main() {
	int n, q, c; //별의 개수, 별 바라보는 회수, 별의 최대밝기
	
	cin >> n >> q >> c;
	for (int i=0; i < n; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		map[a][b][c]++;
	}
	
	while(q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		int sum=0;
		for (int src_bright = 0; src_bright < 11; src_bright++) {
			int add = (src_bright + t) % (c+1);
			for (int xpos=x1; xpos <= x2; xpos++) {
				for (int ypos=y1; ypos <= y2; ypos++) {
					sum += add*map[xpos][ypos][src_bright];
				}
			}
		}
		cout << sum << endl;
	}
}