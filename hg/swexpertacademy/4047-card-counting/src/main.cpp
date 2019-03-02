#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    bool S[13];
    bool D[13];
    bool H[13];
    bool C[13];
    
    
    for (int t=1; t <= tc; t++) {
        memset(S, 0, sizeof(S));
        memset(D, 0, sizeof(D));
        memset(H, 0, sizeof(H));
        memset(C, 0, sizeof(C));
        
        int aS = 13;
        int aD = 13;
        int aH = 13;
        int aC = 13;
        string seq;
        cin >> seq;
        bool ans = true;
        int n = (int)seq.length() / 3;
        for (int i=0; i < n; i++) {
            int base = i*3;
            string s = seq.substr(base, 3);
            int index = 0;
            if (s[1] == '1') index += 10;
            index += s[2] - '0';
            index--;
            char& type = s[0];
            
            bool* slot;
            int* aCnt;
            if (type == 'S') {
                slot = S;
                aCnt = &aS;
            }
            else if (type == 'D') {
                slot = D;
                aCnt = &aD;
            }
            else if (type == 'H') {
                slot = H;
                aCnt = &aH;
            }
            else if (type == 'C') {
                slot = C;
                aCnt = &aC;
            }
            if (slot[index]) {
                ans = false;
                printf("#%d ERROR\n", t);
                break;
            } else {
                slot[index] = true;
                (*aCnt)--;
            }
        }
        if (ans) {
            printf("#%d %d %d %d %d\n", t, aS, aD, aH, aC);    
        }
        
    }
	return 0;
}

