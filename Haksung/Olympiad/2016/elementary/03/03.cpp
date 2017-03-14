#include <stdlib.h>
#include <stdio.h>

int student[2][6] = {0,};

int main() {
	int day[100][2] = {0,};
	int cost_sum, cost[3]={0,}, total, impo, impo_day, day_count, cou=0, i;
	
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &total, &impo);

	// first assign	
	for(i=0; i<total; i++)
		day[i][0] = 1;
	for(i=0; i<impo; i++){
		scanf("%d", &impo_day);
		day[impo_day-1][0] = 0;
	}
	day_count = total - impo;

	// algorithm for min_cost
	for(i=0; i<total; i++){
		if(day[i][0] == 1){
			
		}
	}

	// final cost
	cost[0] -= (cou/3);
	cost_sum = (cost[0] * 10000) + (cost[1] * 25000) + (cost[2] * 37000);
	printf("%d\n", cost_sum);
	
	return 0;
}
