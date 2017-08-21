#include <iostream>
#include <vector>

using namespace std;
vector<int> solution(int m, int n, vector<vector<int>>& picture);
int main() {
	int m = 6;
	int n = 4;
	
	vector<vector<int> > picture;
	picture.reserve(6);
	for (int i=0; i <6; i++) {
		picture[i].reserve(4);
	}
	
	picture[0][0] = 1;
	picture[0][1] = 1;
	picture[0][2] = 1;
	picture[0][3] = 0;
	
	picture[1][0] = 1;
	picture[1][1] = 1;
	picture[1][2] = 1;
	picture[1][3] = 0;
	
	picture[2][0] = 0;
	picture[2][1] = 0;
	picture[2][2] = 0;
	picture[2][3] = 1;
	
	picture[3][0] = 0;
	picture[3][1] = 0;
	picture[3][2] = 0;
	picture[3][3] = 1;
	
	picture[4][0] = 0;
	picture[4][1] = 0;
	picture[4][2] = 0;
	picture[4][3] = 1;
	
	picture[5][0] = 0;
	picture[5][1] = 0;
	picture[5][2] = 0;
	picture[5][3] = 1;
	// for (int i=0; i < m; i++) {
	// 	for (int j=0; j < n; j++) {
	// 		printf("%d ", picture[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	vector<int> answer = solution(m, n, picture);
	cout << answer[0] << endl << answer[1] << endl;
		
}