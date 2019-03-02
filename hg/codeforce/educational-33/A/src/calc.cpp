#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int spectator = 3;
    for (int i=0; i < n;i++) {
        int winner;
        cin >> winner;
        if (winner == spectator) {
            cout << "NO" << endl;
            return 0;
        } else {
            spectator = 6 - winner - spectator;
        }
    }
    cout << "YES" << endl;
    return 0;
}