#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int L, C;
char arr[20];
char cur[20];
int mo = 0, ja = 0;

int check(string &pw) {
	for(int i = 0; i < pw.length(); i++) {
		if(pw[i] == 'a' || 'e' || 'i' || 'o' || 'u') {
			mo++;
		} else {
			ja++;
		}
	}
	return mo >= 1 && ja >=2;
}

void go(char &arr, string pw, int i) {
	if(pw.length() == L) {
		if(check(pw)) {
			cout << pw;
			printf("\n");
		}
		return;
	}
//	go(arr, pw + arr+i, i+1);
//	go(arr, pw, i+1);
}
int main() {
	scanf("%d %d", &L, &C);
	for(int i = 0; i < C; i++) {
		scanf("%c", &arr[i]);
	}
	sort(arr, arr+20);
	go(arr, "", 1);
	
	return 0;
}