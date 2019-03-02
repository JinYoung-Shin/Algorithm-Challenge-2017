#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> arr1, arr2, sum1, sum2;
    set<ll> ss;
    arr1.reserve(n);
    arr2.reserve(m);
    sum1.reserve(n+1);
    sum2.reserve(n+1);
    sum1.push_back(0);
    sum2.push_back(0);
    for (int i=0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        arr1.push_back(tmp);
        sum1.push_back(tmp + sum1[i]);
    }
    for (int i=0; i < m; i++) {
        ll tmp;
        cin >> tmp;
        arr2.push_back(tmp);
        sum2.push_back(tmp + sum2[i]);
    }
    //dump
    int ans = 0;
    for (int i=0; i<= n; i++) {
        // cout << sum1[i] << ' ';
        ss.insert(sum1[i]);
    }
    // cout << endl;
    for (int i=0; i<= m; i++) {
        if (ss.find(sum2[i]) != ss.end()) ans++;
        // cout << sum2[i] << ' ';
    }
    // cout << endl;
    //dump
    cout << (ans-1) << endl;
    
	return 0;
}

