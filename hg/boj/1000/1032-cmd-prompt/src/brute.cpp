#include <bits/stdc++.h>
using namespace std;

vector<string> arr;
char all_equal(int index) {
    char ch = arr[0][index];
    for (size_t i=1; i < arr.size(); i++) {
        char n = arr[i][index];
        if (ch != n ) return '\0';
    }
    return ch;
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        string str;
        cin >> str;
        arr.push_back(str);
    }
    for (size_t i=0; i < arr[0].size(); i++) {
        char ch = all_equal(i);
        if (ch) {
            putchar(ch);
        } else {
            putchar('?');
        }
    }
    putchar('\n');
	return 0;
}

