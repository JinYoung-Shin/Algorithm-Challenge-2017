#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[10000];
int main() {
    int n;
    cin >> n;
    for (int i=0; i <n; i++) {
        cin >> arr[i];
    }
    ll budget;
    cin >> budget;
    
    ll average = budget/n;
    
    ll i;
    ll ans = 0;
    for (i = average; i <= 100000; i++) {
        ll sum = 0;
        ll new_ans = 0;
        for (int j=0; j < n; j++) {
            if (arr[j] >= i) {
                sum += i;
                new_ans = max(new_ans, i);
            } else {
                sum += arr[j];
                new_ans = max(new_ans, arr[j]);
            }
        }
        if (sum > budget) break;
        ans = new_ans;
    }
    cout << ans << '\n';
	return 0;
}

