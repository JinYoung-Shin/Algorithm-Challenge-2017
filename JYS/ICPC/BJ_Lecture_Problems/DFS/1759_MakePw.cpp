#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
vector<char> cur;

bool check(vector<char> &pw) {
	int mo = 0, ja = 0;
	for(vector<char>::iterator it = pw.begin(); it < pw.end(); it++) {
		if(*it == 'a' ||  *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u') {
			mo++;
		} else {
			ja++;
		}
	}
	return mo >= 1 && ja >=2;
}

void go(vector<char> &a, vector<char> &pw, int i) {	
	if(pw.size() == n) {
		if(check(pw) == true) {
			for(vector<char>::iterator it = pw.begin(); it < pw.end(); it++) {
				cout << *it;
			}
			cout << endl;
		}
		return;
	}
	if(i == a.size()) return;
	pw.push_back(a[i]);
	go(a, pw, i+1);
	pw.pop_back();
	go(a, pw, i+1);
}
int main() {
	scanf("%d %d", &n, &m);
	vector<char> arr(m);
	for(int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	go(arr, cur, 0);
	return 0;
}