#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i=1; i <= 10; i++) {
        int ans = 0;
        int n;
        cin >> n;
        string str;
        cin >> str;
        for (size_t j=0; j < n; j++) {
            char& c = str[j];
            if (c != '+') {
                ans += (c - '0');
            }
        }
        
        printf("#%d %d\n", i, ans);
    }
	return 0;
}

