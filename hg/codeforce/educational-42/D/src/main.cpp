#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll, set<int> > m; // (value, index-list)

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]].insert(i);
    }
    
    for (auto& it : m) {
        auto& val = it.first;
        auto& s = it.second;
        while(s.size() >= 2) {
            int p1 = *s.begin();
            int p2 = *next(s.begin());
            arr[p2] *= 2;
            arr[p1] = -1;
            s.erase(p1);
            s.erase(p2);
            m[val*2].insert(p2);
        }
    }
    vector<ll> ans;
    ans.reserve(n);
    for (int i=0; i< n; i++) {
        if (arr[i] != -1) {
            ans.push_back(arr[i]);
        }
    }
    cout << ans.size() << '\n';
    for (int i=0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
	return 0;
}

