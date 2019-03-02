#include <bits/stdc++.h>
using namespace std;

int dp[100001];
const int sqrt_val = 317;
vector<int> candid;

int get(int val) {
    if (dp[val] != -1) return dp[val];
    auto& ret = dp[val];
    ret = 987654321;
    for (size_t i=0; i < candid.size(); i++) {
        int& dec = candid[i];
        if (dec < val) {
            ret = min(ret, get(val-dec) + 1);
        } else if (dec == val) {
            ret = min(ret, 1);
        } else {
            break;
        }
    }
    return ret;
}
int main() {
    candid.reserve(sqrt_val);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    for (int i=1; i < sqrt_val; i++) {
        candid.push_back(i*i);
    }
    int n;
    cin >> n;
    cout << get(n) << endl;
	return 0;
}

