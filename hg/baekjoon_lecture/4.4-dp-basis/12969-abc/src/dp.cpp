#include <bits/stdc++.h>
using namespace std;
int dp[31][31][31][900]; // dp[i][a][b][k] => 길이 i, A가 a개, B가 b개, C가 i-a-b개에 조건 만족하는 쌍이 k개인 문자열의 가능 여부
string get_string(int n, int a, int b, int k) {
    if (n == 0) return string("");
    //마지막이 A인 경우
    if (a && dp[n-1][a-1][b][k]) {
        return get_string(n-1, a-1, b, k) + "A";
    }
    
    //마지막이 B인 경우
    if (b && k-a >= 0 && dp[n-1][a][b-1][k-a]) {
        return get_string(n-1, a, b-1, k-a) + "B";
    }
    
    //마지막이 C인 경우
    if (k-a-b >= 0 && dp[n-1][a][b][k-a-b]) {
        return get_string(n-1, a, b, k-a-b) + "C";
    }
    return string("");
}
string check_exist(int N, int K) {
    for (int a=0; a <= N; a++) {
        for (int b=0; b <= N - a; b++) {
            if (dp[N][a][b][K]) return get_string(N, a, b, K);
        }
    }
    return string("-1");
}
int main() {
    int N, K;
    dp[0][0][0][0] = 1;
    cin >> N >> K;
    for (int i=1; i <= N; i++) {
        for (int a=0; a <= i; a++) {
            for (int b=0; b <= i; b++) {
                int c = i - a - b;
                for (int k=0; k <= i*(i-1)/2; k++) {
                    //마지막에 A를 추가하는 경우
                    if (a) {
                        dp[i][a][b][k] = dp[i-1][a-1][b][k];
                    }
                        
                    //마지막에 b를 추가하는 경우
                    if (b && k >= a) {
                        dp[i][a][b][k] = dp[i-1][a][b-1][k-a];
                    }
                        
                    //마지막에 c를 추가하는 경우
                    if (c && k-a-b >= 0) {
                        dp[i][a][b][k] = dp[i-1][a][b][k-a-b];
                    }
                }
            }
        }
    }
    
    cout << check_exist(N, K) << endl;
    
	return 0;
}

