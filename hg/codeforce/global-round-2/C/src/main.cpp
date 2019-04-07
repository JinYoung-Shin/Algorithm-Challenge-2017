#include <bits/stdc++.h>
using namespace std;

int A[505][505], B[505][505];
void nope() {
    cout << "NO";
    exit(EXIT_SUCCESS);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            int v;
            cin >> v;
            A[i][j] ^= v;
            //cin >> B[i][j]
        }
    }
    
    // for (int i=0; i < n; i++) {
    //     for (int j=0; j < m; j++) {
    //         cout << A[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for (int i=0; i < n; i++) {
        int s = 0;
        for (int j=0; j <m ;j++) {
            s += A[i][j];
        }
        if (s % 2 != 0) nope();
    }
    
    for (int i=0; i < m; i++) {
        int s = 0;
        for (int j=0; j <n ;j++) {
            s += A[j][i];
        }
        if (s % 2 != 0) nope();
    }
    
    cout << "YES";
	return 0;
}

