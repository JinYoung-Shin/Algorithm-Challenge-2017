#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_palindrome(string& str) {
	int len = str.length();
	
	for (int i=0; i < len/2; i++) {
		if (str[i] == str[len-1 - i]) {
			
		} else {
			return false;
		}
	}
	return true;
}

vector<string> arr;
void chk(int n) {
	for (int i=0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			if (i==j) continue;
			string chker = arr[i] + arr[j];
			// cout << chker << endl;
			if (is_palindrome(chker)) {
				cout << chker << endl;
				return;
			}
		}
	}
		
	cout << 0 << endl;
}
int main() {
	int t;
	
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		arr.clear();
		arr.reserve(n);
		
		for (int i=0; i < n; i++) {
			string temp;
			cin >> temp;
			arr.push_back(temp);
		}
		chk(n);
		
	}
	
}