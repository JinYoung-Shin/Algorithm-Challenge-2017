#include <iostream>
#include <unordered_set>
using namespace std;

int arr[2002][2];
unordered_set<int> s;
int main() {
	int n;
	cin >> n;
	for (int i=0;i < 2; i ++) {
		for (int j=0; j< n; j++) {
			cin >> arr[j][i];
			s.insert(arr[j][i]);
		}
	}
	
	bool even = true;
	for (int i=0; i < n; i++) {
		for (int j=0; j < n; j++) {
			auto& xi = arr[i][0];
			auto& yi = arr[j][1];
			int val = (xi ^ yi);
			if (s.find(val) != s.end()) {
				even = !even;
			}
		}
	}
	
	cout << (even ? "Karen" : "Koyomi") << endl;
}