#include <bits/stdc++.h>
using namespace std;

vector<int> child[1001];
set<int> leaf;

inline bool is_leaf(int i) {
    return leaf.find(i) != leaf.end();
}
int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        child[parent].push_back(i);
    }
    
    
    //check leaf
    for (int i=1; i<= n; i++) {
        if (child[i].size() == 0) {
            leaf.insert(i);
        }
    }
    
    //dumjp
    // for (int i=1; i <= n; i++) {
    //     printf("%d - ", i);
    //     for (size_t j=0; j < child[i].size(); j++) {
    //         printf("%d ", child[i][j]);
    //     }
    //     putchar('\n');
    // }
    
    
    for (int i=1; i <= n; i++) {
        if (is_leaf(i)) continue;
        size_t sz = child[i].size(); //number of children
        
        int num_of_leaf_child = 0;
        for (int j=0; j < sz; j++) {
            int child_idx = child[i][j];
            if (is_leaf(child_idx)) {
                num_of_leaf_child++;
            }
        }
        if (num_of_leaf_child < 3) {
            cout << "No" << endl;
            return 0;
        }
        
    }
    cout << "Yes\n";
    return 0;
}