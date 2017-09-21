#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<bool> chk;
vector< vector<int> > ans;
int n;
int guaranteed = 0;
int unused_idx() {
	for (int i=guaranteed; i < n;i++) {
		if (chk[i] == false) {
			guaranteed = i;
			return i;
		}
	}
	return -1;
}
int main() {
	cin >> n;
	arr.reserve(n);
	int used = 0;
	chk.resize(n, false);
	for (int i=0; i < n;i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	while(used < n) {
		int idx = unused_idx();
		if (idx == -1) break;
		vector<int> tmp;
		int prev = arr[idx];
		
		chk[idx] = true;
		used++;
		tmp.push_back(prev);
		for (int i=idx; i < n; i++) {
			if (chk[i] == false && arr[i] > prev) {
				prev = arr[i];
				chk[i] = true;
				used++;
				tmp.push_back(prev);
			}
		}
		ans.push_back(tmp);
	}
	
	int l = ans.size();
	for (int i=0; i < l ;i++) {
		int l2 = ans[i].size();
		for (int j=0; j < l2; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
}