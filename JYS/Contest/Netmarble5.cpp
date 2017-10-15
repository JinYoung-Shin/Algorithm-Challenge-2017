#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> matrix, int r) {
    vector<vector<int>> answer;
    // r = 1, 2, 3, 4
    // r % 4 == 0, 1, 2, 3

    // 90도 회전을 회수마다 다르게 해줘라
    int size = matrix.size();
    int num = r%4;
    if(num == 1) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                answer[j][size-i] = matrix[i][j];
            }
        }   
    } else if(num == 2) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                answer[size-i][size-j] = matrix[i][j];
            }
        }
    } else if(num == 3) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                answer[size-j][i] = matrix[i][j];
            }
        }
    } else {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                answer[i][j] = matrix[i][j];
            }
        }
    }
    return answer;
}