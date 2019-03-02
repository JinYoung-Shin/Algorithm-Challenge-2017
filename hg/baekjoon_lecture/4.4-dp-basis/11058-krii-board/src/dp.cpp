#include <bits/stdc++.h>
using namespace std;

long long dp[101]; //N번 눌러서 출력할 수 있는 최대 값

/*
입력한 A의 개수는 항상 증가하므로,
전체선택과 복사하기는 가장 나중에 하는 것이 항상 유리하다
3번 키를 눌러서 복사하기를 한번 할 수 있고
4번 키를 눌러서 복사하기를 두번 할 수 있고
5번 키를 눌러서 복사하기를 세번 할 수 있다...
이것은

3번 키를 눌러서 크기를 2배로 증가
4번 키를 눌러서 크기를 3배로 증가
5번 키를 눌러서 크기를 4배로 증가....
이러한 패턴이 가능하다는 것.
*/
int main() {
    int N;
    cin >> N;
    for (int i=1; i <= N; i++) {
        dp[i] = dp[i-1] + 1;
        if (i >= 4) {
            for (int j=3; j < i; j++) {
                long long next = dp[i - j] * (j - 1);
                dp[i] = max(dp[i], next);    
            }
        }
    }
    cout << dp[N] << endl;
	return 0;
}

