#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int, int> Data;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    queue<Data> q;
    Data d;
    int check = 1;
    
    // find
    for(int i=0; i<m-1; i++) {
        for(int j=0; j<n-1; j++) {
            char c = board[i][j];
            if(c != board[i][j+1])  continue;
            if(c != board[i+1][j])  continue;
            if(c != board[i+1][j+1])  continue;
            d.first = i;    d.second = j;
            q.push(d);
        }
    }
    
    while(check) {
        check = 0;
        // delete
        while(!q.empty()) {
            d = q.front();
            int x = d.first;
            int y = d.second;
            for(int i=0; i<2; i++) {
                for(int j=0; j<2; j++) {
                    if(board[x+i][y+j] != ' ') {
                        board[x+i][y+j] = ' ';
                        answer++;
                    }
                }
            }
            q.pop();
        }
        // down
        int count;
        for(int j=0; j<n; j++) {
            for(int i=m-1; i>=0; i--) {
                if(board[i][j] == ' ') {
                    count = 1;
                    while(i-count >= 0 && board[i-count][j] == ' ')    count++;
                    if(i-count >= 0) {
                        board[i][j] = board[i-count][j];
                        board[i-count][j] = ' ';
                    }
                }
            }
        }
        // find
        for(int i=0; i<m-1; i++) {
            for(int j=0; j<n-1; j++) {
                char c = board[i][j];
                if(c == ' ')    continue;
                if(c != board[i][j+1])  continue;
                if(c != board[i+1][j])  continue;
                if(c != board[i+1][j+1])  continue;
                d.first = i;    d.second = j;
                q.push(d);
                check = 1;
            }
        }
    }
    
    return answer;
}