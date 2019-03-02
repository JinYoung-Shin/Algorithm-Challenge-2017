#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; //src, dst
map<pii, int> order; // map<make_pair(dst, src) = size;

int loaded[2001];
int main() {
    int ans = 0;
    int capacity;
    int n, c, m;
    cin >> n >> c >> m;
    capacity = c;
    for (int i=0; i < m; i++) {
        int src, dst, size;
        cin >> src >> dst >>size;
        order[make_pair(dst, src)] = size;
    }
    
    auto it = order.begin();
    for (int pos = 1; pos <= n; pos++) {
        if (loaded[pos] > 0) {
            int& unload_amt = loaded[pos];
            capacity += unload_amt;
            ans += unload_amt;
            // printf("%d에서 내린다 : %d\n", pos, unload_amt);
            unload_amt = 0;
        }
        
        while(capacity > 0 and it != order.end()) {
            int src = it->first.second;
            int dst = it->first.first;
            int size = it->second;
            if (src < pos) {
                it++;
                continue;
            } else if (src > pos) {
                break;
            } else { //src == pos
                int load_amount = min(capacity, size);
                // if (load_amount > 0) {
                //     printf("%d에서 %d만큼 태웁니다.\n", pos, load_amount);
                // }
                loaded[dst] += load_amount;
                capacity -= load_amount;
                it++;
            }
        }
    }
    
    cout << ans <<'\n';
    return 0;
}