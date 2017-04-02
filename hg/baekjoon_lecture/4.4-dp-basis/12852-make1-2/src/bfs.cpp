#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int num;
queue<int> open;
stack<int> trace;

int cost[1000001][2];
int main() {
	int cur, data;
	for (int i=0;i<1000001;i++) {
		cost[i][0] = -1;
		cost[i][1] = -1;
	}
	scanf("%d\n", &num);
	open.push(num);
	cost[num][0] = 0;
	
	while(!open.empty()) {
		cur = open.front();
		open.pop();
		
		if (cur == 1) {
			//정답 출력
			cout << cost[1][0] << endl;
			int pos = 1;
			while (pos != -1) {
				trace.push(pos);
				// cout << pos;
				pos = cost[pos][1];
				// cout << " ";
			}
			while (!trace.empty()) {
				data = trace.top();
				trace.pop();
				cout << data;
				if (trace.size() > 0) {
					cout << " ";
				}
			}
			cout << endl;
			break;
		}
		
		if (cur % 3 == 0 && cost[cur/3][0] == -1) {
			cost[cur/3][0] = cost[cur][0] + 1;
			cost[cur/3][1] = cur;
			open.push(cur/3);
		}
		
		if (cur % 2 == 0 && cost[cur/2][0] == -1) {
			cost[cur/2][0] = cost[cur][0] + 1;
			cost[cur/2][1] = cur;
			open.push(cur/2);
		}
		
		if (cur - 1 > 0 && cost[cur -1][0] == -1) {
			cost[cur-1][0] = cost[cur][0] + 1;
			cost[cur-1][1] = cur;
			open.push(cur-1);
		}
	}
	
}