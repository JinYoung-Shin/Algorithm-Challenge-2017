#include <bits/stdc++.h>
using namespace std;
struct data {
    int num, gold, silver, bronze;
    
    bool operator < (const data& rhs) const {
        return gold != rhs.gold ? gold > rhs.gold : (silver != rhs.silver ? silver > rhs.silver : bronze > rhs.bronze);
    }
    bool operator == (const data& rhs) const {
        return gold == rhs.gold && silver == rhs.silver && bronze == rhs.bronze;
    }
};
vector<data> arr;
int main() {
    int n, k;
    cin >> n >> k;
    arr.reserve(n);
    for (int i=0; i < n; i++) {
        data tmp;
        scanf("%d %d %d %d\n", &tmp.num, &tmp.gold, &tmp.silver, &tmp.bronze);
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    
    int rank = 0;
    int accu = 1;
    data prev;
    prev.gold = prev.silver = prev.bronze = -1;
    //dump
    for (int i=0; i < n; i++) {
        auto& a = arr[i];
        if ( (prev == a) == false) {
            rank += accu;
            accu = 1;
        } else {
            accu++;
        }
        // printf("rank %d - ", rank);
        if (a.num == k) {
            cout << rank << '\n';
            return 0;
        }
        
        prev = a;
        // printf("(%d) %d, %d, %d\n", a.num, a.gold, a.silver, a.bronze);
    }
    //dump
}