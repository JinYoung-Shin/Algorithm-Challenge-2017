#include <bits/stdc++.h>

using namespace std;

set<string> ss;
vector<string> arr;
int main() {
    //ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    while(n--) {
        string name, cmd;
        cin >> name;
        cin >> cmd;
        if (cmd == "enter") {
            ss.insert(name);
        } else {
            ss.erase(name);
        }
    }
    arr.reserve(ss.size());
    for (set<string>::iterator ptr = ss.begin(); ptr != ss.end(); ptr++) {
        // cout << *ptr << '\n';
        arr.push_back(*ptr);
    }
    sort(arr.begin(), arr.end());
    for (int i=arr.size()-1; i>=0; i--) {
        cout << arr[i] << '\n';
    }
    return 0;
}