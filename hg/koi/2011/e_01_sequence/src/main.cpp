#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int main() {
    int n ,k;
    cin >> n >> k;
    arr.reserve(n);
    for (int i=0; i< n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int seq = 0;
    for (int i=0; i<k; i++) {
        seq += arr[i];
    }
    int back = 0;
    int front = k;
    int ans = -987654321;
    while (front < n) {
        ans = max(ans, seq);
        seq -= arr[back];
        seq += arr[front];
        back++;
        front++;
    }
    ans = max(ans, seq);
    cout << ans << '\n';
	return 0;
}

