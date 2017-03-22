#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int arr[101][101];
	int t, n, m, k;
	int a, b, price;
	int travel;
	int ticket = 0;
	int temp_i;
	int min_val = 99999;
	
	fill(arr[0], arr[101], 0);
	
	scanf("%d", &t);
	for( int i = 0; i < t; i++ ) {
		scanf("%d%d%d", &n, &m, &k); // k : Ticket Price
		for( int j = 0; j < m; j++) {
			scanf("%d%d%d", &a, &b, &price);
			arr[a-1][b-1] = price;	
			arr[b-1][a-1] = price;
		}
		scanf("%d", &travel);
		for( int k = 0; k < travel; k++) {
			scanf("%d%d", &a, &b);
			if(arr[a-1][b-1] == 0) {
				for(int i = 0; i < n; i++) {
					if(arr[a-1][i] != 0 && arr[b-1][i] != 0) {
						min_val = min(k, arr[a-1][i] + arr[b-1][i]);
					}
				}
			}
			if( k == min_val )
			ticket++;
			
			min_val = 99999;
		}
	}
	
// 	for( int i = 0 ; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 			printf("%d ", arr[i][j]);
// 		}
// 		printf("\n");
// 	}
	
	
	printf("%d", ticket);
	
	return 0;
}