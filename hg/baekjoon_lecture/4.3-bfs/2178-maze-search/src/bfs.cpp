#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef struct _pos {
	int x, y, cost;
} pos;

int row, col;
vector<vector<char> > map;
queue<pos> open;

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
void dump() {
	cout << "====================================" << endl;
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			printf("%c", map[i][j]);
		}
		putchar('\n');
	}
	cout << "====================================" << endl;
}
bool is_in_bound(int x, int y) {
	return x >=0 && x < row && y >= 0 && y < col;
}
bool is_goal(int x, int y) {
	return x == row - 1 && y == col - 1;
}

int bfs() {
	pos current;
	int new_x, new_y;
	while(!open.empty()) {
		current = open.front();
		open.pop();
		
		if (is_goal(current.x, current.y)) {
			return current.cost;
		}
		
		for (int i=0; i< 4;i++) {
			new_x = current.x + dx[i];
			new_y = current.y + dy[i];
			if (is_in_bound(new_x, new_y) && map[new_x][new_y] == '1') {
				map[new_x][new_y] = '2';
				// dump();
				open.push(pos {new_x, new_y, current.cost + 1});
			}	
		}
	}
}
int main() {
	scanf("%d %d\n", &row, &col);
	map.reserve(row);
	for(int i=0; i < row;i++) {
		map[i].reserve(col);
	}
	
	for (int i=0; i < row; i++) {
		for (int j=0; j < col; j++) {
			scanf("%c", &map[i][j]);
		}
		scanf("\n");
	}
	
	open.push(pos {0, 0, 1});
	
	// dump();
	
	cout << bfs() << endl;
}