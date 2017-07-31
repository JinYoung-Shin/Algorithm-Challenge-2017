/*
SoMa Interview
정수 N을 입력 받고 N 개의 배열을 입력 받는다.
다음으로 대상 수(K)를 입력 받고,
dfs를 이용하여 해당 배열 내 수의 조합의 합으로 K를 구할 수 있는지 검사한다.
구할 수 있으면 "YES" 출력 / 구할 수 없으면 "NO" 출력

ex)
입력 :
4
1 2 4 7
13
출력 :
YES
*/
#include <iostream>

using namespace std;

int N;
int arr[100 * 100 * 10];
int K;
//int sum = 0;
int ans = 0;

void dfs(int a, int s) {
    if(a == N) {
        if(s == K) {
            ans++;
        }
        return;
    }
    
    dfs(a+1, s+arr[a]);
    dfs(a+1, s);
}

int main()
{
   cin >> N;
   for(int i = 0; i < N; i++) {
       cin >> arr[i];
   }
   cin >> K;
   
   dfs(0, 0);
   
   if(ans != 0) cout << "YES" << endl;
   else cout << "NO" << endl;
   
   return 0;
}