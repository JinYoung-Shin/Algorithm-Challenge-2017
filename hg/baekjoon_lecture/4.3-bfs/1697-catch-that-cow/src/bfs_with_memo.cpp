#include <iostream>
#include <cstdio>
#include <queue>
#include <stdlib.h>

using namespace std;

int my_pos, cow_pos;

typedef struct _Case {
	int cost;
	int my_pos;
} Case;

queue<Case> open;
bool visited[200001];
int bfs() {
	Case current, temp;
	while(!open.empty()) {
		current = open.front();
		open.pop();
		
		// printf("(%d, %d)\n", current.cost, current.my_pos);
		if (current.my_pos == cow_pos) {
			return current.cost;
		}
		
			
		if (current.my_pos - 1 >= 0 && visited[current.my_pos - 1] == false) {
			visited[current.my_pos - 1] = true;
			temp.cost = current.cost + 1;
			temp.my_pos = current.my_pos - 1; // 왼쪽으로 한칸 케이스
			open.push(temp);
		}

		if (current.my_pos + 1 <= 200000 && visited[current.my_pos + 1] == false) {
			visited[current.my_pos + 1] = true;
			temp.cost = current.cost + 1;
			temp.my_pos = current.my_pos + 1; // 오른쪽으로 한칸 케이스
			open.push(temp);
		}

		if (current.my_pos * 2 <= 200000 && visited[current.my_pos * 2] == false) {
			visited[current.my_pos * 2] = true;
			temp.cost = current.cost + 1;
			temp.my_pos = current.my_pos * 2; // 곱하기 2배 케이스
			open.push(temp);
		}
	}
	//큐가 비어있는 경우
	return -1;
}
int main() {
	int answer = -1;
	Case first;
	
	scanf("%d %d\n", &my_pos, &cow_pos);
	
	first.cost = 0;
	first.my_pos = my_pos;
	open.push(first);
	visited[my_pos] = true;
	answer = bfs();

	cout << answer << endl;
	
}