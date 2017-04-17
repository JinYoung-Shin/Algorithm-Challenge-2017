#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int M;
char str[100];
int num;
int sum = 0;

int main() {
	scanf("%d", &M);
	for(int i = 1; i <= M; i++) {
//		cin >> str >> num;
		scanf("%s", str);
		//scanf("%d", num);
		//add
		if(!strcmp(str,"add")) {
			scanf("%d", &num);
			num--;
			sum |= (1 << num);	
		}
		//remove
		if(!strcmp(str,"remove")) {
			scanf("%d", &num);
			num--;
			sum &= ~(1 << num);
		}
		//check
		if(!strcmp(str,"check")) {
			scanf("%d", &num);
			num--;
			if(sum & (1 << num)) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		}
		//toggle
		if(!strcmp(str,"toggle")) {
			scanf("%d", &num);
			num--;
			if(sum & (1 << num)) {
				sum &= (1 << num);
			} else {
				sum |= (1 << num);
			}
		}
		//all
		if(!strcmp(str, "all")) {
			sum = (1<<20) - 1;
		}
		//empty
		if(!strcmp(str,"empty")) {
			sum &= (1 << 21);
		}
	}
	return 0;
}