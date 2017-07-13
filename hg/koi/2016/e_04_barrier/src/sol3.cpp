#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef struct {
	int x, yl, yh;
} barPos;

typedef pair<int, int> meta;
bool operator<(barPos a, barPos b) {
	return a.x < b.x;
}

vector<barPos> barriers;
vector<int> answer;
set<meta> subp;
void dump_barrier() {
	cout << " --------------------------------------" << endl;
	for (int i=0; i < barriers.size(); i++) {
		cout << barriers[i].x << " " << barriers[i].yl << " " << barriers[i].yh << endl;
	}
	cout << " --------------------------------------" << endl;
}
void dump_subp() {
	for (set<meta>::iterator ptr = subp.begin(); ptr != subp.end(); ptr++) {
		cout << ptr->first << ", " << ptr->second << endl;
	}
}
int find_min_y() {
	int min_val = 98754321;
	for (set<meta>::iterator ptr = subp.begin(); ptr != subp.end(); ptr++) {
		min_val = min(min_val, ptr->second);
	}
	return min_val;
}
void set_answers(int min_val) {
	for (set<meta>::iterator ptr = subp.begin(); ptr != subp.end(); ptr++) {
		if (ptr->second == min_val) {
			answer.push_back(ptr->first);
		}
	}
}
int main() {
	int N;
	int srcY, finX;
	
	cin >> N >> srcY >> finX;
	barriers.reserve(N);
	
	for (int i=0; i < N; i++) {
		int x, yl, yh;
		
		cin >> x >> yl >> yh;
		barPos tmp;
		tmp.x = x;
		tmp.yl = yl;
		tmp.yh = yh;
		barriers.push_back(tmp);
	}
	sort(barriers.begin(), barriers.end());
	subp.insert(make_pair(srcY, 0));
	vector<set<meta>::iterator> delete_candidate;
	for (int i=0; i < N; i++) {
		auto upper_bound = barriers[i].yh;
		auto lower_bound = barriers[i].yl;
		delete_candidate.clear();
		int minl = 987654321;
		int minh = 987654321;
		for (set<meta>::iterator ptr = subp.lower_bound(make_pair(lower_bound, 0)); ptr != subp.upper_bound(make_pair(upper_bound, 0)); ptr++) {
			delete_candidate.push_back(ptr);
			minl = min(minl, ptr->second + (ptr->first - lower_bound));
			minh = min(minh, ptr->second + (upper_bound - ptr->first));
		}
		for (int j=0; j < delete_candidate.size(); j++) {
			subp.erase(delete_candidate[j]);
		}
		if (delete_candidate.size() > 0) {
			delete_candidate.clear();
			subp.insert(make_pair(upper_bound, minh));
			subp.insert(make_pair(lower_bound, minl));
		}
	}
	
	int min_y_val = find_min_y();
	set_answers(min_y_val);
	
	cout << finX + min_y_val << endl << answer.size();
	for (int i=0; i < answer.size(); i++) {
		cout << ' ' << answer[i];
	}
	cout << endl;
}