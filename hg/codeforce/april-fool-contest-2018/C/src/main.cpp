#include <bits/stdc++.h>
using namespace std;

int arr[11];
// int correct[11];
int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        // cin >> correct[i];
    }
    for (int i=1; i <n; i++) {
        auto bias = arr[i] - arr[i-1];
        if (bias * bias >= 4) {
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
    
	return 0;
}

