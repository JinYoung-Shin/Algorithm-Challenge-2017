#include <bits/stdc++.h>
using namespace std;

void go(list<int>::iterator &p, int n, list<int>::iterator begin, list<int>::iterator end) {
    for (int i=0; i < n; i++) {
        if (p != end) {
            p++;
            if (p == end) p = begin;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    list<int> arr;
    
    for (int i=1; i<= n; i++) {
        arr.push_back(i);
    }
    
    list<int>::iterator victim = arr.begin();
   
   cout << '<';
    for (int i=0; i< n; i++) {
        go(victim, m-1, arr.begin(), arr.end());
        cout << *victim;
        if (i < n-1) cout << ", ";
        list<int>::iterator tmp = victim;
        go(tmp, 1, arr.begin(), arr.end());
        arr.erase(victim);
        victim = tmp;
    }
    cout << ">\n";
  
   
    return 0;
}