#include <bits/stdc++.h>
using namespace std;

int N, L;  
int plainValue[105];

int main() {
    int tc; cin >> tc;
    for (int t=1; t<=tc; t++) {
        memset(plainValue, 0, sizeof(plainValue));
        cin >> N >> L;
        vector<int> ciphers;
        set<int> primes;
        map<int, char> int2char;
        map<char, int> char2int;
        ciphers.clear();
        primes.clear();
        int2char.clear();
        char2int.clear();
        for (int i=0; i < L; i++) {
            int tmp; cin >> tmp;
            ciphers.push_back(tmp);
        }
        for (int i=0; i< L-1; i++) {
            if (ciphers[i] != ciphers[i+1]) {
                int cd = __gcd(ciphers[i], ciphers[i+1]);
                primes.insert(cd);
                primes.insert(ciphers[i]/cd);
                primes.insert(ciphers[i+1]/cd);
            }
        }
        char c = 'A';
        for (auto& p : primes) {
            if (int2char.find(p) == int2char.end()) {
                char2int[c] = p;
                int2char[p] = c++;
            }
        }
        
        int idx, pval, ppval;
        for (idx=0; idx < L-1; idx++) {
            if (ciphers[idx] != ciphers[idx+1]) {
                int cd = __gcd(ciphers[idx], ciphers[idx+1]);
                plainValue[idx+1] = cd;
                pval = ciphers[idx+1] / cd;
                ppval = ciphers[idx] / cd;
                break;
            }
        }
        
        
        for (int i=idx; i >= 1; i--) {
            plainValue[i] = ppval;
            ppval = ciphers[i-1] / ppval;
        }
        plainValue[0] = ppval;
        
        for (int i=idx+2; i < L; i++) {
            plainValue[i] = pval;
            pval = ciphers[i] / pval;
        }
        plainValue[L] = pval;
        
        printf("Case #%d: ", t);
        for (int i=0; i <= L; i++) {
            putchar(int2char[plainValue[i]]);
        }
        putchar('\n');
    }
}