#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define is_in(x, y) ((x)>=0 && (y)>=0 && (x)<5 && (y)<5)
const int dx[] = {-1, -1, -1, +0, +0, +1, +1, +1};
const int dy[] = {-1, +0, +1, -1, +1, -1, +0, +1};
char map[5][5];
bool dp[5][5][11];
bool chk[5][5][11];

bool is_found(int x, int y, int len, string& str) {
	if (!is_in(x, y)) {
		return false;
	}
	if (len >= str.length()) {
		return true;
	}
	if (chk[x][y][len]) {
		return dp[x][y][len];
	}
	char ch = str[len];
	if (map[x][y] == ch) {
		bool ret = false;
		for (int i=0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			ret |= is_found(nx, ny, len+1, str);
		}
		chk[x][y][len] = true;
		return dp[x][y][len] = ret;
	} else {
		chk[x][y][len] = true;
		return dp[x][y][len] = false;
	}
}
int main() {
	int t_num, word_num;
	cin >> t_num;
	for (int i=0; i < t_num; i++) {
		for (int j=0; j < 5; j++) {
			for (int k=0; k<5; k++) {
				cin >> map[j][k];
			}
		}
		cin >> word_num;
		for (int j = 0;j < word_num; j++) {
			string str;
			cin >> str;
			memset(&chk[0][0][0], 0, sizeof(bool) * 5 * 5 * 11);
			bool val = false;
			for (int x=0; x < 5; x++) {
				for (int y=0; y < 5; y++) {
					val |= is_found(x, y, 0, str);
				}
			}
			cout << str << ' ' << (val ? "YES" : "NO") << endl;
		}
	}
}