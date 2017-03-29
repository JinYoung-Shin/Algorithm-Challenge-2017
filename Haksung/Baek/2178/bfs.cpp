#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> Que;
pair <int, int> q;
int N, M, map[102][102]={0,}, flag[102][102]={0,};

int main() {
	int x, y, size, cost=0;
	char tmp;

	// Assigning
	scanf("%d %d\n", &N, &M);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%c", &tmp);
			map[i][j] = tmp - '0';
		}	
		scanf("%c", &tmp);
	}

	// BFS
	Que.push(make_pair(1,1));
	flag[1][1] = 1;
	while(!Que.empty()) {
		cost++;
		size = Que.size();
		while(size--){
			q = Que.front();
			Que.pop();
			x = q.first, y = q.second;
			if(x==N && y==M) {
				printf("%d\n", cost);
				return 0;
			}
			if(map[x][y+1]==1 && (y+1)<=M && flag[x][y+1]==0) {
				Que.push(make_pair(x, y+1));
				flag[x][y+1] = 1;
			}
			if(map[x+1][y]==1 && (x+1)<=N && flag[x+1][y]==0) {
				Que.push(make_pair(x+1, y));
				flag[x+1][y] = 1;
			}
			if(map[x][y-1]==1 && (y-1)>0 && flag[x][y-1]==0) {
				Que.push(make_pair(x, y-1));
				flag[x][y-1] = 1;
			}
			if(map[x-1][y]==1 && (x-1)>0 && flag[x-1][y]==0) {
				Que.push(make_pair(x-1, y));
				flag[x-1][y] = 1;
			}
		}
	}
	
	return 0;
}
