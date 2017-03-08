#include <stdio.h>
#include <stdlib.h>

void dump_arr(int* arr, int len) {
	for (int i=0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int case_num, total_num, least_len, i, j, k, start, len, sum;
	int* arr;
	double min, current;
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &case_num);
	
	for (i=0; i< case_num; i++) {
		scanf("%d %d", &total_num, &least_len);
		arr = (int*) calloc(sizeof(int), total_num);
		for (j=0; j< total_num; j++) {
			scanf("%d", &arr[j]);
		}
		
		min = 9999999999;
		for (len = least_len; len <= total_num; len++) {
			for (start = 0; start <= total_num - len; start++) {
				sum = 0;
				for (k=0; k<len; k++) {
					sum += arr[start + k];
				}
				current = (double)sum / len;
				if (min > current) {
					min = current;
				}
				
			}
		}
		printf("%.10f\n", min);
		
		free(arr);
	}
}