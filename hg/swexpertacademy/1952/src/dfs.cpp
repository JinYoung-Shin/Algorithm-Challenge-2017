#include <iostream>
#include <algorithm>
using namespace std;

int day_fee, mon_fee, mon3_fee, year_fee;
int goto_day_num[12];
int find_min(int left, int current) {
	if (left >= 12) return current;
	if (goto_day_num[left] == 0) return find_min(left+1, current);
	int val = 987654321;
	val = min(val, find_min(left+1, current + day_fee * goto_day_num[left]));
	val = min(val, find_min(left+1, current + mon_fee));
	val = min(val, find_min(left+3, current + mon3_fee));
	return val;
}
int main() {
	int tc_num;
	cin >> tc_num;
	for (int i=1; i <= tc_num; i++) {
		cin >> day_fee >> mon_fee >> mon3_fee >> year_fee;
		for (int j=0; j < 12; j++) {
			cin >> goto_day_num[j];
		}
		
		cout << '#' << i << ' ' << min(find_min(0, 0), year_fee) << endl;
		
	}
	return 0;
}