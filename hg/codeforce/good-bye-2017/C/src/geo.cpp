#include <bits/stdc++.h>
using namespace std;

int n, r;
int x[1001];
typedef pair<int, double> Pos;
// Pos pos[1001];
vector<Pos> pos;
inline int abs(int x) {
    if (x < 0) return -x;
    return x;
}
double get_y(int x, int idx) {
    int target_xpos = pos[idx].first;
    int x_delta = abs(x-target_xpos);
    if (x_delta > r*2) return (double)r; //원끼리 만나지 않는 경우
    else {
        double y_delta = sqrt(4 * r * r - x_delta * x_delta);
        double y_base = pos[idx].second;
        return y_base + y_delta;
    }
}
void push_circle(int x) {
    Pos tmp;
    tmp.first = x;
    if (pos.size() == 0) {
        tmp.second = (double)r;
        pos.push_back(tmp);
        return;
    }
    tmp.second = 0;
    for (size_t i=0; i < pos.size(); i++) {
        tmp.second = max(tmp.second, get_y(x, i));
    }
    pos.push_back(tmp);
    return;
}
int main() {
    cin >> n >> r;
    pos.reserve(n);
    for (int i=0; i < n; i++) {
        int xpos;
        cin >> xpos;
        push_circle(xpos);
    }
    
    for (size_t i=0; i < pos.size(); i++) {
        printf("%.10lf ", pos[i].second);
        // cout << pos[i].second << ' ';
    }
    cout << '\n';
    return 0;
}