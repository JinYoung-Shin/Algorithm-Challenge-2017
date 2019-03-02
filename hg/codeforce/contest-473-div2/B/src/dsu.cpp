#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
unordered_map<string, int> mm; //string to indices
// string indices[100005]; // indices to string
int cost[100005];
int min_cost[100005];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i=1; i <= n; i++) {
        string str;
        cin >> str;
        // indices[i] = str;
        mm[str] = i;
    }
    
    for (int i=1; i <= n; i++) {
        cin >> cost[i];
    }
    
    for (int i=0; i< m; i++) {
        int num;
        cin >> num;
        vector<int> arr;
        arr.clear();
        int min_val = 1000000001;
        for (int j=0; j< num; j++) {
            int idx;
            cin >> idx;
            arr.push_back(idx);
            min_val = min(min_val, cost[idx]);
        }
        for (size_t j=0;j < arr.size(); j++) {
            auto& idx = arr[j];
            min_cost[idx] = min_val;
        }
    }
    ll ans = 0;
    for (int i=0; i < k; i++) {
        string str;
        cin >> str;
        int idx = mm[str];
        ans += min_cost[idx];
    }
    cout << ans << endl;
	return 0;
}

