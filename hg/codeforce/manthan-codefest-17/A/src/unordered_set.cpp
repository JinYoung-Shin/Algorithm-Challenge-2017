#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

unordered_set<string> chk;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (chk.find(str) == chk.end()) {
			cout << "NO" << endl;
			chk.insert(str);
		} else {
			cout << "YES" << endl;
		}
	}
}