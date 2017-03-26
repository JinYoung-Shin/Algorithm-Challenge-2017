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

int bfs() {
	Case current, temp;
	while(!open.empty()) {
		current = open.front();
		open.pop();
		// printf("(%d / %d)\n", current.cost, current.my_pos);
		
		
		if (current.my_pos == cow_pos) {
			return current.cost;
		}
		
		// if (current.cost <= limit) {
			if (current.my_pos - 1 >= 0) {
				temp.cost = current.cost + 1;
				temp.my_pos = current.my_pos - 1; // 왼쪽으로 한칸 케이스
				open.push(temp);
			}

			temp.cost = current.cost + 1;
			temp.my_pos = current.my_pos + 1; // 오른쪽으로 한칸 케이스
			open.push(temp);

			temp.cost = current.cost + 1;
			temp.my_pos = current.my_pos * 2; // 곱하기 2배 케이스
			open.push(temp);
		// }
	}
	//스택이 비어있는 경우
	return -1;
}
int main() {
	int answer = -1;
	Case first;
	
	scanf("%d %d\n", &my_pos, &cow_pos);
	
	// for (int i=0; true ; i++) {
		first.cost = 0;
		first.my_pos = my_pos;
		open.push(first);
		answer = bfs();
		
		// cout << "limit : " << i << " 케이스" << endl;
		if (answer == -1) {
			// cout << "탐색 실패 ㅠㅠ" << endl;
		} else {
			// cout << "탐색 성공!. cost는 " << answer << endl;
			cout << answer << endl;
			return EXIT_SUCCESS;
		}
	// }
	
}