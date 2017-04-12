#include <cstdio>

typedef struct {
	int x, y;
}pair;

int dis(int a, int b) {
	if(a > b) return a-b;
	else return b-a;
}

int main() {
	int X, Y, count, dir, pos, max, half, tmp, total;
	pair p[110], me;
	// input	
	scanf("%d %d", &X, &Y);
	half = X + Y;
	max = 2 * half;
	scanf("%d", &count);
	for(int i=1; i<=count; i++) {
		scanf("%d %d", &dir, &pos);
		if(dir == 1)	  {	p[i].x = pos; p[i].y = 0; }
		else if(dir == 2) { 	p[i].x = pos; p[i].y = Y; }
		else if(dir == 3) {	p[i].y = pos; p[i].x = 0; }
		else if(dir == 4) { 	p[i].y = pos; p[i].x = X; }
	}
	scanf("%d %d", &dir, &pos);
	if(dir == 1)		me.x = pos;
	else if(dir == 2) { 	me.x = pos; me.y = Y; }
	else if(dir == 3)	me.y = pos;
	else if(dir == 4) { 	me.y = pos; me.x = X; }

	// calculate
	for(int i=1; i<=count; i++) {
		if(p[i].x == me.x) {
			if(p[i].y == me.y)	tmp = 0;
			else if(me.x==0 || me.x==X)	tmp = dis(p[i].y, me.y);
			else	tmp = Y + 2*me.x;	
		}
		else if(p[i].y == me.y) {
			if(me.y==0 || me.y==Y)	tmp = dis(p[i].x, me.x);
			else	tmp = X + 2*me.y;
		}
		else {
			if((p[i].x==0 && me.x==X) || (p[i].x==X && me.x==0))	tmp = X + p[i].y + me.y; 
			else if((p[i].y==0 && me.y==Y) || (p[i].y==Y && me.y==0))	tmp = Y + p[i].x + me.x;
			else	tmp = dis(p[i].x, me.x) + dis(p[i].y, me.y);	 
		}
		if(tmp > half) tmp = max -tmp;
		total += tmp;
	}
	printf("%d", total);

	return 0;
}
