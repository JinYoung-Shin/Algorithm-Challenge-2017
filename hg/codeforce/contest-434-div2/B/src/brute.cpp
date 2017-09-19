#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;//first번째놈이 second 층에 있다.

int n, m;
vector<P> mem;	

bool is_possible(int i) {
	int bias = i-1;
	for (int j=0; j < m; j++) {
		int a = mem[j].first;
		int b = mem[j].second;
		int expected = (a+bias)/i;
		if (b != expected) return false;
	}
	return true;
}
int main() {
	cin >> n >> m;
	
	mem.reserve(m);
	for (int i=0; i < m; i++) {
		P p;
		cin >> p.first >> p.second;
		mem.push_back(p);		
	}
	int answer = -1;
	for (int i=1; i < 101; i++) {
		if (is_possible(i)) { //지금 i값이 타당하면
			int real_pos = (n+i-1)/i; //이 층이 맞아야 한다.
			if (answer == -1 || answer == real_pos) {
				answer = real_pos;
			} else {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << answer << endl;
}