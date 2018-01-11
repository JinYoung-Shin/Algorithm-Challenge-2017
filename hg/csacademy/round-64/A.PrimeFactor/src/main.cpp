#include <bits/stdc++.h>

using namespace std;

inline int query(int a) {
    int ret;
    printf("Q %d\n", a);
    fflush(stdout);
    scanf("%d", &ret);
    fflush(stdin);
    return ret;
}
inline void ans(int a) {
    printf("A %d\n", a);
    fflush(stdout);
    exit(EXIT_SUCCESS);
}
int main() {
    int q[] = {2, 3, 5, 7};
    int candid = 1;
    for (int i=0; i< 4; i++) {
        int qq = q[i];
        if (int exponential = query(qq)) {
            while(exponential--) {
                candid *= qq;
            }
        }
        if (i < 3 and candid*q[i+1] > 10) {
            ans(candid);
        }
    }
    ans(candid);
    
    return 0;
}