#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

bool chk[15001];
vector<int> arr;
int main() {
	int num_choo;
	cin >> num_choo;
	for (int i=0; i < num_choo; i++) {
		int w;
		cin >> w;
		arr.clear();
		arr.push_back(w);
		for (int j=1; j <= 15000; j++) {
			if (chk[j]) {
				if (j + w <= 15000) {
					arr.push_back(j+w);
				}
				if (w - j > 0) {
					arr.push_back(w - j);
				}
				if (j - w > 0) {
					arr.push_back(j - w);
				}
			}
		}
		for (unsigned int j=0; j < arr.size(); j++) {
			chk[arr[j]] = true;
		}
	}
	
	///debug
	// for (int i=0; i < 10; i++) {
	// 	printf("[%d] = %s\n", i, chk[i] ? "가능" : "불가능");
	// }
	//debug
	int num_test;
	cin >> num_test;
	for (int i=0; i < num_test; i++) {
		int target;
		cin >> target;
		if (chk[target]) {
			cout << 'Y' << ' ';
		} else {
			cout << 'N' << ' ';
		}
	}
	cout << endl;
}