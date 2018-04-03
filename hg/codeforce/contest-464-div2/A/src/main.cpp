#include <bits/stdc++.h>
using namespace std;

int like[5005];
bool check(int a) {
    int b = like[a]; //whom like a
    int c = like[b]; //whom like b
    int d = like[c]; //whom like c;
    return d == a;
}
int main() {
    int n;
    cin >> n;
    for (int i=1; i <= n; i++) {
        cin >> like[i];
    }
    
    for (int i=1; i <=n; i++) {
        if (check(i)) {
            cout << "YES";return 0;
        }
    }
    cout << "NO";
	return 0;
}

