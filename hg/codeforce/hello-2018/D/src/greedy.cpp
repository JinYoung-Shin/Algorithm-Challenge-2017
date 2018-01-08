#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Data {
    int first, second, idx;
    
    bool operator<(const Data& rhs) const {
        if (first != rhs.first) {
            return first < rhs.first;
        } else {
            return second < rhs.second;
        }
    }
};
// vector<pair<int, int> > arr; // Time / Penalty
// priority_queue< pair<int, int> > pq; // Penalty / Time

vector<Data> arr; // Time / Penalty
priority_queue<Data > pq; // Penalty / Time
int main() {
    int n;
    ll T;
    cin >> n >> T;
    arr.reserve(n);
    for (int i=0;i < n; i++) {
        int a, t;
        cin >> a >> t;
        Data tmp;
        tmp.first = t;
        tmp.second = a;
        tmp.idx = i+1;
        // arr.push_back(make_pair(t, a));
        arr.push_back(tmp);
    }
    
    sort(arr.begin(), arr.end());
    
    //dump
    // for (size_t i=0; i< arr.size(); i++) {
    //     printf("%d, %d %d\n", arr[i].first, arr[i].second, arr[i].idx);
    // }
    //
    ll remain = T;
    for (int i=0; i < n; i++) {
        int tt = arr[i].first;
        int penalty = arr[i].second;
        int iidx = arr[i].idx;
        if (remain >= tt) { // 공간이 있을 경우 시간 작은것부터 넣는다. 
            remain -= tt;
            
            Data tmp;
            tmp.first = -penalty;
            tmp.second = tt;
            tmp.idx = iidx;
            pq.push(tmp);
            // pq.push(make_pair(-penalty, tt));
        } else { //공간이 없는 경우
            while(pq.size() > 0) { // 안되는놈 모조리 빼낸다.
                int min_penalty = -pq.top().first;  
                int spent_time = pq.top().second;
                if (min_penalty < pq.size()) {
                    pq.pop();
                    remain += spent_time;
                } else {
                    break;
                }
            }
            
            if (remain >= tt) {
                remain -= tt;
                
                Data tmp;
                tmp.first = -penalty;
                tmp.second = tt;
                tmp.idx = iidx;
                pq.push(tmp);
                // pq.push(make_pair(-penalty, tt));
                
            } else {
                break;
            }
        }
    }
    
    //dump
    // cout << "========================" << endl;
    
    while(pq.size() > 0) { // 안되는놈 모조리 빼낸다.
        int min_penalty = -pq.top().first;  
        // int spent_time = pq.top().second;
        if (min_penalty < pq.size()) {
            pq.pop();
        } else {
            break;
        }
    }
    

    cout << pq.size() << '\n' << pq.size() << '\n';
    
    while (pq.size() > 0) {
        // int penalty = -pq.top().first;
        // int elap_t = pq.top().second;
        int iidx = pq.top().idx;
        cout << iidx << ' ';
        // cout << penalty << ' ' << elap_t << ' ' << iidx << endl;
        pq.pop();
    }
    cout << '\n'; return 0;
    //
}