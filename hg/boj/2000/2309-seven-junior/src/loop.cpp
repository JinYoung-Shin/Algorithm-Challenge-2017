#include <bits/stdc++.h>
using namespace std;
int arr[9];
bool test(int a, int b) {
    int sum = 0;
    for (int i=0; i < 9; i++) {
        if (i == a || i == b) continue;
        sum += arr[i];
    }
    return sum == 100;
}
void ans(int a, int b) {
    vector<int> val;
    val.reserve(7);
    for (int i=0;i < 9; i++) {
        if (i == a || i == b) continue;
        val.push_back(arr[i]);
    }
    sort(val.begin(), val.end());
    for (int i=0; i< 7; i++) {
        cout << val[i] << '\n';
    }
}
int main() {
    for (int i=0; i < 9; i++) {
        cin >> arr[i];
    }
    for (int i=0; i< 8; i++) {
        for (int j=i+1; j < 9;j++) {
            if (test(i, j)) ans(i, j);
        }
    }
}