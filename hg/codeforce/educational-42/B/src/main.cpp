#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    string str;
    vector<int> arr;
    cin >> n >> a >> b;
    cin >> str;
    int l = 0;
    for (int i=0; i < n; i++) {
        char& c = str[i];
        if (c == '.') {
            l++;
        } else {
            if (l > 0) {
                arr.push_back(l);
            }
            l = 0;
        }
    }
    if (l > 0) {
        arr.push_back(l);
    }
    
    int ans = 0;
    for (size_t i=0; i < arr.size(); i++) {
        int val = arr[i];
        // cout << val << ' ';
        int a_dec = 0;
        int b_dec = 0;
        if (val & 1) { //odd num
            int big = val/2 + 1;
            int small = val/2;

            if (a > b) {
                a_dec = min(a, big);
                b_dec = min(b, small);
            } else {
                a_dec = min(a, small);
                b_dec = min(b, big);
            }
        } else {
            int half = val/2;
            a_dec = min(a, half);
            b_dec = min(b, half);
        }
        
        a -= a_dec;
        ans += a_dec;
        b -= b_dec;
        ans += b_dec;
    }
    cout << ans << endl;
	return 0;
}

