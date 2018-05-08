#include <bits/stdc++.h>
using namespace std;

int main() {
    regex re("(100+1+|01)+");    
    cmatch m;
    string seq;
    cin >> seq;
    bool ans = regex_match(seq.c_str(), m, re);
    cout << (ans ? "SUBMARINE" : "NOISE") << '\n';

	return 0;
}

