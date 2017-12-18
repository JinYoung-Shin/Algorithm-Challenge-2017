#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<int, int> > arr;
    int t;
    cin >> t;
    arr.reserve(t);
    while (t--) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end());
    for (size_t i=0; i < arr.size(); i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    return 0;
}