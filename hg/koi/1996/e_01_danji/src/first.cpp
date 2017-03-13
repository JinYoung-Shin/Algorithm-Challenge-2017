#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<char> > matrix;
int N; //length of matrix edge
int num_of_danji;
int num_of_1;
int x,y;
vector<int> num_of_houses;
void dump_matrix();
bool find_danji();
bool spread(int xpos, int ypos);
bool comp(int a, int b) {
    return (a > b);
};
int main() {
	char temp;
	scanf("%d\n", &N);
	
	matrix.assign(N, vector<char>(N, '0'));
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%c", &temp);
			if (temp == '1') {
				num_of_1++;
			}
			matrix[i][j] = temp;
		}
		scanf("\n");
	}

	while (num_of_1 > 0) {
		// dump_matrix();
		find_danji();
		int temp = num_of_1;
		// cout << "x:" << x << endl << "y:" << y << endl;
		spread(x, y);
		num_of_danji++;
		num_of_houses.push_back(temp - num_of_1);
		// dump_matrix();
	}
	
	cout << num_of_danji << endl;
	sort(num_of_houses.begin(), num_of_houses.end());
	for (int i=0; i< num_of_houses.size(); i++) {
		cout << num_of_houses[i] << endl;;
	}
	
}

bool find_danji() {
	for (int i=0; i<N; i++) {
		for (int j=0;j<N; j++) {
			if (matrix[i][j] == '1') {
				x = i;
				y = j;
				return true;
			}
		}
	}
	x = -1;
	y = -1;
	return false;
}
bool spread(int xpos, int ypos) {
	// cout << "spread(" << xpos << "," << ypos << ")" << endl;
	if (xpos >= 0 && xpos < N && ypos >= 0 && ypos < N) {
		// cout << "flag 1"<< endl;
		if (matrix[xpos][ypos] == '1') {
			// cout << "flag 2"<< endl;
			matrix[xpos][ypos] = '0';
			num_of_1--;
			
			return spread(xpos-1, ypos) || spread(xpos, ypos-1) || spread(xpos+1, ypos) || spread(xpos, ypos+1);
		} else {
			return false;
		}
	} else {
		return false;
	}
}
void dump_matrix() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%c", matrix[i][j]);
		}
		putchar('\n');
	}
}

