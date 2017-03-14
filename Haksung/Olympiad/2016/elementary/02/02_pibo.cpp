#include <stdio.h>

int main() {
	int i, num;
	long long int pib[80] = {0,}, dist;

	scanf("%d", &num);

	pib[0] = 1;
	pib[1] = 1;


	for(i=2; i<num; i++)
		pib[i] = pib[i-1] + pib[i-2];
	if(num == 1)
		dist = 4;
	else
		dist = 2*(2*pib[num-1] + pib[num-2]);

	printf("%lld\n", dist);
	
	return 0;
}
