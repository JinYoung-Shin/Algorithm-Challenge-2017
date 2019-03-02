#include <bits/stdc++.h>
using namespace std;

int arr[105];
int accu[105][105]; //해당 색상 갖는 누적합
inline int range(int s, int d, int c) {
    return accu[d][c] - accu[s-1][c];
}
vector<int> want;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (int i=1; i <= n; i++) {
        for (int c=1; c <= m; c++) {
            accu[i][c] = accu[i-1][c];
        }
        accu[i][arr[i]]++;
    }
    

    want.push_back(-1);
    int len = 0;
    for (int i=0; i < m; i++) {
        int tmp;
        cin >> tmp;
        len += tmp;
        want.push_back(tmp);
    }
    bool ans = false;
    
    for (int start=1; start <= n-len+1; start++) {
        int end = start + len - 1;
        bool ok = true;
        for (int k=1; k <= m; k++) {
            //k번째 색이 num개 나타나야 한다.
            auto& num = want[k];
            if (range(start, end, k) != num) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = true;
            // printf("%d ~ %d\n", start, end);
            break;
        }
    }
    
    cout << (ans ? "YES" : "NO") << endl;
	return 0;
}

