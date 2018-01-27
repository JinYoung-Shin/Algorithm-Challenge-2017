#include <bits/stdc++.h>
using namespace std;

int data[10009];
int front, rear, size;

inline void push(int x) {
    size++;
    data[rear++] = x;
}
inline void pop() {
    if (size > 0) {
        size--;
        cout << data[front++] << '\n';
    } else {
        cout << -1 << '\n';
    }
}
inline void get_front() {
    if (size == 0) {
        cout << -1 << '\n';
    } else {
        cout << data[front] << '\n';
    }
}
inline void get_back() {
    if (size == 0) {
        cout << -1 << '\n';
    } else {
        cout << data[rear-1] << '\n';
    }
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int X;
            cin >> X;
            push(X);
        } else if (cmd == "pop") {
            pop();
        } else if (cmd == "size") {
            cout << size << '\n';
        } else if (cmd == "empty") {
            cout << (size == 0 ? 1 : 0) << '\n';
        } else if (cmd == "front") {
            get_front();
        } else if (cmd == "back") {
            get_back();
        }
        
    }
	return 0;
}

