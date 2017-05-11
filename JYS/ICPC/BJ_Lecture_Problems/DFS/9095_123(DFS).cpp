#include <cstdio>
#include <iostream>

using namespace std;

int T;
int num;

int dfs(int count, int sum, int goal) {
	if(count > 10) {
		return 0;
	}
	if(sum > goal) {
		return 0;
	}
	if(sum == goal) {
		return 1;
	}
	int ans = 0; 
	ans+=dfs(count + 1, sum + 1, goal);
	ans+=dfs(count + 1, sum + 2, goal);
	ans+=dfs(count + 1, sum + 3, goal);
	return ans;
}

int main() {
	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		scanf("%d", &num);
		printf("%d\n",dfs(0, 0, num));		
	}
	return 0;
}