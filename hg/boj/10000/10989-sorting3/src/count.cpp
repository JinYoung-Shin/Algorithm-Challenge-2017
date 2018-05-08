#include <bits/stdc++.h>
using namespace std;

int arr[10001];

int main() {
    int n;
    cin >> n; 
    for (int i=0;i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp]++;
    }
    
    for (int i=1; i<=10000;i++) {
        while(arr[i]) {
            printf("%d\n", i);
            arr[i]--;
        }
    }
}