#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int cur, clip;
} status;

int stat[1501][1501];
int S;
queue<status> open;
int main() {
	status current;
	
	for (int i=0;i<1501;i++) {
		for(int j=0;j<1501;j++) {
			stat[i][j] = -1;
		}
	}
	stat[1][0] = 0;
	
	open.push( status { 1, 0 });
	scanf("%d\n", &S);
	
	while(!open.empty()) {
		current = open.front();
		open.pop();
		if (current.cur == S) {
			//정답 케이스
			cout << stat[current.cur][current.clip] << endl;
			break;
		}
		
		//1. 클립보드에 복사
		if (current.cur != current.clip && stat[current.cur][current.cur] == -1) {
			stat[current.cur][current.cur] = stat[current.cur][current.clip] + 1;
			open.push( status { current.cur, current.cur });
		}
		
		//2. 붙여넣기
		if (current.cur + current.clip < 1500 && stat[current.cur + current.clip][current.clip] == -1) {
			stat[current.cur + current.clip][current.clip] = stat[current.cur][current.clip] + 1;
			open.push( status { current.cur + current.clip, current.clip });
		}
		
		//3. 하나 삭제
		if (current.cur - 1 > 0 && stat[current.cur - 1][current.clip] == -1) {
			stat[current.cur - 1][current.clip] = stat[current.cur][current.clip] + 1;
			open.push( status { current.cur - 1, current.clip });
		}
	}
}