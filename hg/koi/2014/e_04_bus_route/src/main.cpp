#include <bits/stdc++.h>
using namespace std;

int n, m;

struct Route {
    int src, dst, num;    
};

bool cmp(const struct Route& lhs, const struct Route& rhs) {
    if (lhs.src != rhs.src) return lhs.src < rhs.src;
    return lhs.dst > rhs.dst;
}

vector<Route> small, large; //인덱스 숫자가 작을수록 범위가 큰놈이다.
vector<bool> ans;
int main() {
    cin >> n >> m;
    ans.reserve(m+1);
    int large_over = -1;
    int large_below = n+1;
    int over = 0;
    for (int i=1; i<=m; i++) {
        Route tmp;
        scanf("%d %d", &tmp.src, &tmp.dst);
        tmp.num = i;
        if (tmp.src < tmp.dst) {
            small.push_back(tmp);
        } else {
            large_over = max(large_over, tmp.dst);
            large_below = min(large_below, tmp.src);
            large.push_back(tmp);
        }
    }
    sort(small.begin(), small.end(), cmp);
    sort(large.begin(), large.end(), cmp);
    
    //초기 large_over값은 large가 small 덮어쓰는 경우(0~over 범위로 덮는 경우임)
    //초기 large_below값은 large가 small 덮어쓰는 경우(below~N) 범위로 덮는 경우
    //진행하다보면 small이 small 덮어쓰는 경우도 있음
    for (size_t i=0; i < small.size(); i++) {
        if (small[i].dst <= large_over) ans[small[i].num] = true;
        else if (small[i].src >= large_below) ans[small[i].num] = true;
        if (small[i].dst <= over) {
            ans[small[i].num] = true;
        } else {
            over = small[i].dst;
        }
    }
    over = -1; //large가 large 덮어쓰는 경우
    for (size_t i=0; i < large.size(); i++) {
        if (large[i].dst <= over) ans[large[i].num] = true;
        else over = large[i].dst;
    }
    
    for (int i=1; i <= m; i++) {
        if (!ans[i]) {
            cout << i << '\n';
        }
    }
    
	return 0;
}

