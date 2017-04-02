#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int graph[20][20];
int color[20];

int N, M;

int color_check(int n, int _color) {
	for( int j = 1; j <= n; j++ ) {
		if(graph[n][j] && color[j] == _color) {
			return 0;
		}
	}
	return 1;
}

int color_graph(int n) {
	
	if(n > N) return 1; // core ...
	
	for( int i = 1; i <= M; i++) {
		if(color_check(n, i)) {
			color[n] = i; // color[N] is done.
			if(color_graph(n+1)) return 1;
		}
	}
	
	return 0; //컬러 n 입력 안 될 경우
}

int main(void)
{
      // 여기서부터 작성
	scanf("%d %d", &N, &M);
	for( int i = 1; i <= N; i++) {
		for( int j = 1; j <= i; j++) {
			scanf("%d", &graph[i][j]);
			if( i != j ) {
				graph[j][i] = graph[i][j];
			}
		}
	} // initialization
	
	if(color_graph(1)) {
		for(int i = 1; i <= N; i++) {
			printf("%d ", color[i]);
		}
	}
	else {
		printf("-1");
	}
	printf("\n");
	 	
	  return 0;
}