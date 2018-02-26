#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> ss;
    int n;
    cin >> n;
    for (int i=0; i< n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp)
            ss.insert(tmp);
    }
    cout << ss.size() << '\n';
	return 0;
}

