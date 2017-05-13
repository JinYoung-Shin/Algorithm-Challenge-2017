#include <cstdio>
#include <iostream>

using namespace std;

int N;
int arr[10010];
int temp1, temp2;
int _max = -1;
int temp;

bool next_permutation(int *a, int n) {
	int i = n-1;
	while(i > 0 && a[i-1] > a[i]) i -= 1;
	if(i <= 0) return false;
	int j = n-1;
	while(a[j] <= a[i-1]) j -= 1;
	swap(a[i-1], a[j]);
	j = n-1;
	while(i < j) {
		swap(a[i], a[j]);
		i++; j--;
	}
	return true;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	if(next_permutation(arr, N)) {
		for(int i = 0; i < N; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else {
		printf("-1\n");
	}
	
	//1. a[i-1] < a[i] 가장 큰 i(temp1)
	//2. j>=i a[j] > a[i-1] 가장 큰 j(temp2)
	//3. swap a[i-1], a[j]
	//4. Reverse from a[i] ~
//	
//	for(int i = 1; i < N; i++) {
//		if(arr[i] > arr[i-1]) {
//			if(arr[i] > _max) {
//				_max = arr[i];
//				temp1 = i;
//			}
//		}
//	}
//	_max = -1;
//	for(int i = temp1; i < N; i++) {
//		if(arr[temp-1] < arr[i]) {
//			if(arr[i] > _max) {
//				_max = arr[i];
//				temp2 = i;
//			}
//		}
//	}
//	
//	temp = arr[temp1-1];
//	arr[temp1-1] = arr[temp2];
//	arr[temp2] = temp;
//	
//	int i = temp1;
//	int j = N-1;
//	while(i<j) {
//		temp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = temp;
//		i++;
//		j--;
//	}
	
//	for(int i = 0; i < N; i++) {
//		printf("%d ", arr[i]);
//	}
			
	return 0;
}