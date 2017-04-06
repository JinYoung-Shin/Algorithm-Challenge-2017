#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define MIN 100000000

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int apt_area;
int N;
int arr[30][30];
int area[1000];

void dfs(int x, int y) {
	if(!arr[x][y]) {
		return;
	}
	arr[x][y] = 0;
	area[apt_area]++;
	for(int i = 0; i < 4; i++) {
		dfs(x +dx[i], y + dy[i]);
	}
}

int main() {
	scanf("%d", &N);
	for( int i = 1; i <= N; i++) {
		for( int j = 1; j <= N; j++) {
			scanf("%1d", &arr[i][j]);
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
	printf("%d\n", apt_area);
	sort(area, area + apt_area);
	for( int i = 0; i < apt_area; i++) {
		printf("%d\n", area[i]);
	}
	
	return 0;
}