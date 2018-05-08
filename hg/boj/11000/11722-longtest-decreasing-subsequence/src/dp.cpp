#include <bits/stdc++.h>
using namespace std;

int dp[1001]; //dp[i] = arr[i]를 마지막으로 하는 부분수열 중 가장 긴놈의 길이.
int arr[1001];
int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    arr[n] =  -99999;
    
    for (int i=0; i <= n; i++) {
        auto& next = arr[i];
        for(int j=0; j < i; j++) {
            auto& prev = arr[j];
            if (prev > next) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    cout << (dp[n]-1) << endl;
	return 0;
}

