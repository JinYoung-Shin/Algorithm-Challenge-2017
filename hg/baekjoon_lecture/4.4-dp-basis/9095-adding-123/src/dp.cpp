#include <cstdio>
#include <iostream>

using namespace std;

int answer[12];

int T, num;

int get(int num) {
	int ret = 0;
	if (answer[num] != 0) {
		return answer[num];
	}
	
	if (num - 1 > 0) {
		ret += get(num-1);
		//num-1 케이스에 + 1한 것이 하나의 케이스
	}
	
	if (num - 2 > 0) {
		ret += get(num-2);
		//num-2 케이스에 + 2 한 것이 하나의 케이스
	}
	
	if (num - 3 > 0) {
		ret += get(num-3);
		//num-3 케이스에 + 3 한 것이 하나의 케이스
	}
	
	answer[num] = ret;
	return ret;
}
int main() {
	scanf("%d\n", &T);
	
	answer[1] = 1; // 1 = 1
	answer[2] = 2; // 2 = 1+1, 2
	answer[3] = 4; // 3 = 1+1+1, 1+2, 2+1, 3
	for (int Case = 0; Case < T; Case++) {
		scanf("%d\n", &num);
		cout << get(num) << endl;
	}
}