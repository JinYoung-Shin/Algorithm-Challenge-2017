#include <bits/stdc++.h>

using namespace std;

void blank(int n) {
    for (int i=0; i< n; i++) {
        putchar(' ');
    }
}
void star(int n) {
    for (int i=0;i < n; i++) {
        putchar('*');
    }
}
inline void l() {
    putchar('\n');
}
int main() {
    int n;
    cin >> n;
    for (int i=n; i>0;i--) {
        blank(n-i);
        star(2*i-1);
        // blank(n-i);
        l();
    }
}