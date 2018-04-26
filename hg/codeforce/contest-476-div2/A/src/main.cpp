#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    
    int sheet_per_person = (n + s - 1) / s;
    int total_sheet = sheet_per_person * k;
    int ans = (total_sheet + p - 1) / p;

    cout << ans << endl;
	return 0;
}

