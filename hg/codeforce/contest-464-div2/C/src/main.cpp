#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    for (int i =0; i <n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    int start, end;
    cin >> start >> end;
    int range = end - start;
    
    ll max_val = 0;
    ll prev_val = 0;
    int start_time = end - 1; //0 for max_val index
    for (int i=0; i < range; i++) {
        prev_val += arr[i];
    }
    
    max_val = prev_val;
    
    for (int i=1; i < n; i++) {
        ll cur_val = prev_val;
        cur_val += arr[(i+range-1) % n];
        cur_val -= arr[i-1];    
        if (cur_val > max_val) {
            max_val = cur_val;
            start_time = end - 1 + i;
        }
        prev_val = cur_val;
    }
    
    // int ans = (start_time + start - 1) % n;
    int ans = (start_time - 1) % n + 1;
    cout << ans << endl; 
	return 0;
}

