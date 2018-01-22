#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[101][101];
int A[101];
int B[101];
int n, m;
const ll NEGINF = numeric_limits<long long>::min();
#define ALL_INDEX -1
int get(int a, int b) {
    int& ret = dp[a+1][b+1];
    if (ret != -1) return ret;
    ret = 2;
    ll aval = (a==ALL_INDEX ? NEGINF : A[a]);
    ll bval = (b==ALL_INDEX ? NEGINF : B[b]);
    
    ll target = max(aval, bval);
    for (int i=a+1; i < n; i++) {
        if (A[i] > target) {
            ret = max(ret, get(i, b) + 1);
        }
    }
    for (int i=b+1; i< m; i++) {
        if (B[i] > target) {
            ret = max(ret, get(a, i) + 1);
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        
        cin >> n >> m;
        for (int i=0; i <n; i++) {
            cin >> A[i];
        }
        for (int i=0; i<m; i++) {
            cin >> B[i];
        }
        
        cout << get(ALL_INDEX, ALL_INDEX)-2 << '\n';
 
    }
    
	return 0;
}

