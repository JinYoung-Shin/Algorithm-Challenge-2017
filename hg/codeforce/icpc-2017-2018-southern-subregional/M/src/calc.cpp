#include <iostream>

using namespace std;

int main() {
	int x1, y1, x2, y2;
	
	cin >> x1 >> y1 >> x2 >> y2;
	
	int garo = abs(y2-y1) + 1;
	int sero = abs(x2-x1) + 1;
	garo = max(garo, 2);
	sero = max(sero, 2);
	
	
	cout << ((garo+sero)*2) << endl;
}