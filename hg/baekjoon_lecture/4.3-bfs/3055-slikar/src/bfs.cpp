#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

int row, col;
typedef pair<int, int> pos;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};

queue<pos> flood_open;
queue<pos> beaver_open;
pos goal;

int cost;
vector<vector<char> > map;

void dump_map() {
	cout << "----------------------" << endl;
	for(int i=0; i < row;i++) {
		for (int j=0;j<col;j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
}

bool is_out(int x, int y) {
	return x < 0 || y < 0 || x >= row || y >= col;
}

bool is_beaver_alive() {
	for (int i=0; i < row; i++) {
		for (int j=0; j < col; j++) {
			if (map[i][j] == 'S') {
				return true;
			}
		}
	}
	return false;
}
int main() {
	vector<char> single_row;
	char temp;
	int flood_iter, beaver_iter;
	int x, y, newx, newy;
	scanf("%d %d\n", &row, &col);
	
	for(int i=0; i< row ;i++) {
		single_row.clear();
		for (int j=0;j<col;j++) {
			scanf("%c", &temp);
			if (temp == 'D') {
				goal.first = i;
				goal.second = j;
			} else if (temp == 'S') {
				beaver_open.push(pos(i, j));
			} else if (temp == '*') {
				flood_open.push(pos(i, j));
			}
			single_row.push_back(temp);
		}
		map.push_back(single_row);
		scanf("\n");
	}
	
	while (true) {
		// dump_map();
		cost++;
		beaver_iter = beaver_open.size();
		for (int i=0 ; i < beaver_iter; i++) {
			x = beaver_open.front().first;
			y = beaver_open.front().second;
			beaver_open.pop();
			if (map[x][y] == 'S') {
				for (int dir = 0; dir < 4; dir++) {
					newx = x + dx[dir];
					newy = y + dy[dir];
					if (is_out(newx, newy)) {
						continue;
					}
					if (map[newx][newy] == '.') {
						beaver_open.push(pos(newx, newy));
						map[newx][newy] = 'S';
					} else if (map[newx][newy] == 'D') {
						cout << cost << endl;
						return EXIT_SUCCESS;
						
					}
				}
			}
		}
		flood_iter = flood_open.size();
		for (int i=0 ; i < flood_iter; i++) {
			x = flood_open.front().first;
			y = flood_open.front().second;
			flood_open.pop();
			for (int dir = 0; dir < 4; dir++) {
				newx = x + dx[dir];
				newy = y + dy[dir];
				if (is_out(newx, newy)) {
					continue;
				}
				if (map[newx][newy] == '.') {
					flood_open.push(pos(newx, newy));
					map[newx][newy] = '*';
				} else if (map[newx][newy] == 'S') {
					map[newx][newy] = '*';
					if(!is_beaver_alive()) {
						cout << "KAKTUS" << endl;
						return EXIT_SUCCESS;
					}
					flood_open.push(pos(newx, newy));
				}
			}
		}
		// dump_map();
		
		if (flood_open.empty() && beaver_open.empty()) {
			break;
		}
	}
	
}