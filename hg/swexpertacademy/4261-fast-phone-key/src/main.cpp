#include <bits/stdc++.h>
using namespace std;


char match[30];

int main() {
    int tc;
    cin >> tc;
    match[0] = match[1] = match[2] = '2';
    match[3] = match[4] = match[5] = '3';
    match[6] = match[7] = match[8] = '4';
    match[9] = match[10] = match[11] = '5';
    match[12] = match[13] = match[14] = '6';
    match[15] = match[16] = match[17] = match[18] = '7';
    match[19] = match[20] = match[21] = '8';
    match[22] = match[23] = match[24] = match[25] = '9';
    
    for (int t=1; t <= tc; t++) {
        int ans = 0;
        string pat;
        int n;
        cin >> pat >> n;
        for (int i=0; i <n; i++) {
            string word;
            cin >> word;
            if (word.length() != pat.length()) {
                continue;
            }
            bool matched = true;
            for (size_t j=0; j < word.length(); j++) {
                char& c = word[j];
                char& p = pat[j];
                if (match[c-'a'] != p) {
                    matched = false;
                    break;
                }
            }
            if (matched) ans++;
        }
        
        printf("#%d %d\n", t, ans);
    }
	return 0;
}

