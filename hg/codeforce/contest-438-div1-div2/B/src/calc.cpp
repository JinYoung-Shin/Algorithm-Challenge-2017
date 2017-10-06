#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<double, char> pdc;
vector<pdc> arr;
int main() {
	double hour, min, sec;
	arr.reserve(5);
	int h, m, s, t1, t2;
	
	cin >> h >> m >> s >> t1 >> t2;
	
	hour = (double)h + (double)m/(12*5) + (double)s/(12*60);
	while (hour >= 12) {
		hour -= 12;
	}
	min = (double)m/5 + (double)s/(5*60);
	while (min >= 12) {
		min -= 12;
	}
	sec = (double)s/5;
	while (sec >= 12) {
		sec -= 12;
	}
	//debug//
	// cout << hour << endl << min << endl << sec << endl;
	//debug//
	arr.push_back(pdc(hour, 'h'));
	arr.push_back(pdc(min, 'm'));
	arr.push_back(pdc(sec, 's'));
	arr.push_back(pdc((double)t1, '1'));
	arr.push_back(pdc((double)t2, '2'));
	sort(arr.begin(), arr.end());
	bool yes = false;
	for (int i=0; i < 5; i++) {
		char f = arr[i].second;
		char s = arr[(i+1)%5].second;
		//debug
		cout << arr[i].first << ' ' << arr[i].second << endl;
		//debug
		if (f == '1' && s == '2' || f == '2' && s == '1') {
			yes = true;
		}
	}
	
	if (yes) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}