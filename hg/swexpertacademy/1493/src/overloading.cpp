#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
ll summation(ll i) {
	return (i * (i+1)) / 2;
}
int find_range(ll n) {
	for (int i=0;;i++) {
		if (n > summation(i) && n <= summation(i+1))
			return i+1;
	}
}
P ampersand(ll i) {
	ll range = find_range(i);
	ll x = i - summation(range-1);
	ll y = range - x;
	// cout << '(' << x << ',' << y << ')' << endl;
	P p;
	p.first = x;
	p.second = y+1;
	return p;
}
ll sharp(P p) {
	int range = p.first + p.second - 1;
	ll base = summation(range - 1);
	return base + p.first;
}
ll star(ll p, ll q) {
	P lhs = ampersand(p);
	P rhs = ampersand(q);
	P ss;
	ss.first = lhs.first + rhs.first;
	ss.second = lhs.second + rhs.second;
	return sharp(ss);
}
int main() {
	int t;
	cin >> t;
	for (int i=1; i <= t; i++) {
		cout << '#' << i << ' ';
		int a,b;
		cin >> a >> b;
		cout << star(a,b) << endl;
	}
}