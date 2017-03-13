#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int map[100][100] = {0,};
int rect[4][4];

void dump();
int answer();
int main() {
	for (int i=0; i<4;i++) {
		scanf("%d %d %d %d\n", &rect[i][0], &rect[i][1], &rect[i][2], &rect[i][3]);
	}
	for (int i=0; i<4;i++) {
		for (int x=rect[i][0]; x < rect[i][2]; x++) {
			for(int y=rect[i][1]; y < rect[i][3]; y++) {
				map[x][y]++;
			}
		}
	}
	// dump();
	cout << answer() << endl;
}
int answer() {
	int count = 0;
	for(int i=0;i<100;i++) {
		for (int j=0;j<100;j++) {
			if (map[i][j]) {
				count++;
			}
		}
	}
	return count;
}
void dump() {
	//rect
	// for(int i=0;i<4;i++) {
	// 	for(int j=0;j<4;j++) {
	// 		printf("%d\t", rect[i][j]);
	// 	}
	// }
	
	for(int i=99;i>=0;i--) {
		for(int j=99;j>=0;j--) {
			printf("%d ", map[j][i]);
		}
		putchar('\n');
	}
}
