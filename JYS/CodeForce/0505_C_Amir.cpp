#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int num;
	int ans;
	scanf("%d", &num);
	if(num == 0 || num == 1) {
		ans = 0;
	} else {
		if(num % 2 == 1) {
			ans = num/2;
		}
		else {
			ans = num/2 - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

/*
(i+j) % n+1 times n-1.
(n*n + n)/2 = sum

Answer becomes 
0 ~ 2 -> 0
3 ~ 4 -> 1
5 ~ 6-> 2
7 ~ 8 -> 3
9 ~ 10 -> 4
...
*/