#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int vote[1001];
int main() {
    int t;
    cin >> t;
    for (int tc=1; tc <= t;  tc++) {
        int n, m;
        cin >> n >> m;
        for (int i=0; i < n; i++) {
            cin >> arr[i];
        }
        
        //debug
        // for (int i=0; i < n; i++) {
        //     cout << arr[i] << ' ';
        // }
        // cout << endl;
        //debug
        for (int i=0; i <m; i++) {
            int tmp;
            cin >> tmp;
            // cout << tmp << endl;
            for (int j=0;j <n; j++) {
                if (tmp >= arr[j]) {
                    // printf("tmp <= arr[j], ?? %d, %d, %d\n", tmp, arr[j], j);
                    vote[j]++;
                    // cout << j << endl;
                    break;
                }
            }
        }
        int indice = 0;
        int quantity = vote[0];
        for (int i=0; i < n;i++) {
            if (quantity < vote[i]) {
                quantity = vote[i];
                indice = i;
            }
        }
        cout << '#' << tc << ' ' << (indice+1) << endl;
        memset(vote, 0, sizeof(vote));
    }
    return 0;
}