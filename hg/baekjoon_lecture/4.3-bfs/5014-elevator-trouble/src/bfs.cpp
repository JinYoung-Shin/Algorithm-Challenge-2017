#include <iostream>
#include <cstdio>
#include <queue>
#include <stdlib.h>

using namespace std;

bool visited[1000001];
int floor, start, goal, up, down;

typedef struct _node {
	int pos, cost;
} Node;

queue<Node> open;
int main() {
	Node current;
	int pos_up, pos_down, i=0;
	scanf("%d %d %d %d %d\n", &floor, &start, &goal, &up, &down);
	
	open.push(Node { start, 0 });
	visited[start] = true;
	
	// while(!open.empty() && i < 13) {
	while(!open.empty()) {
		i++;
		current = open.front();
		open.pop();
		
		// printf("(%d / %d)\n", current.pos, current.cost);
		
		if (current.pos == goal) {
			cout << current.cost << endl;
			return EXIT_SUCCESS;
		}
		pos_up = current.pos + up;
		pos_down = current.pos - down;
		
		if (pos_up >= 1 && pos_up <= floor && visited[pos_up] == false) {
			visited[pos_up] = true;
			open.push(Node {pos_up, current.cost + 1});
		}
		
		if (pos_down >= 1 && pos_down <= floor && visited[pos_down] == false) {
			visited[pos_down] = true;
			open.push(Node {pos_down, current.cost + 1});
		}
	}
	cout << "use the stairs" << endl;
}