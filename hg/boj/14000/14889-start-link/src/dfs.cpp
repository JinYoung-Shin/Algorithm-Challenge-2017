#include <bits/stdc++.h>

using namespace std;

bool team[20];
int n;
int s[20][20];
int ans;
int abs(int v) {
    if (v<0) return -v;
    else return v;
}
void check() {
    int start=0;
    int link=0;
    vector<int> ss, ll;
    ss.reserve(n/2);
    ll.reserve(n/2);
    for (int i=0; i <n; i++) {
        if (team[i]) {
            ss.push_back(i);
        } else {
            ll.push_back(i);
        }
    }
    for (int i=0; i < n/2; i++) {
        for (int j=0; j < n/2; j++) {
            if (i==j) continue;
            start += s[ss[i]][ss[j]];
        }
    }
    for (int i=0; i < n/2; i++) {
        for (int j=0; j < n/2; j++) {
            if (i==j) continue;
            link += s[ll[i]][ll[j]];
        }
    }
    ans = min(ans, abs(start-link));
}
void dump() {
    for (int i=0; i < n; i++) {
        cout << team[i] << ", ";
    }
    cout << '\n';
}
void dfs(int i, int j) {
    if (j > n-i) return;
    if (i >= n) {
        if (j == 0) {
            // dump();    
            check();
        }
        return;
    }
    team[i] = true;
    dfs(i+1, j-1);
    team[i] = false;
    dfs(i+1, j);
}
int main() {
    ans = 987654321;
    cin >> n;
    for (int i=0; i < n; i++) {
        for (int j=0; j < n;j++) {
            cin >> s[i][j];
        }
    }
    dfs(0, n/2);
    cout << ans << '\n';
    return 0;
}