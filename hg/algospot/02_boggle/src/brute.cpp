#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

int num_case, num_word, i,j,c;
char board[7][7], word[10][10] = {0,};
bool found[10] = {0,};

const int xd[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int yd[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool hasWord(int matched_pos, const char* word, int x, int y) {
	// printf("matched_pos %d (%c) : (%d, %d)\n", matched_pos, word[matched_pos], x, y);
	int word_len = strlen(word);
	if (matched_pos + 1 == word_len) {
		return true;
	}
	int i,j,k;
	vector<int> xpos;
	vector<int> ypos;
	
	if (matched_pos == -1) {
		for(i=1;i<6;i++) {
			for(j=1;j<6;j++) {
				if (word[0] == board[i][j]) {
					xpos.push_back(i);
					ypos.push_back(j);
				}
			}
		}

		for(k=0;k<xpos.size();k++) {
			if (hasWord(0, word, xpos[k], ypos[k])) {
				return true;
			}
		}
		return false;
	} else {
		for(int dir=0;dir<8;dir++) {
			
			if (word[matched_pos+1] == board[x + xd[dir]][y + yd[dir]]) {
				xpos.push_back(x + xd[dir]);
				ypos.push_back(y + yd[dir]);
			}
		}
		for (k=0;k<xpos.size();k++) {
			if (hasWord(matched_pos+1, word, xpos[k], ypos[k])) {
				return true;
			}
		}
		return false;
	}

}
int main() {
	
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d\n", &num_case);
	
	for(c=0; c<num_case; c++) {
		for(i=1;i<6;i++) {
			scanf("%c%c%c%c%c\n", &board[i][1], &board[i][2], &board[i][3], &board[i][4], &board[i][5]);
		}
		scanf("%d\n", &num_word);
		for(i=0;i<num_word;i++) {
			scanf("%s\n", word[i]);
		}
		for(i=0;i<num_word;i++) {
			found[i] = hasWord(-1, word[i], 0, 0);
		}
		for (i=0;i<num_word;i++) {
			printf("%s %s\n", word[i], (found[i] ? "YES" : "NO"));
		}
	}
	
}