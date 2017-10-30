#include <iostream>

using namespace std;

bool map[501][501];
int main() {
	int h, w;
	cin >> h >> w;
	for (int i=0; i < w; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 0) {
			int idx = h-1;
			for (int j=0; j < tmp; j++) {
				map[idx][i] = true;
				idx--;
			}
		}
	}
	int ans = 0;
	for (int i=0; i < h; i++) {
		int id = -1;
		for (int j=0; j< w; j++) {
			if (map[i][j]) {
				if (id != -1) {
					ans += j - id - 1;
				}
				id = j;
			}
		}
		
	}
	cout << ans << endl;
	// cout << " =================== " << endl;
	// //dump
	// for (int i=0; i < h; i++) {
	// 	for (int j=0; j < w;j++) {
	// 		printf("%c", map[i][j] ? '1' : '0');
	// 	}
	// 	putchar('\n');
	// }
	//dump
}