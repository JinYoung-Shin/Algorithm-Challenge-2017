#include <bits/stdc++.h>
using namespace std;

#define NUM 1000000
int arr[NUM];

void merge(int start, int mid, int end) {
    // printf("merge(%d, %d, %d)\n", start, mid, end);
    vector<int> tmp;
    tmp.reserve(end-start+1);
    int ptr1 = start;
    int ptr2 = mid;
    while(ptr1 < mid and ptr2 < end) {
        if (arr[ptr1] < arr[ptr2]) {
            tmp.push_back(arr[ptr1]);
            ptr1++;
        } else {
            tmp.push_back(arr[ptr2]);
            ptr2++;
        }
    }
    while (ptr1 < mid) {
        tmp.push_back(arr[ptr1]);
        ptr1++;
    }
    while(ptr2 < end) {
        tmp.push_back(arr[ptr2]);
        ptr2++;
    }
    for (size_t i=0; i < tmp.size(); i++) {
        // printf("arr[%d] = %d\n", start+i, tmp[i]);
        arr[start+i] = tmp[i];
    }
}
void merge_sort(int start, int end) {
    if (end - start <= 1) return;
    // if (start >= end) return;
    // if (end - start == 1) return;
    int mid = (start+end)/2;
    
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, mid, end);
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i <n ;i++) {
        cin >> arr[i];
    }
    merge_sort(0, n);
    for (int i=0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}
