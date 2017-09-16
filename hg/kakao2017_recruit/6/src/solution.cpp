#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
static int map[30][30];
static bool era[30][30];
const int dx[] = {0, 0, +1, +1};
const int dy[] = {0, +1, 0, +1};

int erase(int m, int n) {
	int ret = 0;
	for (int i=0; i < m-1; i++) {
		for (int j=0; j < n-1; j++) {
			auto& a1 = map[i][j];
			auto& a2 = map[i+1][j];
			auto& a3 = map[i][j+1];
			auto& a4 = map[i+1][j+1];
			auto& b1 = era[i][j];
			auto& b2 = era[i+1][j];
			auto& b3 = era[i][j+1];
			auto& b4 = era[i+1][j+1];
			if (a1 && a1 == a2 && a2 == a3 && a3 == a4) {
				// a1 = a2 = a3 = a4 = 0;
				b1 = b2 = b3 = b4 = true;
				ret = true;
			}
		}
	}
	for (int i=0; i < m; i++) {
		for (int j=0; j < n; j++) {
			if (era[i][j]) {
				ret++;
				map[i][j] = 0;
				era[i][j] = false;
			}
		}
	}
	return ret;
}
bool gravity(int m, int n) {
	bool ret = false;
	for (int i = 0; i < m-1; i++) {
		for (int j =0; j < n; j++) {
			if (map[i+1][j] == 0 && map[i][j] != 0) {
				map[i+1][j] = map[i][j];
				map[i][j] = 0;
				ret = true;
			}
		}
	}
	return ret;
}
void dump(int m, int n) {
	for (int i=0;i<m; i++) {
		for (int j=0;j <n;j++) {
			if (map[i][j] == 0) {
				cout << '-';
			} else {
				printf("%c", map[i][j]);
			}
		}
		cout << endl;
	}
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
	for (int i=0; i < m; i++) {
		for (int j=0; j < n; j++) {
			map[i][j] = board[i][j];
		}
	}
	// dump(m, n); cout << endl;
	while(true) {
		int delta = erase(m, n);
		// dump(m, n); cout << endl;
		if (delta > 0) {
			while(gravity(m, n));
			// dump(m, n); cout << endl;
		} else {
			break;
		}
	}
	for (int i=0; i < m; i++) {
		for (int j=0; j< n;j++) {
			if (map[i][j] == 0) {
				answer++;
			}
		}
	}

	// dump(m, n); cout << endl;
	
    return answer;
}
