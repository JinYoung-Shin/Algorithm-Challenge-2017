#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef set<int>::iterator ITR;
set<int> candid;
vector<int> candid_arr;
vector<int> mapper;
vector<bool> flag;
int k, n; //candid의 수, mapper의 수

void dump_set() {
	for(ITR ptr = candid.begin(); ptr != candid.end(); ptr++) {
		cout << *ptr << ' ';
	}
	cout << endl;
}
void dump_mapper() {
	for (int i=0; i < mapper.size(); i++) {
		cout << mapper[i] << ' ';
	}
	cout << endl;
}
int get_ans() {
	int cnt = 0;
	for (ITR ptr = candid.begin(); ptr != candid.end(); ptr++) {
		int bias = *ptr - mapper[0];
		bool failed = false;
		// cout << "bias : " << bias << endl;
		for (int i=1; i < n; i++) {
			if (candid.find(mapper[i] + bias) == candid.end()) {
				failed = true;
				break;
			}
		}
		if (failed == false) {
			cnt++;
		}
	}
	return cnt;
}
int main() {
	int val = 0;
	cin >> k >> n;
	candid_arr.reserve(k);
	mapper.reserve(n);
	flag.resize(k, false);
	for (int i=0; i < k; i++) {
		int cur;
		cin >> cur;
		val += cur;
		candid.insert(val);
	}
	for (int i=0; i < n; i++) {
		int tmp;
		cin >> tmp;
		mapper.push_back(tmp);
	}
	// dump_set();
	cout << get_ans() << endl;
	
	// for(set<int>::iterator ptr = candid.begin(); ptr != candid.end(); ptr++) {
	// 	candid_arr.push_back(*ptr);
	// }
	// sort(candid_arr.begin(), candid_arr.end());
	// sort(mapper.begin(), mapper.end());
	// dump_set();
	// for (int i=0; i < candid_arr.size(); i++) {
	// 	cout << candid_arr[i] << ' ';
	// }
	// cout << endl;
	// dump_mapper();
}