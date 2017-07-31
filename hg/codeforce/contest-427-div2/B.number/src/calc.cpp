#include <iostream>
#include <string>

using namespace std;

int candid[10];

int main() {
	int k;
	string str;
	int sum = 0;
	int ans = 0;
	
	cin >> k >> str;
	for (int i=0; i < str.length(); i++) {
		char ch = str[i];
		sum += (ch-'0');
		candid[9 - (ch-'0')]++;
	}
	
	
	int need_inc = k - sum; //요놈이 0이 되야함.
	int dec = 9;
	while (need_inc > 0) {
		if (candid[dec] > 0) {
			candid[dec]--;
			need_inc -= dec;
			ans++;
		} else {
			dec--;
		}
	}
	
	cout << ans << endl;
}