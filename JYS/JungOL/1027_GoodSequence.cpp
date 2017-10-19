//
//  main.cpp
//  AlgoKing
//
//  Created by 신진영 on 2017. 10. 19..
//  Copyright © 2017년 신진영. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int num;
int flag;
char s[100];

int strncmp(char* s1, char* s2, int n){
    while(n--){
        if(*s1 > *s2) return 1;
        else if (*s1 < *s2)return -1;
        s1++;
        s2++;
    }
    return 0;
}

int check(int n) {
    // 1 나와야 잘된거지
    int cnt = 0;
    if(n == 0) return 1;
    else {
        cnt = ++n / 2;
        for(int i = 1; i <= cnt; i++){
            if(strncmp(&s[n-i], &s[n-(2*i)], i) == 0)return 0;
        }
    }
    
    return 1;
}

void DFS(int n) {
//    if(n == 0){
//        s[0] = 1;
//        DFS(n+1);
//    }
    if(n >= num) {
        flag = 1;
    }
    else {
        for(char i = '1'; i <= '3'; i++) {
            s[n] = i;
            if(check(n)==0) continue;
            DFS(n+1);
            if(flag == 1) return;
            
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> num; // 숫자 입력받음
    DFS(0);
//    answer[0]= '1';
//    answer[1]= '2';
//    for(int t = 2; t < num; t++){ // answer을 다 채울 동안
//        for(char i = '1'; i <= '3'; i++) { // 1, 2, 3 별로 검사
//            // 요기만 잘 짜면됩니다...
//
//
//        }
//    }
    cout << s;

    return 0;
}
