#include <iostream>
#include <string>
using namespace std;

int cost[26];
int main() {
    string str;
    cin >> str;
    for(int i=0; i < 26; i++) {
        cin >> cost[i];
    }
    int ans = 0;
    for (size_t i=0; i < str.length(); i++) {
        char ch = str[i];
        ans += cost[ch-'a'];
    }
    cout << ans << '\n';
    return 0;
}