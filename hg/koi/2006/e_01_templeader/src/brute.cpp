#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

vector<vector<int> > std_info; //[1][2] = 5 이면 1번학생이 (2+1)학년때 5반이었다.
vector<vector<bool> > friend_info; // [1][2] = true이면 1이랑 2는 친구다
vector<int> inmaek; // 학생의 인맥 수를 저장하는 배열이다.
int num_of_std;

void dump();
void dump_friend();
bool is_friend(int, int);

int main() {
	bool temp;
	int max_man_index = 0, max_val = 0;
	scanf("%d\n", &num_of_std);
	
	std_info.reserve(num_of_std);
	friend_info.reserve(num_of_std);
	inmaek.resize(num_of_std, 0);
	
	for (int i=0; i < num_of_std; i++) {
		std_info[i].reserve(5);
		friend_info[i].resize(num_of_std, false);
		scanf("%d %d %d %d %d\n", &std_info[i][0], &std_info[i][1], &std_info[i][2], &std_info[i][3], &std_info[i][4]);
	}
	// dump();
	
	for (int i=0; i< num_of_std; i++) {
		for (int j=0; j< num_of_std; j++) {
			if (i==j) {
				continue;
			} else {
				temp = is_friend(i, j);
				friend_info[i][j] = temp;
				friend_info[j][i] = temp;
				if (temp) {
					inmaek[i]++;
				}
			}
		}
	}
	// dump_friend();
	
	for (int i=0; i < num_of_std; i++) {
		if (inmaek[i] > max_val) {
			max_man_index = i;
			max_val = inmaek[i];
		}
	}
	
	// cout << "answer" << endl;
	cout << max_man_index + 1 << endl;
}

bool is_friend(int a, int b) {
	if (friend_info[a][b]) {
		return true;
	}
	if (a==b) {
		return false; //자기 자신은 체크하지 않는다.
	}
	for(int j=0; j<5; j++) {
		if (std_info[a][j] == std_info[b][j]) {
			// printf("%d번학생과 %d번 학생은 %d학년때 같은 %d반을 해서 친구이다\n", a+1,b+1,(j+1), std_info[a][j]);
			return true;
		}
	}
	return false;
}
void dump() {
	for (int i=0;i<num_of_std; i++) {
		// printf("%d %d %d %d %d\n", std_info[i][0], std_info[i][1], std_info[i][2], std_info[i][3], std_info[i][4]);
	}
}
void dump_friend() {
	for (int i=0; i<num_of_std; i++) {
		for(int j=0; j<num_of_std; j++) {
			// printf("(%d, %d) = %s\n", i,j, friend_info[i][j] ? "friend" : "not friend");
		}
	}
	for(int i=0; i<num_of_std;i++) {
		// printf("%d학생의 친구는 %d명이다.\n", i+1, inmaek[i]);
	}
}