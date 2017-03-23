#include <cstdio>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int row, column;

vector<vector<char> > map;

void dump_map() {
	printf("-----------------------\n");
	for (int i=0;i<row;i++) {
		for(int j=0;j<column;j++) {
			printf("%c", map[i][j]);
		}
		putchar('\n');
	}
	printf("-----------------------\n");
};
bool out_of_range_kk(int x,int y) {
	if (x >= 0 && x < row && y>=0 && y < column) {
		return false;
	} else {
		return true;
	}
}

bool find(int x, int y) {
	if (out_of_range_kk(x,y)) {
		return false;
	}
	
	if (map[x][y] == '0') {
		map[x][y] = '2';
		return find(x-1, y) || find(x, y-1) || find(x+1, y) || find(x, y+1);
	} else {
		return false;
	}
}

int main() {
	scanf("%d %d\n", &row, &column);
	map.reserve(row);
	for (int i=0; i<row;i++) {
		map[i].reserve(column);
	}
	for (int i=0;i<row;i++) {
		for (int j=0;j<column;j++) {
			scanf("%c", &map[i][j]);
		}
		scanf("\n");
	}
	// dump_map();
	for (int i=0; i<column;i++) {
		find(0, i);
	}
	for (int i=0; i<column;i++) {
		if (map[row-1][i] == '2') {
			cout << "YES" << endl;
			// dump_map();
			return EXIT_SUCCESS;
		}
	}
	cout << "NO" << endl;
	return EXIT_SUCCESS;
	
}