#include <bits/stdc++.h>
using namespace std;

int gear[4][8];
int pos[4]; //12시 방향을 의미함. ++하면 반시계, --하면 시계방향 회전
int rot_delta[4];
int get_polar(int num, int clock) {
    int base = pos[num] + clock;
    if (base >= 8) {
        base = base % 8;
    }
    while (base < 0) {
        base += 8;
    }
    return gear[num][base];
}
int main() {
    for (int i=0; i < 4; i++) {
        for (int j=0; j < 8; j++) {
            scanf("%1d", &gear[i][j]);
        }
    }
    
    int rot;
    cin >> rot;
    for (int i=0; i < rot; i++) {
        int num, dir;
        cin >> num >> dir;
        num--;
        rot_delta[num] = dir; //현재꺼 회전량 저장
        
        int prev = num;
        int cur = prev + 1;
        int prev_dir = dir;
        while (cur < 4) {
            if (get_polar(prev, 2) == get_polar(cur, 6)) break;
            rot_delta[cur] = -prev_dir;
            prev_dir = -prev_dir;
            prev = cur;
            cur++;
        }
        prev = num;
        cur = prev - 1;
        prev_dir = dir;
        while (cur >= 0) {
            if (get_polar(prev, 6) == get_polar(cur, 2)) break;
            rot_delta[cur]  = -prev_dir;
            prev_dir = -prev_dir;
            prev = cur;
            cur--;
        }
        
        for (int j=0; j < 4; j++){
            pos[j] -= rot_delta[j];
            rot_delta[j] = 0;
        }
            
    }
    int ans = 0;
    ans += (get_polar(0, 0) == 0 ? 0 : 1);
    ans += (get_polar(1, 0) == 0 ? 0 : 2);
    ans += (get_polar(2, 0) == 0 ? 0 : 4);
    ans += (get_polar(3, 0) == 0 ? 0 : 8);
    
    
    //dump
    // for (int i=0; i < 4; i++) {
    //     for (int j=0; j < 8; j++) {
    //         printf("%d ", gear[i][j]);
    //     }
    //     putchar('\n');
    // }
    
    cout << ans << endl;
	return 0;
}

