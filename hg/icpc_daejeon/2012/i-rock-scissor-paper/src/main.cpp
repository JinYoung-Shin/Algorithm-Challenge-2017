#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> seq;
vector<bool> is_alive;

void kill_him(int stage, char a) {
	for (int i=0; i < seq.size(); i++) {
		if (seq[i][stage] == a) {
			is_alive[i] = false;
		}
	}
}
int get_alive_num() {
	int count = 0;
	for (int i =0; i < is_alive.size(); i++) {
		if (is_alive[i]) count++;
	}
	return count;
}
int get_winner_num() {
	for (int i=0; i < is_alive.size(); i++) {
		if (is_alive[i]) return i+1;
	}
}
char winner_checker(int stage) {
	bool rock, scissor, paper;
	rock = false;
	scissor = false;
	paper = false;
	for (int i=0; i < seq.size(); i++) {
		if (is_alive[i] == false) continue;
		if (seq[i][stage] == 'R') {
			rock = true;
		} else if (seq[i][stage] == 'S') {
			scissor = true;
		} else if (seq[i][stage] == 'P') {
			paper = true;
		}
		
	}
	if (rock && scissor & paper) {
		return 'N'; //draw
	}
	if (rock && scissor && !paper) {
		return 'R';
	}
	if (rock && !scissor && paper) {
		return 'P';
	}
	if (!rock && scissor && paper) {
		return 'S';
	}
	return 'N';
}
int main() {
	int t;
	
	cin >> t;
	
	while(t--) {
		int n, alive_num;
		cin >> n;
		seq.clear();
		seq.reserve(n);
		is_alive.clear();
		is_alive.resize(n, true);
		for (int i=0; i < n; i++) {
			string temp;
			cin >> temp;
			seq.push_back(temp);
		}
		int stage_len = seq[0].length();
		for (int i = 0; i < stage_len; i++) {
			char winner = winner_checker(i);
			if (winner == 'N') continue;
			if (winner == 'S') {
				kill_him(i, 'P');
			} else if (winner == 'R') {
				kill_him(i, 'S');
			} else if (winner == 'P') {
				kill_him(i, 'R');
			}
		}
		if (get_alive_num() == 1) {
			cout << get_winner_num() << endl;
		} else {
			cout << 0 << endl;
		}
		
	};
}