#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

vector<int> holiday;
vector<bool> day;
int total_day, absent_day;
int cost[101][101];

int count = 0;
int count_mem = 0;
int find_cost(int start_day, int num_coupon) {
	count ++;
	int min_cost = 987654321;
	int temp, a,b;
	temp = 987654321;
	if (start_day > total_day) {
		//basis case
		return 0;
	} else if (!day[start_day]) {
		
		for (int i=start_day+1; i<=total_day; i++) {
			if (day[i]) {
				return find_cost(i, num_coupon);
			}
		}
		return 0;
	}
	
	if (cost[start_day][num_coupon] == 0) {
		if ( start_day <= total_day - 2 && day[start_day+1] && day[start_day+2] ) {
			
		} else {
			min_cost = MIN(min_cost, find_cost(start_day + 1, num_coupon) + 10000 );
		}
		
		if (min_cost != temp) {
			temp = min_cost;
			a = start_day + 1;
			b = num_coupon;
		}
		
		if ( start_day <= total_day - 5 && day[start_day+1] && day[start_day+2] && day[start_day+3] && day[start_day+4]) {
		} else {
			min_cost = MIN(min_cost, find_cost(start_day + 3, num_coupon + 1) + 25000 );
		}
		
		if (min_cost != temp) {
			temp = min_cost;
			a = start_day + 3;
			b = num_coupon + 1;
		}
		
		min_cost = MIN(min_cost, find_cost(start_day + 5, num_coupon + 2) + 37000 );
		
		if (min_cost != temp) {
			temp = min_cost;
			a = start_day + 5;
			b = num_coupon + 2;
		}
		
		if (num_coupon >= 3) {
			min_cost = MIN(min_cost, find_cost(start_day + 1, num_coupon - 3) );
			
			if (min_cost != temp) {
				a = start_day + 1;
				b = num_coupon - 3;
			}

		}
		cost[start_day][num_coupon] = min_cost;
		// printf("(%d, %d) -> (%d, %d)\t", start_day, num_coupon, a, b);
		return min_cost;
	} else {
		count_mem++;
		return cost[start_day][num_coupon];
	}
	
	
}
int main() {
	int temp;
	int answer;
	
	scanf("%d %d\n", &total_day, &absent_day);
	holiday.reserve(absent_day);
	day.resize(total_day + 1, true);

	for (int i=0;i<absent_day; i++) {
		scanf("%d ", &temp);
		holiday.push_back(temp);
		// cout << temp << " ";
	}
	
	// cout << endl << "length:" << holiday.size() << endl;
	for (int i=0;i<absent_day; i++) {
		//cout << holiday[i]<< endl;
		day[holiday[i]] = false;
	}
	// for (int i=1;i<=total_day;i++) {
	// 	cout << day[i] << " ";
	// }
	
	answer = find_cost(1, 0);
	cout << answer;
	// cout << endl << "answer: " << answer << endl << "count: " << count << endl << "count_mem: " << count_mem << endl;
}