#include <bits/stdc++.h>
using namespace std;

class MakeTwoConsecutive {
    public:
    string solve(string S) {
        int len = S.length();
        for (int i=0; i < len; i++) {
            char prev = -1;
            for (int j=0; j < len ;j++) {
                if (i == j) continue;
                if (prev == -1) {
                    prev = S[j];
                } else {
                    if (prev == S[j]) {
                        return string("Possible");
                    } else {
                        prev = S[j];
                    }
    			}
            }
        }
        return string("Impossible");
    }
};


int main() {
    MakeTwoConsecutive obj;
    string input;
    cin >> input;
    cout << obj.solve(input) << '\n';
	return 0;
}

