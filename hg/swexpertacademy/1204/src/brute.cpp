#include <iostream>
#include <vector>
using namespace std;

int main() {
	int dummy;
	for (int t =1; t <= 10; t++) {
		cin >> dummy;
		
		vector<int> arr;
		arr.resize(101, 0);
		for (int j=0; j < 1000;j++) {
			int a;
			cin >> a;
			arr[a]++;
		}
		int ans = 0;
		int tmp = arr[0];
		for (int j=1; j <= 100;j ++) {
			if (tmp <= arr[j]) {
				tmp = arr[j];
				ans = j;
			}
		}
		cout << '#' << t << ' ' << ans << endl;
	}
	
}