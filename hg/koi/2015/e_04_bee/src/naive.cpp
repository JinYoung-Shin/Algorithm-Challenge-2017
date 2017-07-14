#include <iostream>
#include <vector>

using namespace std;

vector<int> border;

int main() {
	int M, N;
	cin >> M >> N;
	int len = M*2 - 1;
	border.resize(len, 1);
	while(N--) {
		int zero, one, two;
		cin >> zero >> one >> two;
		for (int i=zero; i < zero + one; i++) {
			border[i]++;
		}
		for (int i = zero+one; i < len; i++) {
			border[i] += 2;
		}
	}
	
	for (int i=0; i < M; i++) {
		for (int j=0; j < M; j++) {
			if (j==0) {
				cout << border[M-i-1] << ' ';
			} else {
				cout << border[M+j-1] << ' ';
			}
		}
		cout << endl;
	}
}