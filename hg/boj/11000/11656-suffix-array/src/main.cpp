#include <bits/stdc++.h>
using namespace std;

vector<string> arr;

int main() {
    string str;
    cin >> str;
    arr.reserve(str.size());
    for (size_t i=0;i < str.size(); i++) {
        arr.push_back(str.substr(i));
    }
    sort(arr.begin(), arr.end());
    for (size_t i=0; i < arr.size(); i++) {
        cout << arr[i] << '\n';
    }
	return 0;
}

