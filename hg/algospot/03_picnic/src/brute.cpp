#include <iostream>
#include <cstdio>

using namespace std;

int num_case;
int num_friend;
int num_pair;

// a와 b가 친구이면(a<b) is_friend[a][b]가 true
bool is_friend[10][10];
// a가 짝지가 있으면, taken[a] = true
bool taken[10];

void init_friend_vector() {
	for (int i=0; i < num_friend; i++) {
		taken[i] = false;
		for (int j=0; j < num_friend; j++) {
			is_friend[i][j] = false;
		}
	}
}

int num_of_case() {
	int first_one = -1;
	int count = 0;
	for (int i=0; i < num_friend; i++) {
		if (taken[i] == false) {
			first_one = i;
			break;
		}
	}
	if (first_one == -1) {
		// 모두 매칭된 경우 이것은 1가지 케이스이다.
		return 1;
	}
	for (int second_one = first_one + 1; second_one < num_friend; second_one++) {
		if (taken[second_one] == false && is_friend[first_one][second_one]) {
			//가능한 조합일 경우
			taken[first_one] = taken[second_one] = true;
			count += num_of_case();
			taken[first_one] = taken[second_one] = false;
		}
	}
	
	return count;
}

int main() {
	
	int temp1, temp2;
	scanf("%d\n", &num_case);
	
	for (int i=0; i < num_case; i++) {
		scanf("%d %d\n", &num_friend, &num_pair);
		init_friend_vector();
		for (int j=0; j < num_pair; j++) {
			scanf("%d %d ", &temp1, &temp2);
			if (temp1 < temp2) {
				is_friend[temp1][temp2] = true;
			} else if (temp1 > temp2) {
				is_friend[temp2][temp1] = true;
			}
		}
		printf("%d\n", num_of_case());
	}
	
}