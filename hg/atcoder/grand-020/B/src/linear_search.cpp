#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
void fail() {
    // cout << "failed T.T" << endl;
    cout << -1 << '\n';
    exit(EXIT_SUCCESS);
}
int main() {
    int k;
    cin >> k;
    arr.reserve(k);
    for (int i=0; i < k; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int min_val, max_val;
    min_val = max_val = 2;
    
    for (int i=k-1; i >= 0 ; i--) {
        
        int a = arr[i];
        
        int X = -1;
        int Y;
        for (int k=min_val; k <= max_val; k++) {
            if (k % a == 0) {
                if (X == -1) X = k;
                Y = k;
            }
        }
        if (X == -1) fail();
        min_val = X;
        max_val = Y + a - 1;

    }
    cout << min_val << ' ' << max_val << endl;
	return 0;
}

