#include <iostream>
#include <cmath>
using namespace std;
 
int d[110];
int p[110];
int length[110];
int N;

int w, h;

int sum = 0;

int main(void)
{
      // 여기서부터 작성
	scanf("%d %d", &w, &h);
	scanf("%d", &N);
	
	for(int i = 0; i <= N; i++) {
		scanf("%d %d", &d[i], &p[i]);
	}
	
	for(int i = 0; i <= N; i++) {
		if(d[i] == 1) {
			length[i] = p[i];
		} else if(d[i] == 2) {
			length[i] = 2*w + h - p[i];
		} else if(d[i] == 3) {
			length[i] = 2*w + 2*h - p[i];
		} else {
			length[i] = w + p[i];
		}
		
	}
	
	for(int i = 0; i < N; i++) {
		length[i] = abs(length[N] - length[i]);
		
		if(length[i] > w + h) {
			length[i] = 2*w + 2*h - length[i];
		}

		sum += length[i];
		
	}
	
	printf("%d", sum);
      return 0;
}