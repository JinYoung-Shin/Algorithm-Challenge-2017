#include <iostream>
#include <cstdio>

using namespace std;

int arr[1001];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        int sum = 0;
        int cnt=0;
        cin >> n;
        for (int i=0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        for (int i=0; i < n; i++) {
            if (arr[i]*n > sum) cnt++;
        }
        double percent = (double)cnt/n *100;
        printf("%.3lf%%\n", percent);
    }
    return 0;
}