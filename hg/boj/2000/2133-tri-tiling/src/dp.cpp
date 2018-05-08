#include <bits/stdc++.h>
using namespace std;

int dp[31][8]; //dp[len][state]
int main() {
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i=0; i < n; i++) {
        auto& c = dp[i];
        auto& n = dp[i+1];
        n[4] += c[0];
        n[1] += c[0];
        n[7] += c[0];
        
        n[0] += c[1];
        n[6] += c[1];
        
        n[5] += c[2];
        
        n[4] += c[3];
        
        n[0] += c[4];
        n[3] += c[4];
        
        n[2] += c[5];
        
        n[1] += c[6];
        
        n[0] += c[7];
    }
    
    cout << dp[n][0] << endl;
	return 0;
}

