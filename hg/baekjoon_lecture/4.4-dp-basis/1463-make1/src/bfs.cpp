#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int num;
queue<int> open;

int cost[1000001];
int main() {
	int cur;
	for (int i=0;i<1000001;i++) {
		cost[i] = -1;
	}
	scanf("%d\n", &num);
	open.push(num);
	cost[num] = 0;
	
	while(!open.empty()) {
		cur = open.front();
		open.pop();
		
		if (cur == 1) {
			//정답 출력
			cout << cost[1] << endl;
			break;
		}
		
		if (cur % 3 == 0 && cost[cur/3] == -1) {
			cost[cur/3] = cost[cur] + 1;
			open.push(cur/3);
		}
		
		if (cur % 2 == 0 && cost[cur/2] == -1) {
			cost[cur/2] = cost[cur] + 1;
			open.push(cur/2);
		}
		
		if (cur - 1 > 0 && cost[cur -1] == -1) {
			cost[cur-1] = cost[cur] + 1;
			open.push(cur-1);
		}
	}
	
}