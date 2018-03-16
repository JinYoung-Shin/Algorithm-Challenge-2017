#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int A = 1;
const int B = 2;
const int C = 4;
const int D = 8;

int cnt;

string make_string(int bitset) {
    string ret = "";
    if (bitset & A) {
        ret += "A";
    }
    if (bitset & B) {
        ret += "B";
    }
    if (bitset & C) {
        ret += "C";
    }
    if (bitset & D) {
        ret += "D";
    }
    return ret;
}
inline int get_bit(char ch) {
    switch(ch) {
        case 'A': return A;
        case 'B': return B;
        case 'C': return C;
        case 'D': return D;
    }
    return -1;
}

ll dp[16][10001]; // dp[mem][len] -> len까지 mem의 인원으로 활동에 참가할 수 있는 경우의 수의 개수
const ll MOD = 1e9 + 7;
int main() {
    int t;
    cin >> t;

    for (int tc=1; tc <= t; tc++) {
        memset(dp, 0, sizeof(dp));
        string seq;
        cin >> seq;
        for (size_t index = 0; index < seq.length(); index++) {
            char ch = seq[index];
            int bit = get_bit(ch);
            if (index == 0) {
                for (int i=1; i < 16; i++) {
                    if ( (i & bit) and (i & A) ) {
                        dp[i][index] = 1;
                    } else {
                        dp[i][index] = 0;
                    }
                }
            } else {
                for (int i=1; i< 16; i++) { //current member
                    if (i & bit) { //필수멤버가 오늘 참석한 경우
                        for (int p=1; p < 16; p++) { //previous member
                            if (p & i) { //열쇠 넘겨줄 사람이 1명이라도 있는 경우
                                dp[i][index] += dp[p][index-1];
                                dp[i][index] %= MOD;
                            }
                        }
                    }
                }
            }
        }
        ll ans = 0;
        for (int i=0; i < 16; i++) {
            ans += dp[i][seq.length() - 1];
            ans %= MOD;
        }
        cout << '#' << tc << ' ' << ans << endl;
    }
    
	return 0;
}

