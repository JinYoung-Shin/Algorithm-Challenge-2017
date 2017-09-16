#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int pow(int a, int b) {
	if (b == 1) return a;
	if (b == 2) return a*a;
	if (b == 3) return a*a*a;
}
typedef struct _score {
	int score;
	int sdt;
	bool sharp;
	bool star;
} Score;
int solution(string dartResult) {
    int answer = 0;
	int len = dartResult.length();
	Score score[3];
	score[0].score = -1;
	score[0].sdt = -1;
	score[1].score = -1;
	score[1].sdt = -1;
	score[2].score = -1;
	score[2].sdt = -1;
	score[0].sharp = false;
	score[0].star = false;
	score[1].sharp = false;
	score[1].star = false;
	score[2].sharp = false;
	score[2].star = false;
	
	int state = 0;
	int idx = 0;
	for (int i=0; i < len; i++) {
		char ch = dartResult[i];
		switch(state) {
			case 0:
				if (ch == '1') {
					state = 1;
				} else if (ch >= '2' && ch <= '9' || ch == '0') {
					state = 2;
					score[idx].score = ch - '0';
				}
				break;
			case 1:
				if (ch == '0') {
					score[idx].score = 10;
					state = 3;
				} else if (ch == 'S') {
					score[idx].score = 1;
					score[idx].sdt = 1;
					state = 4;
				} else if (ch == 'D') {
					score[idx].score = 1;
					score[idx].sdt = 2;
					state = 4;
				} else if (ch == 'T') {
					score[idx].score = 1;
					score[idx].sdt = 3;
					state = 4;
				}
				break;
			case 2:
			case 3:
				if (ch == 'S') {
					score[idx].sdt = 1;
					state = 4;
				} else if (ch == 'D') {
					score[idx].sdt = 2;
					state = 4;
				} else if (ch == 'T') {
					score[idx].sdt = 3;
					state = 4;
				}
				break;
			case 4:
				if (ch == '*') {
					score[idx].star = true;
					state = 0;
					idx++;
				} else if (ch == '#') {
					score[idx].sharp = true;
					state = 0;
					idx++;
				} else if (ch == '1') {
					state = 1;
					idx++;
				} else if (ch >= '2' && ch <= '9' || ch == '0') {
					idx++;
					state = 2;
					score[idx].score = ch - '0';
				}
				break;
		}
	}
	
	//dump
	// printf("state: %d\n", state);
	// for (int i=0;i <3; i++) {
	// 	printf("%d %d %c %c\n", score[i].score, score[i].sdt, score[i].sharp ? '#' : '-', score[i].star ? '*' : '-');
	// }
	//dump
	int arr[3];
	for (int i=0; i < 3; i++) {
		arr[i] = pow(score[i].score, score[i].sdt);
	}
	if (score[0].star) {
		arr[0] *= 2;
    }
	if (score[1].star) {
		arr[0] *= 2;
		arr[1] *= 2;
	}
	if (score[2].star) {
		arr[1] *= 2;
		arr[2] *= 2;
	}
	for (int i=0; i < 3; i++) {
		if (score[i].sharp) {
			arr[i] *= -1;
		}
	}
	answer = arr[0] + arr[1] + arr[2];
    return answer;
}

int main() {
	string str;
	cin >> str;
	
	cout << solution(str) << endl;
}