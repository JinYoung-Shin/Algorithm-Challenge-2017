#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

int row, col;
vector<vector<char> > map;

class cord {
	public:
	int x,y;
	
	// bool operator=(const cord& right) const {
	// 	return x == right.x && y == right.y;
	// }
};
stack<cord> opened;

void dump();
bool is_out(int, int);
void add_adjacent(int, int);
int main() {
	cord temp_cord;
	int cur_x, cur_y;
	scanf("%d %d\n", &row, &col);
	map.reserve(row);
	for (int i=0;i<row;i++) {
		map[i].reserve(col);
	}
	for (int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			scanf("%c", &map[i][j]);
		}
		scanf("\n");
	}
	
	//stack 초기화
	temp_cord.x = 0;
	for (int i=0;i<col;i++) {
		if (map[0][i] == '0') {
			temp_cord.y = i;
			opened.push(temp_cord);
		}
	}
	while(!opened.empty()) {
		temp_cord = opened.top();
		opened.pop();
		cur_x = temp_cord.x;
		cur_y = temp_cord.y;
		if (map[cur_x][cur_y] == '0') {
			map[cur_x][cur_y] = '2';
			//check to visited
			add_adjacent(cur_x, cur_y);
		}
		// dump();
		if (cur_x == row - 1) {
			cout << "YES" << endl;
			return EXIT_SUCCESS;
		}
	};
	cout << "NO" << endl;
}

void dump() {
	printf("--------------------------------\n");
	for (int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------\n");
}
bool is_out(int x, int y) {
	if (x >=0 && x < row && y >=0 && y < col) {
		return false;
	}
	return true;
}
void add_adjacent(int x, int y) {
	int dx[] = {-1, 0, 0, 1};
	int dy[] = {0, -1, 1, 0};
	int new_x, new_y;
	cord temp_cord;
	for (int i=0;i<4;i++) {
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (is_out(new_x, new_y)) {
			continue;
		}
		if (map[new_x][new_y] == '0') {
			temp_cord.x = new_x;
			temp_cord.y = new_y;
			opened.push(temp_cord);
		}
	}
};