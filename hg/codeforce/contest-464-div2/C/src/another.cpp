#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> arr;

int main() {
    int n;
    scanf("%d", &n);
    for (int i =0; i <n; i++) {
        ll tmp;
        scanf("%lld", &tmp);
        arr.push_back(tmp);
    }
    ll start, end;
    cin >> start >> end;
    ll range = end - start; //length of period
    
    ll max_sum = 0LL;
    ll max_index = 0LL;
    for (int i=0; i < range; i++) {
        max_sum += arr[i];
    }
    
    ll current_sum = max_sum;
    for (int i=1; i < n; i++) {
        current_sum -= arr[i-1];
        current_sum += arr[(i + range - 1) % n];
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_index = i;
        }
    }
    
    ll ans = start - max_index;
    while (ans <= 0) {
        ans += n;
    }
    cout << ans << endl;
    return 0;
   
}

