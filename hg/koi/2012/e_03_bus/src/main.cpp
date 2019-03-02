#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; //위치, 인원수
ll ans;
vector<pii> L, R;
int main() {
    int n, k, s; // 아파트 단지수, 버스정원, 학교위치
    cin >> n >> k >> s;
    for (int i=0; i < n; i++) {
        int pos, num;
        cin >> pos >> num;
        if (pos < s) {
            L.push_back(make_pair(pos-s, num));
        } else {
            R.push_back(make_pair(s-pos, num));
        }
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    
    int ptr = 0;
    while(true) {
        while(ptr < L.size() and L[ptr].second == 0) ptr++;
        if (ptr == L.size()) break;
        int capacity = k;
        ans += -(L[ptr].first*2); //왕복거리
        while(capacity > 0) {
            if (ptr == L.size()) break;
            int amount = min(capacity, L[ptr].second);
            capacity -= amount;
            L[ptr].second -= amount;
            if (L[ptr].second == 0) ptr++;
        }
    }
    
    ptr = 0;
    while(true) {
        while(ptr < R.size() and R[ptr].second == 0) ptr++;
        if (ptr == R.size()) break;
        int capacity = k;
        ans += -(R[ptr].first*2); //왕복거리
        while(capacity > 0) {
            if (ptr == R.size()) break;
            int amount = min(capacity, R[ptr].second);
            capacity -= amount;
            R[ptr].second -= amount;
            if (R[ptr].second == 0) ptr++;
        }
    }
    
    cout << ans << '\n';
    
	return 0;
}

