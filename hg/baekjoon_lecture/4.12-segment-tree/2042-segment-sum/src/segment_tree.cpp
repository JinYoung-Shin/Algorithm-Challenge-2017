#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;
vector<ll> arr;
vector<ll> tree;

//segment tree construct 부분
ll init(int node, int start, int end) {
	// node가 담당하는 부분이 start~end 이다.
	if (start == end) {
		return tree[node] = arr[start];
	} else {
		return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2 + 1, end);
	}
}

void update(int node, int start, int end, int idx, ll diff) {
	if (idx < start || idx > end) return;
	tree[node] += diff;
	if (start != end) {
		//리프노드가 아닌 경우
		update(node*2, start, (start+end)/2, idx, diff);
		update(node*2+1, (start+end)/2+1, end, idx, diff);
	}
}
//구간 합 구하는 함수
ll query(int node, int start, int end, int left, int right) { 
	// node가 담당하는 부분이 start~end / 합을 구하는 부분이 left~right
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return query(node*2, start, (start+end)/2, left, right) + query(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
	arr.reserve(n);
	tree.reserve(tree_size);
	for (int i=0;i < n; i++) {
		ll tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	init(1, 0, n-1);

	for (int i=0;i < m+k; i++) {
		ll a,b,c;
		cin >> a >> b >> c;
		b--;
		if (a == 1) {
			ll diff = c - arr[b];
			update(1, 0, n-1, b, diff);
			arr[b] = c;

		} else if (a == 2) {
			c--;
			cout << query(1, 0, n-1, b, c) << endl;
		}
	}
}