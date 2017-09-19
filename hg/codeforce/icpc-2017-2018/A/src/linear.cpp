#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> P;

bool chk[102];
int n;
int found = 0;

int find_first() { //discover 안된놈 idx찾는 함수
	if (found >= n) return -1;
	for (int i=1; i <= n; i++) {
		if (chk[i] == false)
			return i;
	}
	return -1;
}
int main() {
	cin >> n;
	vector<P> arr; // l, r정보들
	vector<P> lists;
	
	arr.reserve(n+1);
	//dummy data injection
	P p;
	p.first = -1;
	p.second = -1;
	arr.push_back(p);
	//dummy data injection
	for (int i=0; i < n;i++) {
		P p;
		cin >> p.first >> p.second;
		arr.push_back(p);
	}
	
	//dump
	// for (int i=1;i <= n; i++) {
	// 	cout << arr[i].first << ' ' << arr[i].second << endl;
	// }
	//dump
	
	while(true) {
		int cur_idx = find_first();
		if (cur_idx == -1) break;
		P p;
		p.first = p.second = cur_idx;
		found++;
		chk[cur_idx] = true;
		int l = arr[p.first].first;
		int r = arr[p.second].second;
		
		while (l != 0) {
			found++;
			chk[l] = true;
			p.first = l;
			l = arr[p.first].first;
		}
		while (r != 0) {
			found++;
			chk[r] = true;
			p.second = r;
			r = arr[p.second].second;
		}
		lists.push_back(p);
	}
	//dump
	// cout << "____________________________" << endl;
	// for (int i=0; i < lists.size(); i++) {
	// 	cout << lists[i].first << ' ' << lists[i].second << endl;
	// }
	// cout << "____________________________" << endl;
	//dump
	
	if (lists.size() > 1) {
		for (int i=0; i < lists.size() - 1; i++) {
			int tail_idx = lists[i].second;
			int head_idx = lists[i+1].first;
			arr[tail_idx].second = head_idx;
			arr[head_idx].first = tail_idx;
		}
	}
	
	//print answer
	for (int i=1;i <= n; i++) {
		cout << arr[i].first << ' ' << arr[i].second << endl;
	}
}