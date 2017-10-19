//
//  main.cpp
//  AlgoKing
//
//  Created by 신진영 on 2017. 10. 17..
//  Copyright © 2017년 신진영. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int arr[10][10];
int cnt;
int temp;
int flag = 0;

int check(int x, int y, int z) {
    //행
    for(int i = 1; i <= 9; i++) {
        if(arr[x][i] == z) {
            return 0;
        }
    }
    //열
    for(int i = 1; i <= 9; i++) {
        if(arr[i][y] == z) {
            return 0;
        }
    }
    //3*3
    //1, 1 / 1, 4 / 1, 7
    //4, 1 / 4, 4 / 4, 7
    //7, 1 / 7, 4 / 7, 7
    int xx = ((x-1)/3)*3;
    int yy = ((y-1)/3)*3;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            if(arr[xx+i][yy+j] == z) {
                return 0;
            }
        }
    }
    
    return 1;
}

int go() {
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            if(arr[i][j] == 0) { // 안채워진 부분 => 채우고 무한히 진행해보고 안되면 빠져..
                for(int k = 1; k <= 9; k++) {
                    if(check(i, j, k)==1) {
                        arr[i][j] = k;
                        go();
                        if(flag == 1) return 0; // 종료시켜
                        arr[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }
    flag = 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            cin >> arr[i][j];
        }
    } // 문제 스도쿠 입력
    
    go();
    
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    } // 문제 스도쿠 출력
    
    return 0;
}
