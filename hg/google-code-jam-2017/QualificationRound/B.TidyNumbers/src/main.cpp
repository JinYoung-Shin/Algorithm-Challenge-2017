#include <bits/stdc++.h>
using namespace std;

void process(string& str) {
    for (size_t i = str.length()-1; i>0; i--) {
        char& ch = str[i];
        char& next_ch = str[i-1];

        if (next_ch > ch) {
            for (size_t k=i; k < str.length(); k++) {
                str[k] = '9';
            }
            next_ch--;
        }
    }
}
int main() {
    int t;
    cin >> t;
    for (int i=1; i <= t; i++) {
        string str;
        cin >> str;
        process(str);
        printf("Case #%d: ", i);
        for (size_t k=0; k < str.length(); k++) {
            if (str[k] != '0') putchar(str[k]);
        }
        putchar('\n');
        
    }
	return 0;
}

