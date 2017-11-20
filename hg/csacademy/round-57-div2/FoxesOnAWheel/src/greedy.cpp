#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> hid_pos;
bool pos[100005];
int main() {

    int n, k;
    int ans = 0;
    cin >> n >> k;
    
    hid_pos.reserve(k);
    
    //input foxes
    for (int i=0; i < k; i++) {
        int tmp;
        scanf("%d", &tmp);
        pos[tmp] = true;
    }
    for (int i=0; i < k; i++) {
        int tmp;
        scanf("%d", &tmp);
        hid_pos.push_back(tmp);
    }
    sort(hid_pos.begin(), hid_pos.end());
    
    for (size_t i=0; i < hid_pos.size(); i++) {
        int cur_pos = hid_pos[i];
        int left_pos = cur_pos == 1 ? n : cur_pos - 1;
        int right_pos = cur_pos == n ? 1 : cur_pos + 1;
        if (pos[left_pos]) {
            pos[left_pos] = false;
            ans++;
            continue;
        }

        if (pos[right_pos]) {
            pos[right_pos] = false;
            ans++;
            continue;
        }
    }
    for (int i=0; i <= n; i++) {
        if (pos[i]) {
            ans += 2;
        }
    }
    cout << ans << '\n';
    return 0;
}