#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
int main() {
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    int dx=INF, dy=INF;
    dx = min(x, w-x);
    dy = min(y, h-y);
    cout << min(dx, dy) << '\n';
    return 0;
}