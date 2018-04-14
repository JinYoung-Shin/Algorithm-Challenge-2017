#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
pii R[11];
pii B[11];
int r, b;

// CCW Algorithm http://jason9319.tistory.com/358
int match[11];
bool occupied[11];
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first*b.second + b.first*c.second + c.first*a.second;
    op -= (a.second*b.first + b.second*c.first + c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}
int inter(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return c <= b&&a <= d;
    }
    return ab <= 0 && cd <= 0;
}

bool dfs(int index) {
    bool ret = false;
    if (index >= r) {
        for (int i=0; i < r; i++) {
            for (int j=i+1; j < r; j++) {
                pii a = R[i];
                pii b = B[match[i]];
                pii c = R[j];
                pii d = B[match[j]];
                if (inter(make_pair(a, b), make_pair(c, d))) return false;
            }
        }
        return true;

    }
    
    for (int i=0; i < r; i++) {
        if (occupied[i] == false) {
            occupied[i] = true;
            match[index] = i;
            ret |= dfs(index+1);
            occupied[i] = false;
        }
    }
    return ret;
}
int main() {
    
    cin >> r >> b;
    if (r!=b) {
        cout << "No"; return 0;
    }
    for (int i=0; i < r; i++) {
        cin >> R[i].first >> R[i].second;
    }
    for (int i=0; i < r; i++) {
        cin >> B[i].first >> B[i].second;
    }
    cout << (dfs(0) ? "Yes" : "No") << endl;;
	return 0;
}

