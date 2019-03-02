#include <bits/stdc++.h>
using namespace std;

char a[20], b[20];

char ans[20]; //answer string
int lft[10]; // 0~9까지 아라비안숫자 남은 개수

void make_max(char *str) { //남은걸로 만들 수 있는 최대값을 만든다.
    int l = strlen(str);
    sort(str, str+l, greater<char>());
}
void swap(char& a, char& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
bool get_answer(int k, int limit) { //리턴값 -> 답을 구할수 있는지 여부

    if (k >= limit) return true;
    int b_digit = b[k] - '0';
    if (lft[b_digit] > 0) { //앞자리 수가 같으면, 뒤에꺼 사부작해서 가능한지 봐야함
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
    if (lft[cur_digit] > 0) { //cur_digit -> 차선책
        ans[k] = cur_digit + '0';
        lft[cur_digit]--;
        k++;
        int val = 9;
        while (k < limit and val >= 0) {
            while(val >= 0 and lft[val] == 0) {
                val--;
            }
            while(val >= 0 and lft[val] > 0) {
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