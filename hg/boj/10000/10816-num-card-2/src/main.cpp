#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (m.find(tmp) == m.end()) {
            m[tmp] = 1;
        } else {
            m[tmp] = m[tmp] + 1;
        }
    }
    
    scanf("%d", &n);
    for (int i=0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        printf("%d ", m[tmp]);
    }
    putchar('\n');
    
	return 0;
}

