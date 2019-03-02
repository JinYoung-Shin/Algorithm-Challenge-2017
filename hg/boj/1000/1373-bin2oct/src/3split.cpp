#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

int oct2int(string& str) {
	int ret = 0;
	int val = 1;
	for (int i = str.length()-1; i >= 0; i--) {
		if (str[i] == '1') ret += val;
		val *= 2;
	}
	return ret;
}
stack<int> ss;
int main() {
	string bin;
	cin >> bin;
	size_t len = bin.length();
	for (int i=len-1; i>=0; i-=3) {
		int idx = i-2;
		int num = 3;
		while (idx < 0) {
			num--;
			idx++;
		}
		string segment = bin.substr(idx, num);
		// cout << segment << endl;
		ss.push(oct2int(segment));
		// cout << oct2int(segment) << endl;
	}
	while (!ss.empty()) {
		cout << ss.top();
		ss.pop();
	}
	cout << '\n';
	
}