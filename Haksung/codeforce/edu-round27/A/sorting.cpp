#include <cstdio>

int main() {
	int num;
	scanf("%d", &num);
	int size = 2*num;

	int arr[size];
	// scan
	for(int i=0; i<size; i++) 
		scanf("%d", &arr[i]);

	// insert sort
	for(int i=0; i<size; i++) {
		int temp = arr[i];
		for(int j=i; j>0; j--) {
			if(arr[j-1] > temp) {
				arr[j] = arr[j-1];
				if(j == 1) {
					arr[0] = temp;
					break;
				}
			}
			else {
				arr[j] = temp;
				break;
			}
		}
	}

	// print YES or NO
	if(arr[num-1] == arr[num])
		printf("NO\n");
	else	
		printf("YES\n");
	return 0;
}
