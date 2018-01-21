#include <bits/stdc++.h>
using namespace std;

int arr[30];
int input[30];
int ptr;
int val;
int n;
void search() {
    while(arr[ptr]) {
        ptr++;
        ptr %= n;
    }
}
int main() {
    cin >> n;
    cin >> val;
    arr[ptr] = val;
    for (int i=1; i < n; i++) {
        ptr += val;
        ptr %= n;
        search();
        cin >> input[i];
        arr[ptr] = val = input[i];
    }
    
    cout << n << endl;
    for (int i=0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
	return 0;
}

