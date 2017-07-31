#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<int>> board, vector<int> nums) {
    int answer = 0;
    set<int> numbers;
    int N = board.size();
    int i, j, k;
    bool garo, sero;
    bool diagon1;
    bool diagon2;
    for (i=0; i < nums.size(); i++) {
        numbers.insert(nums[i]);
    }
    
        for (j=0; j < N; j++) {
            for (k=0; k < N; k++) {
                if (numbers.find(board[j][k]) != numbers.end()) {
                    board[j][k] = -1;
                }
            }
        }

    
    
    for (i=0; i < N; i++) {
        garo = true;
        sero = true;
        for (j=0; j < N; j++) {
            if (board[i][j] != -1) {
                garo = false;
            }
            if (board[j][i] != -1) {
                sero = false;
            }
        }
        if (garo) {
            answer++;
        }
        if (sero) {
            answer++;
        }
    }
    
    diagon1 = true;
    diagon2 = true;
    for (i=0; i < N; i++) {
        if (board[i][i] != -1) {
            diagon1 = false;
        }
        if (board[N-1-i][i] != -1) {
            diagon2 = false;
        }
    }
    if (diagon1) {
        answer++;
    }
    if (diagon2) {
        answer++;
    }
    
    return answer;
}