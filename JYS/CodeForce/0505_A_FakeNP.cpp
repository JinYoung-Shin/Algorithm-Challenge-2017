#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int num1, num2;
	int ans = 2;
	scanf("%d%d", &num1, &num2);
	if(num1 == num2) {
		ans = num1;
	}
	printf("%d\n", ans);
	return 0;
}

/*
같은 경우에는 해당 수를 출력하고,
나머지 경우에는 2를 출력해주면 범위에 따라 최대로 등장하는 Divisor 수와 일치한다.
*/