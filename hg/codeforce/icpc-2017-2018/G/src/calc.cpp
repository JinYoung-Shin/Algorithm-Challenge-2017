#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[7];

int main() {
	int n;
	int ans = 0;
	cin >> n;
	for (int i=0; i < n; i++) {
		string str;
		cin >> str;
		for (int j=0; j < 7; j++) {
			char ch = str[j];
			if (ch == '1') {
				arr[j]++;
			}
		}
	}
	
	for (int i=0; i < 7; i++) {
		// cout << arr[i];
		ans = max(ans, arr[i]);
	}
	// cout << endl;
	cout << ans << endl;
}