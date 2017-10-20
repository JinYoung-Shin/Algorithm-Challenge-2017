//
//  main.cpp
//  AlgoKing
//
//  Created by 신진영 on 2017. 10. 20..
//  Copyright © 2017년 신진영. All rights reserved.
//

/*
 IDEA
 : 한번 나온 변으로 전체 넓이 구하고, 두번 나온 변에서 가운데 나오는 부분 넓이 빼뻐리면 전체 6각형의 넓이를 구할 수 있다 !!
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int K;
pair<int, int> dirlen[6+4];
int dir[2];
int arr[4+1][2] ={0};
int answer = 0;
int temp = 0;
int widthBig, widthSmall;
int bigXY[2];

int main(int argc, const char * argv[]) {
    cin >> K;
    for(int i = 0; i < 6; i++) {
        cin >> dirlen[i].first >> dirlen[i].second;
        if(arr[dirlen[i].first][0] == 0) {
            arr[dirlen[i].first][0] = dirlen[i].second;
        } else {
            arr[dirlen[i].first][1] = dirlen[i].second;
            dir[temp++] = dirlen[i].first;
        }
    }
    temp = 0;
    
    //big
    for(int i = 0; i <= 6; i++) {
        if(dirlen[i].first == dir[0] || dirlen[i].first == dir[1]) continue;
        bigXY[temp++] = dirlen[i].second;
    }
    
    widthBig = bigXY[0] * bigXY[1];
    
    //small
    for(int i = 0; i < 6; i++) {
        if(dirlen[i].second == bigXY[0] || dirlen[i].second == bigXY[1]) {
            if(i == 0 || i == 4) { // 4랑 같지?
                widthSmall = arr[dir[0]][1]*arr[dir[1]][0];
                break;
            }
            else if(i == 1) {
                widthSmall = arr[dir[0]][1]*arr[dir[1]][1];
                break;
            } else if(i == 2) {
                widthSmall = arr[dir[0]][0]*arr[dir[1]][1];
                break;
            } else if(i == 3) {
                widthSmall = arr[dir[0]][0]*arr[dir[1]][0];
                break;
            }
        }
    }
    answer = (widthBig-widthSmall) * K;
    cout << answer << endl;

    return 0;
}