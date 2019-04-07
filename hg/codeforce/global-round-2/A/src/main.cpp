#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 300005
int Left[MAXN], Right[MAXN]; 
int A[MAXN];
int main() {
    int n; cin >> n;
    for (int i=1; i <= n; i++) {
        Left[i] = MAXN;
        Right[i] = 0;
    }
    for (int i=1; i <= n; i++) {
        int v;
        scanf("%d", &v);
        A[i] = v;
        Left[v] = min(Left[v], i);
        Right[v] = max(Right[v], i);
    }
    
    int ans = 0;
    for (int i=1; i <= n; i++) {
        if (i == A[1]) continue;
        ans = max(ans, Right[i] - Left[A[1]]);
    }
    for (int i=1; i <= n; i++) {
        if (i == A[n]) continue;
        ans = max(ans, Right[A[n]] - Left[i]);
    }
    cout << ans << endl;
	return 0;
}

