#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int map[110][110], sum[110][110], N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> Que;
pair<int, int> p;

void bfs() {
	int x, y, newx, newy, tmp1;
	sum[0][0] = map[0][0];
	Que.push(make_pair(0, 0));

	while(!Que.empty()) {
		p = Que.front();
		Que.pop();
		x = p.first, y = p.second;
		for(int i=0; i<4; i++) {
			newx = x + dx[i];
			newy = y + dy[i];
			if(newx>=0 && newy>=0 && newx<N && newy<N) {
				tmp1 = sum[x][y] + map[newx][newy];
				if(tmp1 < sum[newx][newy]) {
					sum[newx][newy] = tmp1;
					Que.push(make_pair(newx, newy));
				}
			}
		}
	}
}

int main(void) {
	char tmp;
	// assigning
	//freopen("input.txt", "r", stdin);
	scanf("%d ", &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%c", &tmp);
			map[i][j] = tmp - '0';
			sum[i][j] = 0x7fffffff;
		}
		scanf("%c", &tmp);		
	}
	bfs();	
	printf("%d\n", sum[N-1][N-1]);

	return 0;
}
