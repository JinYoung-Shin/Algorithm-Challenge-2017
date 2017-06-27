// #include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <functional>

#define STACK_SIZE 300005
using namespace std;

int stack[STACK_SIZE];
int top;
int goal;//도달해야하는 수
int reorder;//재배치한 수
int in_trash;//쓰래기통에 있는 개수

void dump_stack() {
	cout << "--------------dump!!--------------" << endl;
	for (int i=0; i < top; i++) {
		cout << "[" << i << "] = " << stack[i] << endl;
	}
}
int main() {
	cin >> goal;
	string cmd;
	int val;
	while (goal != in_trash) {
		cin >> cmd;
		if (cmd.compare("add") == 0) {
			cin >> val;
			stack[top] = val;
			top++;
		} else {
			//쓰래기통 버리기
			if (stack[top-1] != (in_trash + 1)) {
				// dump_stack();
				reorder++;
				sort(stack, stack+top, greater<int>());
				// dump_stack();
			}
			in_trash++;
			top--;
		}
	}
	cout << reorder << endl;
}