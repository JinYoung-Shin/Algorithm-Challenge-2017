#include <iostream>
#include <cstdlib>

using namespace std;

char score[100001][4];

void yes() {
	cout << "YES" << endl;
	exit(EXIT_SUCCESS);
}
int n, k;
bool ok(int i) {
	bool ret = true;
	for (int a =0; a < k; a++) {
		ret &= (score[i][a] >= 1);
	}
	return ret;
}
bool ok2(int i, int j) {
	bool ret = true;
	for (int a =0; a < k; a++) {
		ret &= (score[i][a] + score[j][a] >= 0);
	}
	return ret;
}
int main() {
	
	cin >> n >> k;
	for (int i=0;i < n; i++) {
		for (int j=0;j < k;j++) {
			int tmp;
			cin >> tmp;
			score[i][j] = (tmp == 0 ? +1 : -1) ;
		}
	}
	
	for (int i=0;i < n; i++) {
		for (int j=i+1;j < n; j++) {
			if (ok(i)) {
				yes();	
			}
			if (ok2(i, j)) {
				yes();
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}