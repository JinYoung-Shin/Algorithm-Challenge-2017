#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
	unordered_set<int> Set;
	int n;
	// cin >> n;
	scanf("%d", &n);
	for (int i=0; i < n; i++) {
		int tmp;
		// cin >> tmp;
		scanf("%d", &tmp);
		Set.insert(tmp);
	}
	int m;
	// cin >> m;
	scanf("%d", &m);
	for (int i=0; i < m; i++) {
		int tmp;
		// cin >> tmp;
		scanf("%d", &tmp);
		if (Set.find(tmp) == Set.end()) {
			// cout << 0;
			putchar('0');
		} else {
			// cout << 1;
			putchar('1');
		}
		// cout << endl;
		putchar('\n');
	}
	return 0;
}