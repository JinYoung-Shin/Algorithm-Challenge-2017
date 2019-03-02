#include <bits/stdc++.h>
using namespace std;

int A[200005]; //A의 위치를 저장
int B[200005];
int main() {
    int n;
    cin >> n;
    for (int i=1;i <= n;i++) {
        int val;
        cin >> val;
        A[val] = i;
    }
    for (int i=0;i < n;i++) cin >> B[i];
    int done = 0;
    

    for (int i=0; i < n; i++) {
        auto& cur = B[i];
        if (A[cur] > done) {
            cout << A[cur] - done << ' ';
            done = A[cur];
        } else {
            cout << 0 << ' ';
        }
    }
	return 0;
}

