#include <bits/stdc++.h>
using namespace std;

#define PRE 0
#define IN 1
#define POST 2

typedef struct _Data {
    char left;
    char right;
} Data;
Data data[26];


void tra(char pos, int type) {
    auto& t = data[pos - 'A'];
    if (type == PRE) {
        cout << pos;    
    }
    
    if (t.left) {
        tra(t.left, type);   
    }
    
    if (type == IN) {
        cout << pos;
    }
    
    if (t.right) {
        tra(t.right, type);
    }
    
    if (type == POST) {
        cout << pos;
    }
}


int main() {
    int n;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        char self, left, right;
        scanf("%c %c %c\n", &self, &left, &right);
        auto& t = data[self-'A'];
        if (left == '.') {
            t.left = '\0';
        } else {
            t.left = left;
        }
        if (right == '.') {
            t.right = '\0';
        } else {
            t.right = right;
        }
    }
    
    tra('A', PRE); cout << '\n';
    tra('A', IN); cout << '\n';
    tra('A', POST); cout << '\n';
	return 0;
}

