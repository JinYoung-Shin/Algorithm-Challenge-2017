#include <cstdio>

int num[6];

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int main() {
	for(int i=0; i<6; i++)
		scanf("%1d", &num[i]);

	int first = num[0] + num[1] + num[2];
	int second = num[3] + num[4] + num[5];
	if(first > second) {
		swap(&num[0], &num[3]);
		swap(&num[1], &num[4]);
		swap(&num[2], &num[5]);
		swap(&first, &second);
	}
	num[0] = 9 - num[0];
	num[1] = 9 - num[1];
	num[2] = 9 - num[2];

	for(int i=0; i<6; i++) {
		int temp = num[i];
                for(int j=i; j>0; j--) {
                        if(num[j-1] < temp) {
                                num[j] = num[j-1];
                                if(j == 1) {
                                        num[0] = temp;
                                        break;
                                }
                        }
                        else {
                                num[j] = temp;
                                break;
                        }
                }

	}

	int diff = second - first;
	int count = 0;
	while(diff) {
                if(diff > num[count]) {
                        diff -= num[count];
                        count++;
                }
                else {
                        count++; break;
                }
	}
	printf("%d\n", count);

	return 0;
}
