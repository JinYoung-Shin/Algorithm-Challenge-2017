#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int arr[20];
	int count = 0;
	int a,b;
	int temp;
	for( int i = 0; i < 20; i++ ) {
		arr[i] = i+1;
	} // Set array
	
	for( int i = 0; i < 10; i++ ) {
		cin >> a >> b;
		for( int j = a-1, count = 0; j<(a+b)/2; j++) {
			// cout << j << " " ;
			// cout << b-1-count << endl;
			temp = arr[j];
			arr[j] = arr[b-1-(count)];
			arr[b-1-(count++)] = temp;
		}
	}

	for( int i = 0; i < 20; i++ ) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}