#include <iostream>
#include <cstdio>
using namespace std;
bool arr[20][20];
int N;
int ans = 0;
bool check(int row, int col) {
	// | 확인
	for(int i = 0; i < N; i++) {
		if(i == row) continue;
		if(arr[i][col]) {
			return false;
		}
	}
	// \ 확인
	int x = row - 1;
	int y = col - 1;
	while(x >= 0 && y >= 0) {
		if(arr[x][y]) return false;
		x--;
		y--;
	}
	// / 확인
	x = row - 1;
	y = col + 1;
	while(x >= 0 && y < N) {
		if(arr[x][y]) return false;
		x--;
		y++;
	}
	
	return true;
}

void place(int row) {
	// 0 ~ N-1 row까지 다 채운 경우 
	if(row == N) {
		ans += 1;
	}
	for(int i = 0; i < N; i++) {
		arr[row][i] = true;
		if(check(row, i)) {
			place(row+1);
		}
		arr[row][i] = false;
	}
}

int main() {
	scanf("%d", &N);
	place(0); // 0 row 부터 배치 
	printf("%d\n", ans);
	return 0;
}