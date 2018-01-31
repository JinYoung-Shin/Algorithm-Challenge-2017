#include <bits/stdc++.h>
using namespace std;

int A[10], B[10];
int main() {
    for (int i=0; i < 10; i++) {
        cin >> A[i];
    }
    for (int i=0; i < 10; i++) {
        cin >> B[i];
    }
    int a = 0, b = 0;
    for (int i=0; i< 10; i++) {
        if (A[i] > B[i]) {
            a+= 3;
        } else if (A[i] == B[i]) {
            a+=1;
            b+=1;
        } else {
            b+= 3;
        }
    }
    if (a != b) {
        cout << a << ' ' << b << '\n';
        if (a > b) cout << 'A' << '\n';
        else cout << "B\n";
        return 0;
    }
    for (int i=9; i>=0; i--) {
        if (A[i] > B[i]) {
            cout << a << ' ' << b << '\n';
            cout << 'A' << '\n';
            return 0;
        } else if (B[i] > A[i]) {
            cout << a << ' ' << b << '\n';
            cout << 'B' << '\n';
            return 0;
        }
    }
    cout << a << ' ' << b << '\n';
    cout << 'D' << '\n';
	return 0;
}

