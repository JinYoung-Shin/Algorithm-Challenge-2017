#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int t=1; t <= tc; t++) {
        
        string a, b;
        cin >> a >> b;
        int ans = a.length();
        int sub = b.length() - 1;
        
        while(true) {
            // cout << a << endl;
            size_t found = a.find(b);    
            if (found == string::npos) break;
            // cout << "Found on " << found << endl;
            ans -= sub;
            if (found + b.length() >= a.length()) break;
            a = a.substr(found + b.length());
            
        }
        printf("#%d %d\n", t, ans);
    }
	return 0;
}

