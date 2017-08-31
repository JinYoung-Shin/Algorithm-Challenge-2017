#include <cstdio>
#include <iostream>

using namespace std;

int N;
char a[80+10];
int flag;
 
int strncmp(const char *s1, const char *s2, unsigned int n)
{
  	while(n--)
  	{
		if(*s1 > *s2) return 1;
		else if(*s1 < *s2) return -1;
		else if(*s1 == 0) return 0;
		s1++;
		s2++;
  	}
  	return 0;
}

int Check(int s)
{
	if(s == 0) 
	{
		return 1;
	}
	
	int t = ++s / 2;
	for(int i = 1; i <= t; i++) {
		if(strncmp(&a[s-i], &a[s-i*2], i) == 0) return 0;
	}
	return 1;
}
 
void DFS(int s)
{	
	if(s >= N) {
		flag = 1;
	}
	else{	
		for(char i = '1'; i <= '3'; i++) {
			a[s] = i;
			if(Check(s) == 0)
				continue;
			DFS(s + 1);
			if(flag = 1) return;		
		}	
	}
}
 
int main(void)
{
  	scanf("%d", &N);
  	DFS(0);
  	printf("%s", a);
	return 0;
}