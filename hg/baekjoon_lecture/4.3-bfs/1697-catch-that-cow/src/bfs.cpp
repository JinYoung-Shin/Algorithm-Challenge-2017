#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
using namespace std;

typedef struct _node {
	int cost;
	int current;
	int delta;
	bool freer;
	struct _node *parent;
} node;
set<node*> deleted;
int farmer_pos;
int cow_pos;
node root;
queue<node*> open;

void expand_child(node* ptr) {
	node* temp;
	if (ptr->delta == 0) {
		return;
	}
	
	temp = (node*)malloc(sizeof(node));
	temp->cost = ptr->cost + 1;
	temp->current = ptr->current + 1;
	temp->delta = cow_pos - temp->current;
	temp->parent = ptr;
	temp->freer = true;
	// ptr->left = temp;
	open.push(temp);
	
	temp = (node*)malloc(sizeof(node));
	temp->cost = ptr->cost + 1;
	temp->current = ptr->current - 1;
	temp->delta = cow_pos - temp->current;
	temp->parent = ptr;
	temp->freer = false;
	// ptr->middle = temp;
	open.push(temp);
	
	if (ptr->delta > 0) {
		temp = (node*)malloc(sizeof(node));
		temp->cost = ptr->cost + 1;
		temp->parent = ptr;
		temp->current = ptr->current * 2;
		temp->delta = cow_pos - temp->current;
		temp->freer = false;
		// ptr->right = temp;
		open.push(temp);
	}
};
void dump(node* ptr) {
	printf("node (%d, %d, %d)\n", ptr->cost, ptr->current, ptr->delta);
}
void bfs() {
	node *cursor;
	while(!open.empty()) {
		cursor = open.front();
		open.pop();
		dump(cursor);
		if (!cursor) {
			continue;
		}
		expand_child(cursor); //자식 노드를 만들여서 큐에 넣는다
		if (cursor->delta == 0) {
			cout << "found!" << endl;
			cout << cursor->cost << endl;
			return;
		}
	}
}
int main() {
	scanf("%d %d\n", &farmer_pos, &cow_pos);
	node temp, *cursor;
	root.cost = 0;
	root.current = farmer_pos;
	root.delta = cow_pos - root.current;
	open.push(&root);
	
	// dump(&root);
	// expand_child(&root);
	// dump(root.left);
	// dump(root.right);
	bfs();
}