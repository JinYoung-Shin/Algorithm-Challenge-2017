#include <bits/stdc++.h>
using namespace std;

vector<bool> arr; // true = hit , false = heal
int main() {
    int h1, a1, c, h2, a2;
    cin >> h1 >> a1 >> c >> h2 >> a2;
    while(h2 > 0) {
        if (h2 <= a1) {
            arr.push_back(true);
            break;
        } else if (h1 > a2) {
            arr.push_back(true);
            h2 -= a1;
            h1 -= a2;
        } else {
            arr.push_back(false);
            h1 += c;
            h1 -= a2;
        }
    }
    cout << arr.size() << '\n';
    for (size_t i =0; i < arr.size(); i++) {
        if (arr[i]) {
            cout << "STRIKE\n";
        } else {
            cout << "HEAL\n";
        }
    }
    return 0;
}