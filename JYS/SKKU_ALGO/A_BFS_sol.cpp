#include <stdio.h>
 
#define INF 0x7fffffff
int N;
int a[100+10][100+10];
int sol;
 
int sum[100+10][100+10];
 
#define MAX (100*100*100+10)
struct _data
{
      int i, j;
};
struct _data Queue[MAX];
int Rp, Wp;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
 
int BFS(void)
{
      struct _data d1, d2;
      int k, ni, nj;
 
      sum[0][0] = a[0][0];
      d1.i = 0;
      d1.j = 0;
      Queue[Wp++] = d1;
 
      for(;;)
      {
            if(Rp == Wp) return sum[N-1][N-1];
 
            d2 = Queue[Rp++];
 
            for(k=0; k<4; k++)
            {
                  ni = d2.i + di[k];
                  nj = d2.j + dj[k];
                  if(ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
                  if(sum[d2.i][d2.j] + a[ni][nj] >= sum[ni][nj]) continue;
                  sum[ni][nj] = sum[d2.i][d2.j] + a[ni][nj];
                  d1.i = ni;
                  d1.j = nj;
                  Queue[Wp++] = d1;
            }
      }
}
 
int main(void)
{
      int i, j;
 
      scanf("%d", &N);
      for(i=0; i<N; i++)
      {
            for(j=0; j<N; j++)
            {
                  scanf("%1d", &a[i][j]);
            }
      }
 
      for(i=0; i<N; i++)
      {
            for(j=0; j<N; j++)
            {
                  sum[i][j] = INF;
            }
      }
 
      sol = BFS();
 
      printf("%d", sol);
 
      return 0;
}