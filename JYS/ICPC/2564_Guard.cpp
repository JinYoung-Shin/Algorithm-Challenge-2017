//
//  main.cpp
//  AlgoKing
//
//  Created by 신진영 on 2017. 10. 20..
//  Copyright © 2017년 신진영. All rights reserved.
//

/*
방향 케이스 별로 일일히 체크해서 계산할 수도 있지만,
방향 별로 거리의 합을 나타내어 간결하게 문제를 해결할 수 있다.
방향의 차가 둘레의 절반보다 클 경우 전체 둘레에서 방향의 차를 빼서 계산하는 것이 중요하다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int x,y,n;
int answer = 0;
int val[110];
pair<int, int> point[110];

int ans = 0;

int abs(int a) {
    if(a >= 0) {
        return a;
    } else {
        return -a;
    }
}

int main(int argc, const char * argv[]) {
    cin >> x >> y >> n;
    for(int i = 0; i <= n; i++) { // i == n이 myPoint
        cin >> point[i].first >> point[i].second;
        if(point[i].first == 1) {
            val[i] = point[i].second;
        } else if(point[i].first == 2) {
            // 남
            val[i] = 2*x + y - point[i].second;
        } else if(point[i].first == 3) {
            val[i] = 2*x + 2*y - point[i].second;
        } else {
            val[i] = x + point[i].second;
        }
    }
    
    for(int i = 0; i < n; i++) {
        int temp = abs(val[n] - val[i]);
        if(temp > x + y) {
            answer += 2*(x+y) - temp;
        } else {
            answer += temp;
        }
    }
    cout << answer;
    
//    cin >> x >> y;
//    cin >> n;
//    for(int i = 0; i < n; i++) {
//        cin >> point[i].first >> point[i].second;
//    }
//    cin >> my_point.first >> my_point.second;
//    if(my_point.first == 1 || my_point.first == 2) {
//        mine = y;
//        notmine = x;
//    } else {
//        mine = x;
//        notmine = y;
//    }
//
//    // 계산
//    for(int i = 0; i < n; i++) {
//        if(abs(my_point.first - point[i].first) == 0) { // 같은 줄
//            ans += abs(my_point.second - point[i].second);
//            continue;
//        } else if(my_point.first - point[i].first == 1) { // 왼쪽면
//
//        }
//        else if (abs(my_point.first - point[i].first) == 2) {
//            ans += min(mine + my_point.second + point[i].second, mine + (notmine - my_point.second) + (notmine - point[i].second));
//        } else {
//
//        }
//    }

    return 0;
}
