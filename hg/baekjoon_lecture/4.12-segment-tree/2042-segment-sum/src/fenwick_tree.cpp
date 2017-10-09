#include <iostream>
#include <vector>
#include <cstdio>

typedef long long ll;

using namespace std;

vector<ll> tree;
vector<ll> arr;
int n, m, k;
ll query(int i) {
	// A[0] ~ A[i] 까지의 합을 리턴함
	ll ans = 0LL;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(int i, ll val) {
	while (i <= n) {
		tree[i] += val;
		i += (i & -i);
	}
}

int main() {
	cin >> n >> m >> k;
	arr.reserve(n+1);
	tree.reserve(n+1);
	arr.push_back(-1);
	for (int i=1; i <= n; i++) {
		ll tmp;
		cin >> tmp;
		arr.push_back(tmp);
		update(i, tmp);
	}

	for (int i=0; i < m+k; i++) {
		ll a,b,c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - arr[b];
			update(b, diff);
			arr[b] = c;
		} else if (a == 2) {
			ll val = query(c);
			if (b > 0) {
				val -= query(b-1);
			}
			cout << val << endl;
		}
	}
}