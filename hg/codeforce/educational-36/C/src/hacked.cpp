#include <bits/stdc++.h>
using namespace std;

char a[20], b[20];

char ans[20]; //answer string
int lft[10]; // 0~9까지 아라비안숫자 남은 개수

void make_max(char *str) { //최대값을 만든다.
    int l = strlen(str);
    sort(str, str+l, greater<char>());
}
void swap(char& a, char& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
bool get_answer(int k, int limit) {
    //dump
    // printf("get_answer(%d, %d)\n", k, limit);
    //dump
    
    if (k >= limit) return true;
    int b_digit = b[k] - '0';
    if (lft[b_digit] > 0) {
        lft[b_digit]--;
        ans[k] = b_digit + '0';
        if(get_answer(k+1, limit)) {
            return true;
        }
        lft[b_digit]++;
    } 
    
    
    int cur_digit = b_digit-1;
    while(lft[cur_digit] == 0 and cur_digit >= 0) {
        cur_digit--;
    }
    if (cur_digit > 0) { //cur_digit -> 차선책
        ans[k] = cur_digit + '0';
        lft[cur_digit]--;
        k++;
        int val = 9;
        while (k < limit) {
            // printf("when k=%d ----------------------\n", k);
            // //dump
            // for (int i=0;i < 10; i++) {
            //     printf("[%d]: %d\n", i, lft[i]);
            // }
            //dump
            
            
            while(val >= 0 and lft[val] == 0) {
                val--;
            }
            while(lft[val] > 0) {
                lft[val]--;
                ans[k] = val + '0';
                k++;
            }
        }
        ans[k] = '\0';
        return true;
 
    } else {
        return false;
    }
    
}
int main() {
    scanf("%s%s", a, b);
    int a_len = strlen(a);
    int b_len = strlen(b);
    for (int i=0; i < a_len; i++) {
        char ch = a[i];
        int index = ch-'0';
        lft[index]++;
    }
    //dump
    // for (int i=0;i < 10; i++) {
    //     printf("[%d]: %d\n", i, lft[i]);
    // }
    // //dump
    
    if (a_len < b_len) {
        make_max(a);
        printf("%s\n", a);
        return 0;
    } else {
        if (get_answer(0, a_len)) {
            printf("%s\n", ans);
            return 0;
        } else {
            printf("invalid\n");
            return 0;
        }
    }
}