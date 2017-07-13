#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int ans = 0;
	while(N--) {
		int std, apple;
		cin >> std >> apple;
		int cnt = apple/std;
		int total = cnt * std;
		ans += apple - total;
	}
	cout << ans << endl;
}