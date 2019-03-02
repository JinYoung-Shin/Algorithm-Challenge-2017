#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int size;
inline void push(int a) {
    arr[size++] = a;
}
inline int pop() {
    return size > 0 ? arr[--size] : -1;
}
inline int top() {
    return size > 0 ? arr[size-1] : -1;
}
inline int empty() {
    return size>0 ? 0 : 1;
}
inline int sz() {
    return size;
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int tmp;
            cin >> tmp;
            push(tmp);
        } else if (cmd == "pop") {
            cout << pop() << '\n';
        } else if (cmd == "size") {
            cout << sz() << '\n';
        } else if (cmd == "empty") {
            cout << empty() << '\n';
        } else if (cmd == "top") {
            cout << top() << '\n';
        }
    }
    return 0;
}
