#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> route;

inline bool is_in(pii range, int pos) {
    return pos >= range.first and pos <= range.second;
}
int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        route.reserve(n);
        route.clear();
        for (int i=0; i< n; i++) {
            int a, b;
            cin >> a >> b;
            route.push_back(make_pair(a, b));
        }
        int num_query;
        cin >> num_query;
        cout << "Case #" << tc << ": ";
        for (int i=0; i < num_query; i++) {
            int target;
            cin >> target;
            int cnt = 0;
            for (size_t j=0; j < route.size(); j++) {
                if (is_in(route[j], target)) cnt++;
            }
            cout << cnt << ' ';
        }
        cout << '\n';
    }
	return 0;
}

