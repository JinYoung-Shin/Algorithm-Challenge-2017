//
//  main.cpp
//  icpc
//
//  Created by Spiritsensor on 2017. 5. 7.
//  Copyright © 2017년 JYS. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, d[100010];
int arr[100010];
long long _Max = -99999999;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    d[1] = arr[1];
    _Max = arr[1]; // Should start _Max with first val...
    for(int i = 2; i <= n; i++) {
        d[i] = max(d[i-1]+arr[i], arr[i]);
        if(d[i] > _Max) _Max = d[i];
    }
    printf("%lld\n", _Max);
    return 0;
}