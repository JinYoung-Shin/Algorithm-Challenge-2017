#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
typedef long long ll;
#define MAX_NUM 100005
#define INF 98765432100LL
ll cost[MAX_NUM];
bool bribed[MAX_NUM];
vector<int> rel[MAX_NUM];
ll ans;


ll dfs(int i) {
    ll ret = INF;
    if (bribed[i] == false) {
        bribed[i] = true;
        ret = min(ret, cost[i]);
        for (size_t j=0; j < rel[i].size(); j++) {
            int next_i = rel[i][j];
            ret = min(ret, dfs(next_i));
        }
    }
    return ret;
}
int main() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i <= n; i++) {
        
        cin >> cost[i];

        //scanf("%I64d", &cost[i]);
    }
    for (int i=0; i < m; i++) {
        int src, dst;
        scanf("%d %d", &src, &dst);
        if (src > dst) {
            swap(src, dst);
        }
        rel[src].push_back(dst);
        rel[dst].push_back(src);
    }
    for (int i=1; i <= n; i++) {
        ll val = dfs(i);
        if (val != INF) {
            ans += val;
        }
    }

    cout << ans << '\n';
    return 0;
}