#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	set<char> Set;
	string s;
	int k;
	cin >> s >> k;
	int len = s.length();
	
	if (k > len) {
		cout << "impossible" << endl;
		return 0;
	}
	for (int i=0; i < len ; i++) {
		char ch = s[i];
		Set.insert(ch);
	}
	int cur = Set.size();
	cout << max(0, k - cur) << endl;
}