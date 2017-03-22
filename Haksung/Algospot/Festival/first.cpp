#include <stdio.h>
#include <stdlib.h>

using namespace std;
int cost[1000][100] = {0,};

int main() {
	int num, day[100], team[100], i, j, k, l;
	double min, temp;

//	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	for(i=0; i<num; i++) {
		scanf("%d %d", &day[i], &team[i]);
		for(j=0; j<day[i]; j++) 
			scanf("%d", &cost[j][i]);
	}
	
	for(i=0; i<num; i++) {
		min = 1000;
		for(j=team[i]; j<=day[i]; j++) {
			for(k=0; k<(day[i]-j+1); k++) {
				temp = 0;
				for(l=0; l<j; l++)
					temp += cost[k+l][i];
				temp /= j;
				if(temp < min)
					min = temp;
			}
		}
		printf("%.12f\n", min);
	}

	return 0;
}
