#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > seat)
{
    int answer = 0;
    int ssize = seat.size();
    int x,y;
    // vector<vector<bool>> arr;
    // arr.resize(ssize);
    // arr.
    bool arr[1001][1001] = {false};
    
    for(int i = 0; i < ssize; i++) {
        x = seat[i][0];
        y = seat[i][1];
        
        if(arr[x][y] == true){
            continue;
        }
    
        answer++;
        arr[x][y] = true;
    }
    
    return answer;
}