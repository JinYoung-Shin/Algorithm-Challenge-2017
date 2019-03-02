#include <bits/stdc++.h>
using namespace std;

int c[501]; //cost from i to i+1
int s[501]; //start time i th station
int f[501]; // frequency time to i th station
int n;

int calc(int pos) {
    int time = 0;
    while (pos != n) {
        int depart_time = max ( (time+f[pos]-1)/f[pos] * f[pos], s[pos]);
        time = depart_time + c[pos];
        pos++;
    }
    
    return time;
}
int main() {
    
    cin >> n;
    for (int i=1; i < n; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }
    for (int i=1; i <= n; i++) {
        cout << calc(i) << '\n';
    }
    return 0;
}