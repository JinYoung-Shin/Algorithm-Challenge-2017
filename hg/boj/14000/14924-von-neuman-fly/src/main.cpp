#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, t, d;
    cin >> s >> t >> d;
    int time = d/(2*s);
    cout << (time * t) << '\n';
    return 0;
}