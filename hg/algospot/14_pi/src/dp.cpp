#include <bits/stdc++.h>
using namespace std;

#define IMPOSSIBLE 987654321
int dp[10001];
string seq;
bool score1(int start, int end) {
    char ch = seq[start];
    for (int i=start+1; i<end; i++) {
        if (seq[i] != ch) return false;
    }
    return true;
}
bool score4(int start, int end) {
    char ch1 = seq[start];
    char ch2 = seq[start+1];
    for (int i=start+2; i < end; i++) {
        if ( (i-start) % 2 == 0 ) {
            if (seq[i] != ch1) return false;
        } else {
            if (seq[i] != ch2) return false;
        }
    }
    return true;
}
int is_sequence(int start, int end) {
    int diff = seq[start+1] - seq[start];
    for (int i=start+1; i < end-1; i++) {
        int new_diff = seq[i+1] - seq[i];
        if (new_diff != diff) return IMPOSSIBLE;
    }
    return diff;
}
int get_diffi(int start, int end){
    if (score1(start, end)) return 1;
    int diff = is_sequence(start, end);
    if (diff == 1 or diff == -1) return 2;
    if (score4(start, end)) return 4;
    if (diff != IMPOSSIBLE) return 5;
    return 10;
}
int get(int l) {
    if (l == seq.length()) return 0;
    if (l > seq.length()) return IMPOSSIBLE;
    int& ret = dp[l];
    if (ret != -1) return ret;
    
    ret = IMPOSSIBLE;
    for (int len = 3; len <= 5; len++) {
        if (get(l+len) != IMPOSSIBLE) //잘못끊은게 아닌경우에만 계산함
            ret = min(ret, get(l+len) + get_diffi(l, l+len));
    }
    return ret;
    
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));    
        cin >> seq;
        cout << get(0) << '\n';
    }
	return 0;
}

