#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> dup;
vector<string> str_set;
int main() {
	int n;
	cin >> n;
	str_set.reserve(n);
	
	for (int i=0;i < n; i++) {
		string str;
		cin >> str;
		str_set.push_back(str);
	}
	
	for (int i=0; i < n;i++) {
		for (int l=1; l < 10; l++) {
			for (int s=0; s < 10-l; s++) {
				string s_str = str_set[i].substr(s, l); //substring 죄다 마킹해버리기
				if (dup.find(s_str) == dup.end()) {
					dup[s_str] = i;
				} else {
					if (dup[s_str] != i && dup[s_str] != -1) {
						dup[s_str] = -1;
					}
				}
				// cout << s_str << endl;
			}
		}
	}
	
	for (int i=0; i < n; i++) {
		for (int l=1; l < 10; l++) {
			for (int s=0; s < 10-l; s++) {
				string s_str = str_set[i].substr(s, l);
				if (dup[s_str] == i) {
					cout << s_str << endl;
					goto next_stage;
				}
			}
		}
		next_stage:
		continue;
	}
	
	// for (map<string, int>::iterator ptr = dup.begin(); ptr != dup.end(); ptr++) {
	// 	string key = ptr->first;
	// 	int val = ptr->second;
	// 	cout << key << '-' << val << endl;
	// }
}