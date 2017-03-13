#include <stdlib.h>
#include <stdio.h>

using namespace std;

int student[2][6] = {0,};

int main() {
	int num, room_num, count=0, sex, year, total=0;
	
	// freopen("input.txt", "r", stdin);
    scanf("%d %d", &num, &room_num);
	
	while(count++ < num) {
		scanf("%d %d", &sex, &year);
		student[sex][year-1]++;
	}
	
	for(int i=0; i<6; i++) {
		for(int j=0; j<2; j++) {
			while(1) {
				if(student[j][i] > 0) {
					total++;
					student[j][i] = student[j][i] - room_num;
				}
				else
					break;
			}
		}
	}
	
	printf("%d\n", total);
	
	return 0;
}