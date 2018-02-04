#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
string seq;
pii get_contiguous(int start) {
    pii ret;
    ret.first = ret.second = -1;
    if (start >= seq.size()) return ret;
    for (int i=start; i < seq.size(); i++) {
        char ch = seq[i];
        if (ch == '1') {
            if (ret.first == -1) {
                ret.first = i;
                ret.second = i;
            } else {
                ret.second = i;
            }
        } else {
            if (ret.first != -1) {
                break;
            }
        }
    }
    return ret;
}
int main() {
    int n; // sequence length
    scanf("%d\n", &n);
    vector<int> arr, sorted;
    arr.reserve(n);
    for (int i=0; i < n; i++) {
        int val;
        scanf("%d", &val);
        arr.push_back(val);
    }
    cin >> seq;
    pii my_range;
    my_range.first = my_range.second = -1;
    while(true) {
        // range.clear();
        my_range = get_contiguous(my_range.second+1);
        if (my_range.first == -1 and my_range.second == -1) break;
        for (int i=my_range.first; i <= my_range.second+1; i++) {
            int& val = arr[i];
            if (val >= my_range.first + 1 and val <= my_range.second + 2) {
                
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if ((seq[0] == '0' and arr[0] != 1) or (seq[n-2] == '0' and arr[n-1] != n) ) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i=1; i < n-1; i++) {
        if (seq[i-1] == '0' and seq[i] == '0') {
            if (arr[i] != i+1) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    
	return 0;
}

