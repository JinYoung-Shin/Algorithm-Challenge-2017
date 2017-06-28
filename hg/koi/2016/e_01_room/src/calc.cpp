#include <iostream>

#define GIRL 0
#define BOY 1
using namespace std;

int people[2][7];
int main() {
	int N, K;
	int ans = 0;
	int bias;
	cin >> N >> K;
	
	bias = K - 1;
	
	for (int i=0; i < N; i++) {
		int S, Y;
		cin >> S >> Y;
		people[S][Y]++;
	}
	for (int s = 0; s < 2; s++) {
		for (int y = 1; y < 7; y++) {
			if (people[s][y]) {
				ans += (people[s][y] + bias) / K;
			}
		}
	}
	cout << ans << endl;
	
}