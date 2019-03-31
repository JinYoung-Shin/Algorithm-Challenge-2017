#include <bits/stdc++.h>
using namespace std;

typedef struct _item {
    string name;
    int vol, val;
    bool operator<(const struct _item rhs) const {
        return vol < rhs.vol;
    }
} Item;

vector<Item> items;
vector<string> selection;
int dp[105][1005];
int knapsack(int n, int w) {
    //w 만큼 무개로 n개의 물건 담을 때 최대 가치
    if (n < 0) return 0;
    auto& ret = dp[n][w];
    if (ret != -1) return ret;
    if (items[n].vol > w) {
        return ret = knapsack(n-1, w);
    }
    
    return ret = max(knapsack(n-1, w), knapsack(n-1, w-items[n].vol) + items[n].val);
}
void backtrace(int n, int w) {
    if (n < 0) return;
    if (knapsack(n, w) == knapsack(n-1, w)) backtrace(n-1, w);
    else {
        selection.push_back(items[n].name);
        backtrace(n-1, w-items[n].vol);
    }
}
int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n, w;
        cin >> n >> w;
        items.clear();
        selection.clear();
        memset(dp, 0xff, sizeof(dp));
        for (int i=0; i < n; i++) {
            string name;
            int vol, val;
            cin >> name >> vol >> val;
            items.push_back({name, vol, val});
        }
        int max_val = knapsack(n-1, w);
        backtrace(n-1, w);
        cout << max_val << ' ' << selection.size() << '\n';
        for (int i=(int)selection.size() - 1; i>=0; i--) {
            cout << selection[i] << '\n';
        }
    }
	return 0;
}

