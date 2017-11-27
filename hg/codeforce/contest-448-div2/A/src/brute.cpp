#include <iostream>
#include <algorithm>
using namespace std;

int arr[365];

int abs(int val) {
    if (val < 0) {
        return -val;
    } else {
        return val;
    }
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 360;
    
    for (int i=0; i < n; i++) {
        int x = 0;
        for (int j=0;j < n; j++) {
            x += arr[(i+j)%n];
            int val = abs(2*x-360);
            ans = min(ans, val);
        }
    }
    cout << ans << endl;
    return 0;
}