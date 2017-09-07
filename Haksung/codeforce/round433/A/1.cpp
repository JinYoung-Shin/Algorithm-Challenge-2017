#include <cstdio>

int main() {
	int num;
	scanf("%d", &num);

	int first, second;
	if(num % 2 == 0) {
		first = num/2 - 1;
		second = num/2 + 1;
	}
	else {
		first = num/2;
		second = num/2 +1;
	}

	int result;
	while(first != 1) {
		result = 0;
		for(int i=2; i<=first; i++) {
			if(!(first%i || second%i)) {
				first--;
				second++;
				result = 1;
				break;
			}
		}
		if(result == 0)	break;
	}
	printf("%d %d\n", first, second);

	return 0;
}
