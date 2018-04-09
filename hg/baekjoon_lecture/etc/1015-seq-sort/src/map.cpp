#include <bits/stdc++.h>
using namespace std;

vector<int> arr, sorted;
int val[1001];

int main() {
    int n;
    cin >> n;
    arr.reserve(n);
    for (int i=0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sorted = arr;
    sort(sorted.begin(), sorted.end());
    for (int i=0; i < n; i++) {
        int a = sorted[i];
        val[a] = i;
    }
    for (int i=0;i < n; i++) {
        int a = arr[i];
        cout << val[a] << ' ';
    }
    cout << '\n';
	return 0;
}

