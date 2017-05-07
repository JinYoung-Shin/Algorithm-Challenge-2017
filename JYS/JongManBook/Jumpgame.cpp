#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[110][110];
int cache[110][110];
int ans = 0;

int check_arrive(int x, int y) {
	//base
	if(x > n || y > n) return 0;
	if(x == n && y == n) return 1;
	
	int& ret = cache[x][y]; // 이해가 잘 안되네...
	if(ret != -1) {
		return ret;
	}
	int jumpSize = arr[x][y];
	return ret = (check_arrive(x+jumpSize, y) || check_arrive(x, y+jumpSize));
}

int main(int argc, char** argv) {
	//freopen("sample_input.txt", "r", stdin);
	//setbuf(stdout, NULL);
	int T;
	int test_case;
    
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
        	for(int j = 1; j <= n; j++) {
        		scanf("%d", &arr[i][j]);
        	}
        }
        memset(cache, -1, sizeof(cache));
        cache[n][n] = 1;
		ans = check_arrive(1, 1);
        
        if(ans == 1) {
        	printf("YES\n");
        } else {
        	printf("NO\n");
        }
        
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}