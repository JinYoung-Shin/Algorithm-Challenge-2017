#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

char map[1000][1000];
bool flag[1000][1000];
int M, N;
stack <pair <int, int> > Stack;
pair <int, int> tmp;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool isIn(int x, int y) {
	return x>=0 && y>=0 && x<M && y<N;
}

int main() {
	int result=0, x, y, newX, newY;
	char tmpC;

	// input
	scanf("%d %d\n", &M, &N);
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++)
			scanf("%c", &map[i][j]);
		scanf("%c", &tmpC);
	}

	// dfs
	for(int i=0; i<N; i++) {
		if(map[0][i] == '0') {
			Stack.push(make_pair(0, i));
			flag[0][i] = true;
		}
	}
	while(!Stack.empty()) {
		tmp = Stack.top();
		Stack.pop();
		x = tmp.first;
		y = tmp.second;
		if(x==M-1) {
			result=1;
			break;
		}
		for(int i=0; i<4; i++) {
			newX = x + dx[i];
			newY = y + dy[i];
			if(isIn(newX, newY) && flag[newX][newY]==false && map[newX][newY]=='0') {
				Stack.push(make_pair(newX, newY));
				flag[newX][newY] = true;
			}
		}
	}
	if(result == 0)	printf("NO\n");
	else	printf("YES\n");

	return 0;
}
