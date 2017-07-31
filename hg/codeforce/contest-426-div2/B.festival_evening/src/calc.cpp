#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool opened[26];
int open_time[26];
int close_time[26];
int num_guest, num_guard;

int get_max_opened() {
	int ret = 0;
	for (int day = 0; day <= num_guest; day++) {
		int cur = 0;
		for (int ch = 0; ch < 26; ch++) {
			if (opened[ch]) {
				if (open_time[ch] <= day && day <= close_time[ch]) {
					cur++;
				}
			}
		}
		ret = max(cur, ret);
	}
	return ret;
}

int main() {
	string seq;
	
	cin >> num_guest >> num_guard;
	cin >> seq;
	for (int i=0; i < num_guest; i++) {
		char ch = seq.at(i);
		if (opened[ch-'A'] == false) {
			opened[ch-'A'] = true;
			open_time[ch-'A'] = i;
			close_time[ch-'A'] = i;
		} else {
			close_time[ch-'A'] = i;
		}
	}
	
	cout << ( (get_max_opened() > num_guard) ? "YES" : "NO") << endl;
}