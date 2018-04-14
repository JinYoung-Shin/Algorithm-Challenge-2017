#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}
pair<int, int> arr[200005];
map<pair<int, int>, int> mm;
int main() {
    
    int n;
    scanf("%d\n", &n);
    for (int i=0; i < n; i++) {
        int a, b, c;
        scanf("(%d+%d)/%d\n", &a, &b, &c);
        int upper = a+b;
        int lower = c;
        int common;
        while((common = gcd(upper, lower)) != 1) {
            upper /= common;
            lower /= common;
        }
        arr[i].first = upper;
        arr[i].second = lower;
    
        if (mm.find(make_pair(upper, lower)) == mm.end()) {
            mm[make_pair(upper, lower)] = 1;
        } else {
            mm[make_pair(upper, lower)] = mm[make_pair(upper, lower)] + 1;
        }
    }
    
    for (int i=0; i < n; i++) {
        auto& key = arr[i];
        cout << mm[key] << ' ';
    }
    cout << endl;
    
	return 0;
}

