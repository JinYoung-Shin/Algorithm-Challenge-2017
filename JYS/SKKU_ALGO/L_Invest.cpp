#include <cstdio>
#include <iostream>

using namespace std;

int M, N;
int company[20][310];
int Max;
int arr[20];
int invest_arr[20];

void dfs(int n, int money, int benefit) {
   if(n >= N) {
      if(benefit > Max) {
         Max = benefit;
         for(int i = 0; i < N; i++) {
            arr[i] = invest_arr[i];
         }
      }
      return;
   }
   
   for(int i = 0; i <= money; i++) {
      invest_arr[n] = i;
      dfs(n + 1, money - i, benefit + company[n][i]);
      invest_arr[n] = 0;
   }
}

int main() {
   scanf("%d %d", &M, &N);
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         scanf("%d", &company[i][j]);
      }
   }
   dfs(0, M, 0);
   printf("%d\n", Max);
   for( int i = 0; i < N; i ++) {
      printf("%d ", arr[i]);
   }
   return 0;
}