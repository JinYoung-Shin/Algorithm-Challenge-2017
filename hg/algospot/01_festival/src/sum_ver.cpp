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
	int* arr, *summation;
	double min, current;
	
	scanf("%d", &case_num);
	
	for (i=0; i< case_num; i++) {
		scanf("%d %d", &total_num, &least_len);
		arr = (int*) calloc(sizeof(int), total_num);
		summation = (int*) calloc(sizeof(int), total_num + 1);
		summation[0] = 0;
		for (j=0; j< total_num; j++) {
			scanf("%d", &arr[j]);
			summation[j+1] = summation[j] + arr[j];
		}
		
		min = 9999999999;
		int start, end;
		for (start = 0; start <= total_num - least_len; start++) {
			for (end = start + least_len ; end <= total_num; end++) {
				current = (double)(summation[end] - summation[start]) / (end-start);
				//printf("(%d,%d)\n", start, end);
				if (min > current) {
					min = current;
				}
			}
		}
		/*
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
		*/
		printf("%.10f\n", min);
		
		free(arr);
		free(summation);
	}
}