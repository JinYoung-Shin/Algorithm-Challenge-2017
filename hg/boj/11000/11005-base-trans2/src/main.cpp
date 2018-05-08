#include <bits/stdc++.h>
using namespace std;

char val2char(int val) {
    // printf("val: %d\n", val);
    if (val < 10) {
        return val + '0';
    }
    return val - 10 + 'A';
}
int main() {
    int decimal;
    int base;
    cin >> decimal >> base;
    // int base = b;
    vector<char> ans;
    while(decimal > 0) {
        int cur_val = decimal % base;
        ans.push_back(val2char(cur_val));
        decimal /= base;
    }
    
    for (int i=ans.size()-1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    
	return 0;
}

