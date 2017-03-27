#include <iostream>
#include <cstdio>
#include <queue>
#include <stdlib.h>
#include <stack>

using namespace std;

int my_pos, cow_pos;

typedef struct _Case {
	int cost;
	int my_pos;
	_Case *parent;
} Case;

queue<Case*> open;
stack<int> trace;
bool visited[200001];
Case* bfs() {
	Case *current, *temp;
	while(!open.empty()) {
		current = open.front();
		open.pop();
		
		// printf("(%d, %d)\n", current.cost, current.my_pos);
		if (current->my_pos == cow_pos) {
			return current;
		}
		
			
		if (current->my_pos - 1 >= 0 && visited[current->my_pos - 1] == false) {
			visited[current->my_pos - 1] = true;
			temp = (Case*) malloc(sizeof(Case));
			temp->cost = current->cost + 1;
			temp->my_pos = current->my_pos - 1; // 왼쪽으로 한칸 케이스
			temp->parent = current;
			open.push(temp);
		}

		if (current->my_pos + 1 <= 200000 && visited[current->my_pos + 1] == false) {
			visited[current->my_pos + 1] = true;
			temp = (Case*) malloc(sizeof(Case));
			temp->cost = current->cost + 1;
			temp->my_pos = current->my_pos + 1; // 오른쪽으로 한칸 케이스
			temp->parent = current;
			open.push(temp);
		}

		if (current->my_pos * 2 <= 200000 && visited[current->my_pos * 2] == false) {
			visited[current->my_pos * 2] = true;
			temp = (Case*) malloc(sizeof(Case));
			temp->cost = current->cost + 1;
			temp->my_pos = current->my_pos * 2; // 곱하기 2배 케이스
			temp->parent = current;
			open.push(temp);
		}
	}
	//큐가 비어있는 경우
	return NULL;
}
int main() {
	Case *answer;
	Case *first;
	
	scanf("%d %d\n", &my_pos, &cow_pos);
	
	first = (Case*) malloc(sizeof(Case));
	first->cost = 0;
	first->my_pos = my_pos;
	first->parent = NULL;
	open.push(first);
	visited[my_pos] = true;
	answer = bfs();

	if (answer) {
		cout << answer->cost << endl;
		while (answer->parent) {
			trace.push(answer->my_pos);
			answer = answer->parent;
		}
		
		trace.push(my_pos);
		
		while (!trace.empty()) {
			cout << trace.top();
			trace.pop();
			if (trace.size() > 0) {
				cout << " ";
			} else {
				cout << endl;
			}
		}
		
	} else {
		cout << "No Answer" << endl;
	}
	
}