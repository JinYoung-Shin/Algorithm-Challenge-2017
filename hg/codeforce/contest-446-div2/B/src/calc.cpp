#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[1000001];
int main() {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	ll num_live = 0;
	ll dead_left = 0;
	cin >> n;
	for (int i=0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i=n-1; i >= 0; i--) {
		if (dead_left > 0) {
			dead_left--;
		} else {
			num_live++;
		}
		dead_left = max(dead_left, arr[i]);
	}
	cout << num_live << endl;
	return 0;
}