#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int time = -1;
        for (int i=0; i < n; i++) {
            int come, endure;
            cin >> come >> endure;
            if (time == -1) {
                time = come;
            }
            if (time <= endure) {
                time = max(time, come);
                cout << time << ' ';
                time++;
            } else {
                cout << '0' << ' ';
            }
        }
        cout << '\n';
    }
	return 0;
}

