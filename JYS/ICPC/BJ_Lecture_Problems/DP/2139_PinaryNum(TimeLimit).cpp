//
//  main.cpp
//  icpc
//
//  Created by Spiritsensor on 2017. 5. 7..
//  Copyright © 2017년 JYS. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

int fib( int num ) {
    if( num == 0 ) return 0;
    if( num == 1 || num == 2) {
        return 1;
    }
    return fib(num-1) + fib(num-2);
}

int main() {
    scanf("%d", &N);
    printf("%d\n",fib(N));
    return 0;
}

/*
1 -> 1
2 -> 10
3 -> 100 / 101
4 -> 1000 / 1010 / 1001
5 -> 10000 / 10100 / 10101 / 10010 / 10001
6 -> 100000 / 101010 / 101001 / 100101 / 101000 / 100100/ 100010 / 100001
In form of Fibonacci.
*/