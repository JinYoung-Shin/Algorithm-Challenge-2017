#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll pos[64];
ll neg[64];
ll jaritsu[64];
string calc(int start, ll val) {
    if (start < 0) return "";
    ll base = jaritsu[start];
    ll maxv = base + pos[start];
    ll minv = base + neg[start];
    if (val >= minv and val <= maxv) {
        return "1" + calc(start-1, val - base);
    } else {
        return "0" + calc(start-1, val);
    }
}
int ans;
int main() {
    int n;
    cin >> n;
    jaritsu[0] = 1;
    pos[0] = 1;
    for (int i=1; i < 64; i++) {
        jaritsu[i] = jaritsu[i-1] * -2;
        if (jaritsu[i] > 0) {
            pos[i] = pos[i-1] + jaritsu[i];
            neg[i] = neg[i-1];
        } else {
            neg[i] = neg[i-1] + jaritsu[i];
            pos[i] = pos[i-1];
        }
    }
    
    string raw_ans = calc(60, n);
    
    bool found = false;
    for (size_t i=0; i < raw_ans.length()-1; i++) {
        char& c = raw_ans[i];
        if (!found) {
            if (c == '0') continue;
            else found = true;
        } 
        cout << c;
    }
    cout << raw_ans[raw_ans.length()-1] << endl;
    
	return 0;
}

