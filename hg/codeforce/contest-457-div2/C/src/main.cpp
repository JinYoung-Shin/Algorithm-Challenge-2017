#include <bits/stdc++.h>
using namespace std;

#define PRIME_NUM 1046527
#define INF "100000000"
int main() {
    int n, m; //number of vertices , number of edge
    cin >> n >> m;
    int val = PRIME_NUM/(n-1);
    
    printf("%d %d\n", PRIME_NUM, PRIME_NUM);
    for (int i=1; i <= n-2; i++) {
        m--;
        printf("%d %d %d\n", i, i+1, val);
        
    }
    m--;
    int rest = PRIME_NUM - val*(n-2);
    printf("%d %d %d\n", n-1, n, rest);
    
    for (int i=1; i <=n; i++) {
        for (int j=i+2; j <= n; j++) {
            if (m <= 0) return 0;
            if (i == j or j-i == 1 or i-j == 1) continue;
            printf("%d %d %s\n", i, j, INF);
            m--;
        }
    }
	return 0;
}

