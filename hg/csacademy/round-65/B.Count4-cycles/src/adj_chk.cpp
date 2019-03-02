#include <bits/stdc++.h>

using namespace std;

// vector<vector<int> > T1, T2;
vector<set<int> > T1, T2;
int main() {
    int n;
    cin >> n;
    T1.resize(n+1);
    T2.resize(n+1);
    for (int i=0; i < n-1; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        T1[a].insert(b);

    }
    for (int i=0; i < n-1; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        T2[a].insert(b);
        T2[b].insert(a);

    }
    int ans = 0;
    for (int i=1; i <= n; i++) {
        for (set<int>::iterator ptr = T1[i].begin(); ptr != T1[i].end(); ptr++) {
            // cout << *ptr << endl;
            int src = i;
            int dst = *ptr;
            if (T2[src].find(dst) != T2[src].end() or T2[dst].find(src) != T2[dst].end()) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}