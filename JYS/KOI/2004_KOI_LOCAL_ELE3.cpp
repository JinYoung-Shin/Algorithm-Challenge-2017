#include <cstdio>
#include <iostream>

using namespace std;

int node, edge;
int arr[110][110] = { 0 };
int visited[110] = { 0 };

//pair<int, int> link;
int ans = -1;

//int dfs
int dfs(int Node) {
	visited[Node] = 1;
	ans++;
	for(int i = 1; i <= node; i++) {
		if(visited[i] != 1 && arr[Node][i] == 1) {
			dfs(i);
		}
	}
}

int main() {
	
	scanf("%d", &node);
	scanf("%d", &edge);
	
	for( int i = 1; i <= edge; i++) {
//		scanf("%d %d", link.first, link.second);
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	
	dfs(1);
	printf("%d\n", ans);
		
	return 0;
}