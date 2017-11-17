#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
long long n, p, a[MAXN], mark[MAXN], ans;

//
long long int debug;
//
int main() {
	ios_base::sync_with_stdio (false);
	cin >> n;
	p = n - 2;
	for (int i=0; i < n; i++) 
		cin >> a[i];
	for (int i = n - 1; i >= 0; --i) {
		if (!mark[i])
			ans++;
		if (p >= i)
			p = i - 1;
		if (p < 0) {
			int j = i - 1;
			while (j >= 0) {
				if (!mark[j])
					ans++;
				j--;
			}
			break;
		}
		
		while (p >= max ((long long)(i - a[i]), (long long)0) && p >= 0) {
			mark[p] = true;
			//
			debug++;
			//
			p--;
		}
	}
	cout << ans << "\n";
	cout << debug << endl;
	return 0;
}