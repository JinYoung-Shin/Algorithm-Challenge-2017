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

int chu[35];
int ball[10];
int flag[10] = {0};
int c, b;

int go(int n, int w1, int w2) {
    if(n > c) {
        if(w1 == w2) {
            return 1;
        }
        return 0;
    }

    if(go(n+1, w1+chu[n], w2) == 1) return 1;;
    if(go(n+1, w1, w2) == 1) return 1;
    if(go(n+1, w1, w2+chu[n])) return 1;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    // 추 입력
    cin >> c;
    for(int i = 0 ; i < c; i++) {
        cin >> chu[i];
    }
    // 구슬 입력
    cin >> b;
    for(int i = 0 ; i < b; i++) {
        cin >> ball[i];
    }
    
    // chu의 조합으로 ball[i]의 무게를 알 수 있느냐 없느냐인데,
    // chu는 양쪽에 다 올라갈 수 있어
    for(int i = 0 ; i < c; i++) {
        if(go(0, 0, ball[i]) == 1) { // 추의 개수, 왼쪽(추 무게)
            cout << "Y" << " ";
        } else {
            cout << "N" << " ";
        }
    }
        
    return 0;
}