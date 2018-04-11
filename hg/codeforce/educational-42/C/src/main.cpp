#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool chosen[11];
string num;
int ans;
void dfs(int index) {
    if (index >= num.length()) {
        int deleted_cnt = 0;
        ll value = 0;
        bool first = true;
        for (int i=0; i < num.length(); i++) {
            if (chosen[i]) {
                if (first) {
                    first = false;
                    if (num[i] == '0') return;
                }
                // cout << num[i];
                value += (num[i] - '0');
                value *= 10;
            } else {
                deleted_cnt++;
            }
        }
        value /= 10;
        if (value) {
            ll root = sqrt(value);
            if(root*root == value && root > 0) {
                ans = min(ans, deleted_cnt);
                
                // cout << value;
                // cout << endl;
            }
        }
        
        return;
    }
    
    chosen[index] = true;
    dfs(index+1);
    chosen[index] = false;
    dfs(index+1);
    
}
int main() {
    cin >> num;
    ans = 987654321;
    dfs(0);
    cout << (ans != 987654321 ? ans : -1) << endl;
	return 0;
}

