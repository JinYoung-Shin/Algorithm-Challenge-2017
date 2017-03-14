#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
typedef struct {
	int x,y;
} Pos;

enum Color { white, black, sliced };

typedef struct _Paper{
	Pos left_below, right_above;
	Color color;
	struct _Paper *child1, *child2;
	int size;
} Paper;
int width, height;
int num_of_dot;
vector<Pos> dot_list;
int max_val, min_val;
Paper adam;

void split_paper(int, int);
bool is_in_scope(int, int, Paper*);
void dump_dot_list();
void dfs(Paper*);
int main() {
	
	Pos temp_pos;
	scanf("%d %d\n", &width, &height);
	max_val = -1;
	min_val = 987654321;
	// initialization of adam paper
	adam.left_below.x = 0;
	adam.left_below.y = 0;
	adam.right_above.x = width;
	adam.right_above.y = height;
	adam.color = white;
	adam.size = width * height;
	adam.child1 = '\0';
	adam.child2 = '\0';
	
	scanf("%d\n", &num_of_dot);
	dot_list.reserve(num_of_dot);
	for (int i=0; i<num_of_dot; i++) {
		scanf("%d %d\n", &temp_pos.x, &temp_pos.y);
		dot_list.push_back(temp_pos);
	}
	// dump_dot_list();
	
	for(int i=0; i<num_of_dot; i++) {
	// for(int i=0; i<4; i++) {
		split_paper(dot_list[i].x, dot_list[i].y);
	}
	// cout << "================================" << endl;
	dfs(&adam);
	// cout << "================================" << endl;
	
	cout << max_val << endl << min_val << endl;
}
void dfs(Paper *cursor) {
	if (cursor) {
		dfs(cursor->child1);
		dfs(cursor->child2);
		if (cursor->color != sliced) {
			if (cursor->size < min_val) {
				min_val = cursor->size;
			}
			if (cursor->size > max_val) {
				max_val = cursor->size;
			}
			// printf("(%d, %d) ~ (%d, %d) %s\n", cursor->left_below.x, cursor->left_below.y, cursor->right_above.x, cursor->right_above.y, cursor->color == black ? "black" : "white");
		}
	}
	
}

bool is_in_scope(int xpos, int ypos, Paper* paper) {
	if (xpos > paper->left_below.x && ypos > paper->left_below.y) {
		if (xpos < paper->right_above.x && ypos < paper->right_above.y) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
void split_paper(int xpos, int ypos) {
	Paper *target_paper = &adam;
	Paper *c1, *c2;
	
	//finding child paper process
	while (target_paper && target_paper->color == sliced) {
		if (is_in_scope(xpos, ypos, target_paper->child1)) {
			target_paper = target_paper->child1;
		} else if (is_in_scope(xpos, ypos, target_paper->child2)) {
			target_paper = target_paper->child2;
		} else {
			cout << "split paper error case!!!" << endl;
			return;
		}
	}
	
	//splitting paper process
	if (target_paper->color == white) {
		target_paper->child1 = (Paper*)calloc(1, sizeof(Paper));
		target_paper->child2 = (Paper*)calloc(1, sizeof(Paper));
		c1 = target_paper->child1; //가로로 자른 경우 요놈이 아래놈
		c2 = target_paper->child2; //요놈이 위에놈
		
		c1->left_below.x = target_paper->left_below.x;
		c1->left_below.y = target_paper->left_below.y;
		c1->right_above.x = target_paper->right_above.x;
		c1->right_above.y = ypos;
		c1->color = black;
		c1->size = (c1->right_above.x - c1->left_below.x) * (c1->right_above.y - c1->left_below.y);
		
		c2->left_below.x = target_paper->left_below.x;
		c2->left_below.y = ypos;
		c2->right_above.x = target_paper->right_above.x;
		c2->right_above.y = target_paper->right_above.y;
		c2->color = black;
		c2->size = (c2->right_above.x - c2->left_below.x) * (c2->right_above.y - c2->left_below.y);
		
		target_paper->color = sliced;
	} else if (target_paper->color == black) {
		target_paper->child1 = (Paper*)calloc(1, sizeof(Paper));
		target_paper->child2 = (Paper*)calloc(1, sizeof(Paper));
		c1 = target_paper->child1; //세로로 자른 경우 요놈이 왼쪽놈
		c2 = target_paper->child2; //요놈이 오른쪽놈
		
		c1->left_below.x = target_paper->left_below.x;
		c1->left_below.y = target_paper->left_below.y;
		c1->right_above.x = xpos;
		c1->right_above.y = target_paper->right_above.y;
		c1->color = white;
		c1->size = (c1->right_above.x - c1->left_below.x) * (c1->right_above.y - c1->left_below.y);
		
		c2->left_below.x = xpos;
		c2->left_below.y = target_paper->left_below.y;
		c2->right_above.x = target_paper->right_above.x;
		c2->right_above.y = target_paper->right_above.y;
		c2->color = white;
		c2->size = (c2->right_above.x - c2->left_below.x) * (c2->right_above.y - c2->left_below.y);
		
		target_paper->color = sliced;
	} else {
		cout << "split paper color error case!!:" << endl;
		return;
	}
	
	return;
}

void dump_dot_list() {
	for (int i=0; i<dot_list.size(); i++) {
		printf("(%d, %d)\n", dot_list[i].x, dot_list[i].y);
	}
}