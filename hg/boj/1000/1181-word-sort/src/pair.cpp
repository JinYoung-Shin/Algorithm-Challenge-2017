#include <bits/stdc++.h>
using namespace std;
int main() {
    set<string> ss;
    vector<pair<size_t, string> > arr;
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ss.insert(str);
    }
    arr.reserve(ss.size());
    for (set<string>::iterator ptr = ss.begin(); ptr != ss.end(); ptr++) {
        string s = *ptr;
        arr.push_back(make_pair(s.length(), s));
    }
    sort(arr.begin(), arr.end());
    for (size_t i=0; i < arr.size(); i++) {
        cout << arr[i].second << '\n';
    }
    return 0;
}