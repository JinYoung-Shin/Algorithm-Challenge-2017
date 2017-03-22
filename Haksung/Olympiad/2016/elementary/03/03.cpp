#include <stdlib.h>
#include <stdio.h>

int day[100] = {0,};
int day_count(int count, int index);

int main() {
	int cost_sum, cost[3]={0,}, cou=0;
	int total, impo, impo_day;
	int count, index;
	int day_left, i=0, day_num;
	
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &total, &impo);

	// first assign	
	for(i=0; i<total; i++)
		day[i] = 1;
	for(i=0; i<impo; i++){
		scanf("%d", &impo_day);
		day[impo_day-1] = 0;
	}
	day_left = total - impo;

	// count continuous days
	i = 0;
	while(i < total){
		if(day[i]==1){
			day_num = day_count(0, i);
			for(int j=0; j<day_num; j++)
				day[i+j] = day_num;
			i += day_num;
		}
		else
			i++;
	}

	// find min_cost algorithm

	// for print
	for(i=0; i<total; i++)
		printf("%d ", day[i]);
	printf("\n");

	// final cost
/*
	cost[0] -= (cou/3);
	cost_sum = (cost[0] * 10000) + (cost[1] * 25000) + (cost[2] * 37000);
	printf("%d\n", cost_sum);*/
	
	return 0;
}

int day_count(int count, int index) {
	if(day[index]==1)
		return day_count(++count, ++index);
	else
		return count;
};
