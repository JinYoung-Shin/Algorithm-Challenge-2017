//3번
#include<vector>
using namespace std;

int solution(vector<vector<int> > bricks)
{
    int level[505][505] = {0}; // 물기둥
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int xx, yy;
    int timer = 0;
    while(timer < 10) {
        timer++;
        for(int i = 1; i < bricks.size()-1; i++) {
            for(int j = 1; j < bricks[0].size()-1; j++) {
                for(int k = 0; k < 4; k++) {
                    xx = i + dx[k];
                    yy = i + dy[k];
                    int tmin = 9999999;
                    if(bricks[i][j] >= bricks[xx][yy]) {
                        break;
                    }
                    if(tmin > bricks[xx][yy]){
                        tmin = bricks[xx][yy];
                    }
                    if(k == 3) {
                        if(level[i][j] == 0){
                            level[i][j] = tmin - bricks[i][j];
                            bricks[i][j] = tmin;
                        } else {
                            level[i][j] += (tmin - bricks[i][j]);
                            bricks[i][j] = tmin;
                        }
                    }
                }
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i < bricks.size()-1; i++) {
        for(int j = 1; j < bricks[0].size()-1; j++) {
            if(level[i][j] == 0) continue;
            answer += level[i][j];
        }
    }
    if(answer == 0) answer = -1;
    return answer;
}