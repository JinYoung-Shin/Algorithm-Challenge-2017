#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define MIN 100000000

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int apt_area = 1;
int N;
int arr[300][300];
int area[200] = {0};

void dfs(int x, int y) {
	
	if(!arr[x][y]) {
		return;
	}
	area[apt_area]++;
	for( int i = 0; i < 4; i++) {
		dfs(x +dx[i], y + dy[i]);
	}
}

int main() {
	scanf("%d", &N);
	for( int i = 1; i <= N; i++) {
		for( int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for( int i = 1; i <= N; i++) {
		for( int j = 1; j <= N; j++) {
			if(arr[i][j]) {
				dfs(i, j);
				apt_area++;
			}
		}
	}
	printf("%d\n", apt_area - 1);
	sort(area, area + apt_area);
	for( int i = 1; i <= apt_area; i++) {
		printf("%d\n", area[i]);
	}
	
	return 0;
}