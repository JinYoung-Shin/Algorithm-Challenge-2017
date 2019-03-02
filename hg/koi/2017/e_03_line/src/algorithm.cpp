#include <bits/stdc++.h>
using namespace std;

#define NUM_STUDENT 100001 //학생수 최대
#define UNDEFINED 0 // 정답이 결정되지 않은 상태
set<int> larger_than_me[NUM_STUDENT], smaller_than_me[NUM_STUDENT];

int ans[NUM_STUDENT];
int n, m;
set<int> rest;
void fail() {
    cout << -1 << '\n';
    exit(EXIT_SUCCESS);
}
int main() {
    scanf("%d%d", &n, &m);
    
    //initialize rest set
    for (int i=1; i<=n;i++) {
        rest.insert(-i);
    }
    //initialize rest set
    
    if (n == 1) { //학생수 1명일때만 예외처리
        cout << 1 << '\n';
        return 0;
    }
    
    for (int i=0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // a > b라는 뜻
        smaller_than_me[a].insert(b); // a보다 작은 set에 b 추가.
        larger_than_me[b].insert(a);// b보다 큰 set에 a추가.
    }
    
    for (int cur = n; cur >= 1; cur--) {
        int larger_num = larger_than_me[cur].size();
        auto it = rest.begin();
        for (int i=0; i < larger_num; i++) {
            it++;
        }
        int kth_largest = -*it;
        ans[cur] = kth_largest;
        rest.erase(it);    
    }
    
    //check for validation - 주어진 조건은 맞는지 확인. 빠진 조건이 있는지는 안확인 ㅎㅎㅎ
    for (int cur = 1; cur < n; cur++) {
        int my_val = ans[cur];
        for (auto it : smaller_than_me[cur]) {
            int smaller_val = ans[it];
            if (smaller_val > my_val) {
                fail();
            }
        }
    }
    
    for (int i=1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
	return 0;
}

