#include <iostream>
#include <cstdio>
using namespace std;

typedef long long int ll;
typedef struct _pos {
	ll x,y;
} pos;

int main() {
	//세 점이 같은 직선 위에 있거나, ab길이와 bc길이가 다르면 No이다.
	pos a,b,c;
	double inc_ab = 0, inc_bc = 0;
	bool inf_ab = false, inf_bc = false;
	ll dist_ab, dist_bc;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	
	if (a.x == b.x) //ab 점 기울기가 무한대
		inf_ab = true;
	else {
		inc_ab = ((double)b.y - a.y) / (b.x - a.x);
	}
	if (b.x == c.x) //bc 점 기울기가 무한대
		inf_bc = true;
	else {
		inc_bc = ((double)c.y - b.y) / (c.x - b.x);
	}
	
	dist_ab = ((b.x - a.x)*(b.x - a.x)) + ((b.y - a.y)*(b.y - a.y));
	dist_bc = ((c.x - b.x)*(c.x - b.x)) + ((c.y - b.y)*(c.y - b.y));
	
	bool ans = true;
	
	if (dist_ab != dist_bc){
		ans = false;
	} 
		
	if (inf_ab && inf_bc){
		ans = false;
	}
	else if (!inf_ab && !inf_bc && inc_ab == inc_bc) {
		ans = false;
	}
	
	
	if (ans) 
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}