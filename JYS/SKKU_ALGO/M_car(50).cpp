#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, W;


struct Car {
	int x;
	int y;
};

int main() {
	scanf("%d", &N);
	scanf("%d", &W);
	int dist = 0;
	int x, y;
	Car c1, c2;
	c1.x = 1;
	c1.y = 1;
	c2.x = N;
	c2.y = N;
	int sum1;
	int sum2;
	for( int i = 0; i < W; i++ ) {
		scanf("%d %d", &x, &y);
		sum1 = abs(x - c1.x) + abs(y - c1.y);
		sum2 = abs(c2.x - x) + abs(c2.y - y);
		if(sum1 >= sum2) {
			c2.x = x;
			c2.y = y;
			dist += sum2;
		}
		else {
			c1.x = x;
			c1.y = y;
			dist += sum1;
		}
	}
	printf("%d\n", dist);
	
	return 0;
}