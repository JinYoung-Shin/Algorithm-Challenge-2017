#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int day[100], dp[100][40], total, impo, impo_day;

int minCost(int count, int cou) {
	if(count >= total)
		return 0;
	if(dp[count][cou] < 0)
		dp[count][cou] = day[count] ? minCost(count+1, cou) : min({cou > 2 ? minCost(count+1, cou-3) : minCost(count+1, cou)+10000, minCost(count+3, cou+1)+25000, minCost(count+5, cou+2)+37000});

	return dp[count][cou];
};

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d %d", &total, &impo);

	// first assign	
	for(int i=0; i<impo; i++){
		scanf("%d", &impo_day);
		day[impo_day-1] = 1;
	}
	fill(dp[0], dp[100], -1);
	printf("%d\n", minCost(0, 0));

	return 0;
}
