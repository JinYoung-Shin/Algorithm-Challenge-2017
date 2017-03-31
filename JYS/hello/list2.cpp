// list1에 점 F 추가 및 D, E 사이에 연결
// 점 C 삭제하기

#include <cstdio>
#include <iostream>
#include <list>
using namespace std;

struct Point {
	Point( int p1, int p2 ){
		x = p1;
		y = p2;
	}
	
	int x; // x val of a point
	int y; // y val of a point	
};

int main() {
	
	list<Point> lst;
	
	Point point_A(50, 200);
	lst.push_back(point_A);
	Point point_B(20, 80);
	lst.push_back(point_B);
	Point point_C(75, 10);
	lst.push_back(point_C);
	Point point_D(130, 80);
	lst.push_back(point_D);
	Point point_E(100, 200);
	lst.push_back(point_E);
	
	// Registration&Location of F 
	Point point_F(180, 150);
	list<Point>::iterator iterinsertPos = lst.begin();
	for(int i = 0; i < 4; i++) {
		++iterinsertPos;
	}
	lst.insert(iterinsertPos, point_F);
	
	// Deletion of Point C
	for(int i = 0; i < 3; i++){
		--iterinsertPos;
	}
	lst.erase(iterinsertPos);
	
	list<Point>::iterator iterEnd = lst.end();
	for(list<Point>::iterator iterPtr = lst.begin(); iterPtr != iterEnd; ++iterPtr) {
		cout<< iterPtr->x << ' ' << iterPtr->y << endl;
	}
	
	return 0;
}