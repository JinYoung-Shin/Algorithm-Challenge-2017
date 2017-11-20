#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> len;
bool left_open, right_open;
int main() {
    ll ans = 0;
    ll max_seg_len = -987654321;
    string str;
    ll n, k;
    cin >> n >> k >> str;
    len.reserve(100000);

    ll current_seg_len = 0;
    if (str[0] == '0') left_open = true;
    if (str[n-1] == '0') right_open = true;
    
    for (ll i=0; i < n; i++) {
        char ch = str[i];
        if (ch == '1') {
            if (current_seg_len > 0) {
                len.push_back(current_seg_len);
                current_seg_len = 0;
            }
        } else { // ch == '0'
            current_seg_len++;
        }
    }
    
    if (current_seg_len > 0) {
        len.push_back(current_seg_len);
    }
    
    for (size_t i=0; i < len.size(); i++) {
        max_seg_len = max(max_seg_len, len[i]);
    }

    
    ans = max(ans, max_seg_len); // middle segment case
    if (left_open && right_open) {
        if (len.size() == 1) { //consist of only '0's
            ans = max(ans, (n*k) );
        } else if (k > 1) { //cancatenating head and tail
            ans = max(ans, len[0] + len[len.size()-1] );
        }
    }
    cout << ans << '\n';

    return 0;
}