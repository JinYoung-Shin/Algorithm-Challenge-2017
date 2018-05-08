#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int decimal = 0;
    int n;
    cin >> n;
    int base = 1;
    for (int i=1; i <n; i++) {
        base *= a;
    }
    for (int i=0; i < n; i++) {
        int tmp;
        cin >> tmp;
        decimal += tmp * base;
        base /= a;
    }
    vector<int> ans;
    while (decimal) {
        int rest = decimal % b;
        ans.push_back(rest);
        decimal /= b;
    }
    
    
    for (int i=ans.size()-1; i>=0; i--) {
        cout << ans[i] <<' ';
    }
    cout << endl;
	return 0;
}

