#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

#define is_in(x, y, max_x, max_y) ((x)>=0 && (y)>=0 && (x)<(max_x) && (y)<(max_y))
const int dx[] = {-1, +0, +0, +1};
const int dy[] = {+0, -1, +1, +0};
pair<int, int> find_one(int m, int n, vector<vector<int>>& picture) {
    pair<int, int> pos;
    pos.first = -1;
    pos.second = -1;
	// printf("flag 1-2\n");
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
			// printf("(%d, %d)\n", i, j);
            if (picture[i][j] != 0) {
                pos.first = i;
                pos.second = j;
                return pos;
            }
        }
    }
	return pos;
}
int get_size(int src_x, int src_y, int max_x, int max_y, vector<vector<int>>& picture) {
    int color = picture[src_x][src_y];
    int size = 0;
	if (picture[src_x][src_y] != 0) {
    	picture[src_x][src_y] = 0;
		size++;
	} else {
		return 0;
	}
    queue< pair<int, int> > Q;
    pair<int, int> pos;
    pos.first = src_x;
    pos.second = src_y;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        int cx = pos.first;
        int cy = pos.second;
		if (picture[cx][cy] == color) {
			picture[cx][cy] = 0;
			size++;
		}
        for (int dir=0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (is_in(nx, ny, max_x, max_y) && picture[nx][ny] == color) {
				picture[nx][ny] = 0;
				size++;
                pos.first = nx;
                pos.second = ny;
                Q.push(pos);
            }
        }
    }
    return size;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>>& picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
	
	///////
	// for (int i=0; i < m; i++) {
	// 	for (int j=0; j < n; j++) {
	// 		printf("%d ", picture[i][j]);
	// 	}
	// 	printf("\n");
	// }
    //////
    pair<int, int> pos;
    while(true) {
		// printf("flag1\n");
        pos = find_one(m, n, picture);
		// printf("flag2\n");
        if (pos.first != -1 && pos.second != -1) {
            int current_size = get_size(pos.first, pos.second, m, n, picture);
			if (current_size != 0) {
            	number_of_area++;
            	max_size_of_one_area = max(max_size_of_one_area, current_size);
			}
			// printf("current size: %d\n", current_size);
        } else {
            break;
        }
    };
    //////
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}