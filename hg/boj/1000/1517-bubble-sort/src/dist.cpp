#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
P arr[500000];
int main() {
    int n;
    cin >> n;
    for (int i=0; i< n; i++) {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    
    sort(arr, arr+n);
    
    for (int i=0; i < n; i++) {
        printf("(%d: %d) ", arr[i].first, arr[i].second);
    }
    return 0;
}
