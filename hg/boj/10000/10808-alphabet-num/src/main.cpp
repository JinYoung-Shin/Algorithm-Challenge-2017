#include <bits/stdc++.h>
using namespace std;

int arr[26];
int main() {
    string str;
    cin >> str;
    for (size_t i=0; i < str.length(); i++) {
        char ch = str[i];
        arr[ch-'a']++;
    }
    for (int i=0;i <26;i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}