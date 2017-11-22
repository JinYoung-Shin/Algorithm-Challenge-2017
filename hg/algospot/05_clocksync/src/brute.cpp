#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define NUM_BTN 10
#define NUM_CLOCK 16
#define INF 987654321

vector<vector<int> > factor; // factor[i] i th btn affect clock No.

int btn_pressed[NUM_BTN]; //
int clock_direction[NUM_CLOCK];
int clock_tmp[NUM_CLOCK];
// int btn_tmp[NUM_BTN];

int ans;
void dump() {
	cout << '{';
	for (int i=0; i < NUM_BTN; i++) {
		cout << btn_pressed[i] << ' ';
	}
	cout << '}' << '\n';
}
bool test() { //check all direction is 12 o clock!
	for (int i=0; i < NUM_CLOCK; i++) {
		clock_tmp[i] = clock_direction[i];
	}
	for (int i=0; i < NUM_BTN; i++) {
		if (btn_pressed[i]) {
			for (size_t j=0; j < factor[i].size(); j++) {
				int clock_idx = factor[i][j];
				clock_tmp[clock_idx] += btn_pressed[i] * 3;
			}
		}
	}
	bool ret = true;
	for (int i=0; i < NUM_CLOCK; i++) {
		if (clock_tmp[i] % 12 != 0) {
			ret = false;
			break;
		}
	}
	return ret;
}
int get_val() {
	int ret = 0;
	for (int i=0; i < NUM_BTN; i++) {
		if (btn_pressed[i]) ret+=btn_pressed[i];
	}
	return ret;
}
void dfs(int idx) {
	if (idx >= NUM_BTN) {
		if (test()) {
			ans = min(ans, get_val());
			// dump();
		}
		return;
	}
	for (int i=0; i < 4; i++) {
		btn_pressed[idx] = i;
		dfs(idx+1);
	}
}
int main() {
	int C;
	factor.push_back({0, 1, 2});
	factor.push_back({3, 7, 9, 11});
	factor.push_back({4, 10, 14, 15});
	factor.push_back({0, 4, 5, 6, 7});
	factor.push_back({6, 7, 8, 10, 12});
	factor.push_back({0, 2, 14, 15});
	factor.push_back({3, 14, 15});
	factor.push_back({4, 5, 7, 14, 15});
	factor.push_back({1, 2, 3, 4, 5});
	factor.push_back({3, 4, 5, 9, 13});
	
	//dfs(0);
	cin >> C;
	for (int i=0; i < C; i++) {
		for (int j=0; j < NUM_CLOCK; j++) {
			cin >> clock_direction[j];
		}
		
		ans = INF;
		//dump
		// for (int j=0; j < NUM_CLOCK; j++) {
		// 	cout << clock_direction[j] << ' ';
		// }
		// cout << endl;
		//dump
		dfs(0);
		if (ans == INF) cout << -1;
		else cout << ans;
		cout << '\n';
		
	}
	
	return 0;
}