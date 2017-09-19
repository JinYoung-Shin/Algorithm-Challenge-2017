#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
int n;
int d;

bool chk_arithmetic() {
	for (int i=0; i < n-1; i++) {
		if (arr[i+1] -  arr[i] != d) {
			return false;
		}		
	}
	return true;
}
int main() {
	cin >> n;
	bool is_arithmetic = true;
	for (int i=0; i < n; i++) {
		cin >> arr[i];
	}
	d = arr[1] - arr[0];
	is_arithmetic = chk_arithmetic();
	if (is_arithmetic)
		cout << arr[n-1] + d << endl;
	else
		cout << arr[n-1] << endl;
	
}