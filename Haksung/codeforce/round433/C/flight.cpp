#include <cstdio>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int c[n+1][2];
	for(int i=1; i<=n; i++) {
		scanf("%d", &c[i][0]);
		c[i][1] = 1;
	}
	
	int max = 0, num = 0;
	int sol[n+1];
	int min = 0;
	for(int i=k+1; i<=n+k; i++) {
		max = 0;
		for(int j=1; j<=i; j++) {
			if(c[j][1] == 1) {
				if(c[j][0] > max) {
					max = c[j][0];
					num = j;
				}
			}
		}
		c[num][1] = 0;
		min += (i-num) * max;
		sol[num] = i;
	}

	printf("%d\n", min);
	for(int i=1; i<=n; i++)
		printf("%d ", sol[i]);
	printf("\n");

	return 0;
}
