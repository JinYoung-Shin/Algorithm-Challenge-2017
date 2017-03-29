#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	
	int T, N, S;
	int l = 0;
	int arr[100001] = {0};
	int sum[100001] = {0};
	
	scanf("%d", &T);

	for( int i = 0; i < T; i++ ) {
		scanf("%d %d", &N, &S);
		for( int j = 0; j < N; j++ ) {
			std::cout << "what the" << endl;
			std::cin >> arr[j];
			std::cout << "FFF..." << endl;
		}
		
		printf("#testcase%d\n", i+1);
		
		// Compare if S <
		while(1) {
			for( int k = 0; k < N; k ++ ) {
				sum[k] += arr[k+l];
				if(sum[k] > S) {
					printf("%d", k+1);
					break;
				}
			}
			l++;
		}
	}
	
	return 0;
}