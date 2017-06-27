#include <iostream>

using namespace std;

int map[51][51];

int N;

bool is_good(int x, int y) {
	for (int s=0; s < N; s++) {
		for (int t=0; t < N; t++) {
			if (map[x][y] == map[x][s] + map[t][y]) {
				return true;
			}
		}
	}
	return false;
	
}
int main() {
	
	cin >> N;
	
	for (int i=0; i < N; i++) {
		for (int j=0; j < N ;j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			if (map[i][j] != 1 && is_good(i, j) == false) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}