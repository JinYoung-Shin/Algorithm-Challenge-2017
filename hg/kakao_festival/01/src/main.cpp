#include <iostream>
#include <vector>

using namespace std;
vector<int> solution(int m, int n, vector<vector<int>> picture);
int main() {
	int m = 6;
	int n = 4;
	
	vector<vector<int> > picture({
		vector<int>( { 1, 1, 1, 0 }),
		vector<int>( { 1, 1, 1, 0 }),
		vector<int>( { 0, 0, 0, 1 }),
		vector<int>( { 0, 0, 0, 1 }),
		vector<int>( { 0, 0, 0, 1 }),
		vector<int>( { 0, 0, 0, 1 })	
	});
		
	vector<int> answer = solution(m, n, picture);
	cout << answer[0] << endl << answer[1] << endl;
		
}