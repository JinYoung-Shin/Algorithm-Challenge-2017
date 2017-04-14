#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, l, M;
int Max = 0;
//int arr[10010][10010] = {0};
int x[110],y[110];
int cnt;
int num = 0;
int h,w;

int main() {
	scanf("%d %d %d", &N, &l, &M);
	
	for(int i = 1; i <= M; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	
	l /= 2;
	for(int h = 1; h < l; h++) {
		w = l - h;
		for(int i = 1; i <= M; i++) {
			cnt = 0;
			for(int k = 1; k <= M; k++) {
				if((x[k] >= x[i] && x[k] <= x[i] + h) && (y[k] >= y[i] && y[k] <= y[i] + w)) {
					cnt++;
				}
			}
			if(cnt > Max) {
				Max = cnt;
			}
		}
		
	}
	
	printf("%d", Max);
	return 0;
}