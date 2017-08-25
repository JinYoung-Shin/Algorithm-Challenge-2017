#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> pii;
vector<vector<int> > answer;
vector<bool> chk;
int n;
vector<pii> arr, sorted;
void checker(int i) {
	set<int> aset, bset;
	while (true) {
		aset.insert(arr[i].second);
		bset.insert(sorted[i].second);
		chk[i] = true;
		if (aset == bset) {
			vector<int> row;
			row.reserve(aset.size());
			for (set<int>::iterator ptr = aset.begin(); ptr != aset.end(); ptr++) {
				row.push_back(*ptr);
			}
			answer.push_back(row);
			return;
		} else {
			i = sorted[i].second - 1;
		}	
	}
}
int main() {
	cin >> n;
	
	arr.reserve(n);
	chk.resize(n, false);
	for (int i=0; i < n;i++) {
		int tmp;
		pii tp;
		cin >> tmp;
		tp.first = tmp;
		tp.second = i+1;
		arr.push_back(tp);
	}
	
	sorted = arr;
	sort(sorted.begin(), sorted.end());
	
	for (int i=0; i < n; i++) {
		if (chk[i]) continue;
		checker(i);
	}
	///answer dump
	cout << answer.size() << endl;
	for (int i=0; i < answer.size(); i++) {
		cout << answer[i].size() << ' ';
		for (int j=0; j < answer[i].size(); j++) {
			cout << answer[i][j] << ' ';
		}
		cout << endl;
	}
	
}