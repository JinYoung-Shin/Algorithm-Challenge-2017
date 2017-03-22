#include <stdio.h>
#include <stdlib.h>

using namespace std;
int cost[1000] = {0,};

int main() {
	int num, day, team, i, j, k, l;
	double min, temp;

//	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	for(i=0; i<num; i++) {
		scanf("%d %d", &day, &team);
		for(j=0; j<day; j++) 
			scanf("%d", &cost[j]);
	
		min = 1000;
		for(j=0; j<day; j++) {
			temp=0;			
			for(k=j; k<day; k++){
				temp += cost[k];
				if((k-j+1)<team) 
					continue;
				if((temp/(k-j+1)) < min)
					min = temp/(k-j+1);
			}
		}
		printf("%.12f\n", min);
	}

	return 0;
}
