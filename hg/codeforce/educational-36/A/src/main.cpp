#include <bits/stdc++.h>
using namespace std;

// int arr[101];
int main() {
    int n, k;
    int bucket_size = 0;
    cin >> n >> k;
    for (int i=0; i < n; i++) {
        // cin >> arr[i];
        int tmp;
        cin >> tmp;
        if (k >= tmp and k % tmp == 0) {
            bucket_size = max(bucket_size, tmp);
        }
    }
    cout << (k/bucket_size) << endl;
	return 0;
}

