#include <bits/stdc++.h>
using namespace std;

int dp1[1001]; // arr[i]를 마지막으로하는 앞에서부터 시작했을 때 가장 긴 증가하는 부분수열의 길이
int dp2[1001]; // arr[i]를 마지막으로하는 뒤에서부터 시작했을 때 가장 긴 증가하는 부분수열의 길이
int arr[1001];
int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        dp1[i] = dp2[i] = 1;
    }
    for (int i=0;i < n; i++) {
        auto& next = arr[i];
        for (int j=0; j < i; j++) {
            auto& prev = arr[j];
            if (next > prev) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for (int i=n-1; i >=0; i--) {
        auto& next = arr[i];
        for (int j=n-1; j > i; j--) {
            auto& prev = arr[j];
            if (next > prev) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i=0; i < n; i++) {
        ans = max(ans, dp1[i] + dp2[i]);
    }
    cout << (ans-1) << endl;
    
	return 0;
}

