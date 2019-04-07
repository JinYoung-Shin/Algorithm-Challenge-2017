#include <bits/stdc++.h>
using namespace std;

long long N, H;
long long A[1003];
bool test(long long k) {
    long long h = H;
    vector<long long> arr;
    arr.clear();
    for (int i=0; i < k; i++) {
        arr.push_back(A[i]);   
    }
    sort(arr.begin(), arr.end(), greater<long long>());
    if (k & 1) {
        for (int i=0; i < k-1; i+=2) {
            h -= arr[i];
        }
        h -= arr[k-1];
    } else {
        for (int i=0; i < k; i+=2) {
            h -= arr[i];
        }
    }
    return h >= 0;
}
int main() {
    cin >> N >> H;
    for (int i=0; i < N; i++) {
        cin >> A[i];
    }
    long long l, r;
    l = 0, r = N;
    
    while (l < r) {
        long long m = (l+r)/2 + 1;
        if (test(m)) {
            l = m;
        } else {
            r = m-1;
        }
    }
    cout << l << endl;
    return 0;
}