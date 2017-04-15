#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio> 

using namespace std;

int N,M;
int Max = 0;
char arr[55][55];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int xx, yy;

struct Queue {
	int x, y, temp;
};

Queue que[100*100+100];

int bfs(int _x, int _y) {
	int fp = 0; int sp =0;
	int count = 0;
	int visited[55][55] = {0};
	Queue q;
	q.x = _x;
	q.y = _y;
	q.temp = 0;
	que[sp++] = q;
	visited[_x][_y] = 1;
	
	
	while(fp < sp) {
		q = que[fp++];
		_x = q.x;
		_y = q.y;
		q.temp++;
		for(int i = 0; i < 4; i++) {
			q.x = _x + dx[i];
			q.y = _y + dy[i];
			if(arr[q.x][q.y] == 'L' && visited[q.x][q.y] == 0) {
				visited[q.x][q.y] = 1;
				que[sp++] = q;
				count = q.temp;
			}
		}
	}
	return count;
}

int main() {
	int temp;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%c", &arr[i][j]);
		}
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(arr[i][j] == 'L') {
				temp = bfs(i, j);
				if(temp > Max) {
					Max = temp;
				}
			}
		}
	}
	
	printf("%d", Max);
		
    return 0;
}