#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>

#define MIN 100000000

using namespace std;

int max_dist;
int N; // 정비소 갯수

int dist_between[60];
int req_time[60];
int visited[60]; // 방문 여부

int min_time = 99999999;

void DFS( int n, int sum_time ) { // 위치, 시간
	// printf("N : %d\n", N);
	if(n >= N+1) {
		if(sum_time < min_time) {
			min_time = sum_time;
			printf("N : %d\n", min_time);
			return;
		}
	}
	
	if(sum_time >= min_time) {
		return;
	}
	
	for(int i = 1; i <= N+1; i++) {
		if(visited[i] == 1) {
			continue;
		}
		if(dist_between[i] - dist_between[n] <= max_dist) {
			visited[i] = 1;
			DFS(i, sum_time + req_time[i]);
			printf("req: %d\n", req_time[i]);
			visited[i] = 0;
		}
	}
}

int main(void)
{
      // 여기서부터 작성
	// printf("%d", min_time);
	scanf("%d", &max_dist);
	scanf("%d", &N);
	
	for( int i = 1; i <= N+1; i++) {
		scanf("%d", &dist_between[i]);
	}
	
	for( int i = 1; i <= N; i++) {
		scanf("%d", &req_time[i]);
	}
 	
	DFS(0, 0);
	
	printf("%d", min_time);
	
      return 0;
}