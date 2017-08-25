#include <iostream>

using namespace std;

typedef long long ll;
int map[51][51];
int garo[51][2];
int sero[51][2];
ll pow[51];
bool pow_chk[51];
int n, m;
ll get_pow(int exp) {
	if (pow_chk[exp]) return pow[exp];
	ll ret;
	if (exp & 1) {
		ret = 2 * get_pow(exp-1);
	} else {
		ret = get_pow(exp/2) * get_pow(exp/2);
	}
	pow_chk[exp] = true;
	pow[exp] = ret;
	return ret;
}
bool is_unique(int row, int col) {
	int val = map[row][col];
	int row_cnt = 0;
	int col_cnt = 0;
	for(int i=0; i < n; i++) {
		if (map[i][col] == val) {
			row_cnt++;
		}
	}
	for (int j=0; j < m;j++) {
		if (map[row][j] == val) {
			col_cnt++;
		}
	}
	return row_cnt == 1 || col_cnt == 1;
	
}
int main() {
	pow_chk[0] = pow_chk[1] = true;
	pow[0] = 1;
	pow[1] = 2;
	ll answer = 0;
	cin >> n >> m;
	for (int i=0; i < n; i++) {
		for (int j=0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				garo[i][0]++;
				sero[j][0]++;
			} else {
				garo[i][1]++;
				sero[j][1]++;
			}
		}
	}
	for (int i=0; i < n; i++) {
		if (garo[i][0] > 1) {
			answer += get_pow(garo[i][0]) - 1 - garo[i][0];
		}
		if (garo[i][1] > 1) {
			answer += get_pow(garo[i][1]) - 1 - garo[i][1];
		}
	}
	for (int i=0; i < m; i++) {
		if (sero[i][0] > 1) { //원소가 한개짜리인거는 가로만 세도록 한다.
			answer += get_pow(sero[i][0]) - 1 - sero[i][0];
		}
		if (sero[i][1] > 1) {
			answer += get_pow(sero[i][1]) - 1 - sero[i][1];
		}
	}
	answer += m*n;
	
	cout << answer << endl;
	return 0;
}