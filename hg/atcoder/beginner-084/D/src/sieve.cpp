#include <bits/stdc++.h>
using namespace std;

#define LIMIT 320
// sqrt(10000) ~= 320!

bool P[100001];// 에라토스테네스의 채. false -> 소수, true -> 합성수
int accu[50002]; // 누적합. accu[i] -> 1부터 2i-1 까지의 2017 similar 수의 개수. accu[0]은 항상 0;
bool is_prime(int n) { // 2부터 sqrt(n)까지 나누어서 소수인지 확인
    int limit = ((int)sqrt(n))+1;
    limit = min(limit, n-1);
    for (int i=2; i <= limit; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void set_sieve() { //에라토스테네스의 채 셋팅
    for (int i=2; i <= LIMIT; i++) {
        if (P[i]) continue;
        if (is_prime(i)) {
            // printf("set sieve, %d is prime\n", i);
            int base = i;
            int checker = i+i;
            while (checker <= 100000) {
                P[checker] = true;
                checker += base;
            }
        }
    }
}
inline bool similar(int n) { // 2017 similar 수인지 확인
    return P[n] == false and P[(n+1)/2] == false;
}
void set_accu() { //누적합 만들기
    int cnt = 0;
    int val = 1;
    for (int i=1; i<= 50000; i++) {
        if (similar(val)) cnt++;
        accu[i] = cnt;
        val += 2;
    }
}
int main() {
    P[0] = P[1] = true;
    int q;
    scanf("%d", &q);
    set_sieve();
    set_accu();
    
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int cnt = accu[(r+1)/2] - accu[(l+1)/2-1];

        printf("%d\n", cnt);
    }
    
    
    return 0;
}