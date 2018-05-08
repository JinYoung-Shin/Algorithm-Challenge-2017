#include <bits/stdc++.h>
using namespace std;
stack<int> Stack;
vector<bool> op;// true -> +(push) / false -> -(pop)
vector<int> seq;
void fail() {
    cout << "NO\n";
    exit(EXIT_SUCCESS);
}
int main() {
    int n;
    cin >> n;
    seq.reserve(n);
    for (int i=0; i < n; i++) {
        int tmp; cin >> tmp;
        seq.push_back(tmp);
    }
    int ptr = 0;
    for (int i=1; i <= n;) {
        auto& target_val = seq[ptr];
        auto& current_val = i;
        
        if (target_val == current_val) {
            // printf("넣고 뺀다(%d)\n", current_val);
            op.push_back(true);
            op.push_back(false);
            ptr++;
            i++;
        } else if (!Stack.empty() && target_val == Stack.top()) {
            // printf("뺀다(%d)\n", target_val);
            op.push_back(false);
            Stack.pop();
            ptr++;
        } else {
            // printf("넣는다(%d)\n", current_val);
            op.push_back(true);
            Stack.push(current_val);
            i++;
        }
    }
    while(!Stack.empty()) {
        auto& target_val = seq[ptr];
        auto& current_val = Stack.top();
        if (target_val == current_val) {
            op.push_back(false);
            Stack.pop();
            ptr++;
        } else {
            fail();
            // Stack.pop();
        }
    }
    //answer dump
    for (size_t i = 0; i < op.size(); i++) {
        if (op[i]) {
            putchar('+');
            putchar('\n');
        } else {
            putchar('-');
            putchar('\n');
        }
    }
    return 0;
}