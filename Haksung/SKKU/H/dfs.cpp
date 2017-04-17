#include <cstdio>

int N, W[10], V[10], A, max, sol[10], tmp[10];
int sqr_num[] = { 0,1,2,4,8,16,32,64,128 };
 
void dfs(int n, int sum,int worthy) {
      int i;
      if (sum == 0) {
            if (max < worthy) {
                  max = worthy;
                  for (i = 1; i <= 7; i++) sol[i] = tmp[i];
            }
            return;
      }
      if (n == 8) return;
      if (sum<sqr_num[n]) return;
 
      for (i=0; ; i++) {
            if (sum - i*sqr_num[n] >= 0) {
                  tmp[n] = i;
		  if(i>=5)	dfs(n + 1, sum - i*sqr_num[n], worthy + i*V[n]+ A*i);
		  else		dfs(n + 1, sum - i*sqr_num[n], worthy + i*W[n]+ A*i);
                  tmp[n] = 0;
            }
            else break;
      }
}

int main() {
	// input
	scanf("%d", &N);
	for(int i=1; i<=7; i++)	scanf("%d", &W[i]);
	for(int i=1; i<=7; i++)	scanf("%d", &V[i]);
	scanf("%d", &A);
	dfs(1, N, 0);

	// output
	printf("%d\n", max);
	for(int i=1; i<=7; i++)	printf("%d ", sol[i]);

	return 0;
}
