#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef struct _Group {
	ll size;
	int in;
	int out;
	// bool cycle; //무조건 cycle이다.
} Group;

// vector<Group> cluster;
vector<ll> cluster;
pii p[100002]; // p[i].frist -> i에서 갈수있는곳 , p[i].second -> i로 갈 수 있는곳
bool chk[100002]; //visited 방문시 true임

Group dfs(int start) {
	Group ret;
	ret.size = 0;
	ret.in = ret.out = start;
	
	//forward propagation
	int ptr = ret.out;
	while (chk[ptr] == false) {
		chk[ptr] = true;
		ret.size++;
		ptr = p[ptr].first;
	}
	ret.out = ptr;
	//backward propagation
	ptr = p[ret.in].second;
	while (chk[ptr] == false) {
		chk[ptr] = true;
		ret.size++;
		ptr = p[ptr].second;
	}
	ret.in = ptr;
	
	// if (ret.in == ret.out || p[ret.out].first == ret.in) {
	// 	ret.cycle = true;
	// } else {
	// 	ret.cycle = false;
	// }
	
	return ret;
}
int main() {
	int n;
	cin >> n;
	for (int i=1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		p[i].first = tmp;
		p[tmp].second = i;
	}
	int not_visited = n;
	for (int i=1; i <= n; i++) {
		if (not_visited <= 0) break;
		Group g = dfs(i);
		if (g.size > 0) {
			// cluster.push_back(g);
			cluster.push_back(g.size);
		}
	}
	
	sort(cluster.begin(), cluster.end(), greater<int>());
	ll ans = 0;
	if (cluster.size() == 1) {
		ans = cluster[0] * cluster[0];
	} else {
		ll tmp = cluster[0] + cluster[1];
		ans = tmp * tmp;
		for (unsigned int i = 2; i < cluster.size(); i++) {
			ans += cluster[i] * cluster[i];
		}
	}
	
	cout << ans << endl;
	
	//크기 젤 큰거 2개 group을 합친 뒤, 그룹의 사이즈^2 를 다 더하면 정답이다.
	
	//debug cluster dump//
	// for (unsigned int i=0; i < cluster.size(); i++) {
	// 	auto& gg = cluster[i];
	// 	printf("size: %d\nin: %d\nout: %d\n------------------\n", gg.size, gg.in, gg.out);
	// }
	//debug cluster dump//
}