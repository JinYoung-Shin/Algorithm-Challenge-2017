#include <cstdio>

int main() {
	long long int n, k;
	scanf("%I64d %I64d", &n, &k);

	long long int min, max;
	if(n == k || k == 0)	min = 0;
	else		min = 1;

	if(n >= 3*k)	max = 2*k;
	else		max = n-k;

	printf("%I64d %I64d\n", min, max);

	return 0;
}
