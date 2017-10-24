#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

//string arr[1001];
vector<string> arr;
bool chk[26];
vector<int> idx;

string str;
int n, m;
bool possible(string& cmp) {
	for (int i=0; i < n; i++) {
		if (str[i] != '*') {
			if (str[i] != cmp[i]) return fals
		}
	}
	return true;
}
int main() {
	cin >> n >> str >> m;
	arr.reserve(m);
	idx.reserve(n);
	for (int i=0; i < n; i++) {
		char ch = str[i];
		if (ch == '*') {
			idx.push_back(i);
		} else {
			chk[ch-'a'] = true;
		}
	}
	for (int i=0; i < m; i++) {
		// cin >> arr[i];
		string tmp;
		cin >> tmp;
		bool check = true;
		for (unsigned int j=0; j < idx.size(); j++) {
			if (chk[tmp[idx[j]] - 'a']) {
				check = false;
				break;
			}
		}
		if (check && possible(tmp)) {
			arr.push_back(tmp);
		}
	}
	
	
	int ans = 0;
	for (int i=0; i< 26; i++) {
		if (chk[i]) continue; //이미 revealed된 char는 제외.
		char ch = 'a' + i; //요 글자가
		bool eval = true;
		for (unsigned int j=0; j < arr.size(); j++) { // 아는 단어별로
			bool inclusion = false;
			for (unsigned int k=0; k < idx.size(); k++) {
				if(arr[j][idx[k]] == ch) {
					inclusion = true;
					break;
				}
			}
			if (inclusion == false) {
				eval = false;
				break;
			}
		}
		if (eval) ans++;
	}
	
	cout << ans << endl;
	
}