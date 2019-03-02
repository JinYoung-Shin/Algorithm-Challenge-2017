#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 100005
typedef long long ll;
typedef pair<ll, ll> pii;
ll arr[MAX_NUM];
ll n, x, k; //x로 나뉘는놈이 정확하게 k개 있어야 한다.

pii find(int i) {
    pii ret;
    ret.first = ret.second = -1;
    
    ll first;
    ll occur;
    if (x >= i) {
        first = x;
        occur = 1;
    } else { // i > x
        occur = (i+x-1)/x;
        first = x * occur;
    }
    
    if (k == 0) {
        ret.first = i;
        ret.second = first;
    } else {
        ret.first = first + (k-1) * x;
        ret.second = ret.first + x;
    }
    return ret;
}

int bin_search_left(int left, int right, pii range) {
    int mid = (left+right)/2;
    if (left > right) return -1;
    if (right - left == 1) {
        if (range.first <= arr[left]) {
            return left;
        } else if (range.first <= arr[right]) {
            return right;
        } else {
            return -1;
        }
    }
    if (left == right) {
        if (range.first <= arr[left]) {
            return left;    
        } else {
            return -1;
        }
    }
    if (range.first <= arr[mid]) {
        return bin_search_left(left, mid, range);
    } else {
        return bin_search_left(mid+1, right, range);
    }
}
int bin_search_right(int left, int right, pii range) {
    
    int mid = (left+right)/2;
    if (left > right) return -1;
    if (right - left == 1) {
        if (arr[right] < range.second) {
            return right;
        } else if (arr[left] < range.second) {
            return left;
        } else {
            return -1;
        }
    }
    if (left == right) {
        if (arr[left] < range.second) {
            return left;
        } else {
            return -1;
        }
    }
    if (arr[mid] < range.second) {
        return bin_search_right(mid, right, range);
    } else {
        return bin_search_right(left, mid-1, range);
    }
}

int main() {
    ll ans = 0;
    cin >> n >> x >> k;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    //debug//
    // for (int i=0; i < n; i++) {
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';
    // for (int i=0; i < n; i++) {
    //     pii ret = find(arr[i]);
    //     printf("for %d, (%d, %d)\n", arr[i], ret.first, ret.second);
    // }
    //debug//
    
    for (int i=0; i < n; i++) {
        pii range = find(arr[i]);
        // printf("for %d, (%d, %d) is acceptable\n", arr[i], range.first, range.second);
        int left_bound = bin_search_left(0, n-1, range);
        int right_bound = bin_search_right(0, n-1, range);
        // printf("%d ~ %d\n", left_bound, right_bound);
        if (left_bound == -1 || right_bound == -1) continue;
        ans += max(0, right_bound - left_bound + 1);
        // for (int j=0; j < n; j++) {
            // if (range.first <= arr[j] && arr[j] < range.second) {
            //     ans++;
            // } 
            // else if (j > i && arr[j] >= range.second) {
            //     break;
            // }
        // }
    }
    cout << ans << endl;
    return 0;
    
}