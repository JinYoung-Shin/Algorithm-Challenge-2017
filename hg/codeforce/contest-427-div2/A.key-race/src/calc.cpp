#include <iostream>

using namespace std;

int main() {
	int s, v1, v2, t1, t2;
	int elap1 = 0, elap2 = 0;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	
	elap1 = s*v1 + t1*2;
	elap2 = s*v2 + t2*2;
	
	if (elap1 == elap2) {
		cout << "Friendship";
	} else if (elap1 < elap2) {
		cout << "First";
	} else {
		cout << "Second";
	}
	
	cout << endl;
	return 0;
	
}