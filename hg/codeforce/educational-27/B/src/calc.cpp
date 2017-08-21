#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string seq;

typedef pair<int, int> data; // (값, 위치)
int sum_front() {
	int ret = 0;
	for (int i=0; i < 3; i++) {
		ret += seq[i] - '0';
	}
	return ret;
}
int sum_rear() {
	int ret = 0;
	for (int i=3; i < 6; i++) {
		ret += seq[i] - '0';
	}
	return ret;
}
data max_front() {
	data ret;
	ret.first = 0;
	for (int i=0; i < 3; i++) {
		if (ret.first < seq[i]-'0') {
			ret.first = seq[i]-'0';
			ret.second = i;
		}
	}
	return ret;
}
data min_front() {
	data ret;
	ret.first = 9;
	for (int i=0; i < 3; i++) {
		if (ret.first > seq[i]-'0') {
			ret.first = seq[i]-'0';
			ret.second = i;
		}
	}
	return ret;
}
data max_rear() {
	data ret;
	ret.first = 0;
	for (int i=3; i < 6; i++) {
		if (ret.first < seq[i]-'0') {
			ret.first = seq[i]-'0';
			ret.second = i;
		}
	}
	return ret;
}
data min_rear() {
	data ret;
	ret.first = 9;
	for (int i=3; i < 6; i++) {
		if (ret.first > seq[i]-'0') {
			ret.first = seq[i]-'0';
			ret.second = i;
		}
	}
	return ret;
}

int main() {
	int ans = 0;
	cin >> seq;
	
	int front = sum_front();
	int rear = sum_rear();
	
	bool first_state;
	if (front > rear) {
		first_state = true;
	} else if (front < rear) {
		first_state = false;
	}

	while(true) {
		front = sum_front();
		rear = sum_rear();
		if (front == rear || (first_state == true && front < rear) || (first_state == false && front > rear)) {
			cout << ans << endl;
			return 0;
		}
		if (front > rear) { //앞이 큰 경우
			data front_max = max_front();
			data rear_min = min_rear();
			int front_decrement = front_max.first;
			int rear_increment = 9 - rear_min.first;
			if (front_decrement > rear_increment) {
				int front_pos = front_max.second;
				seq[front_pos] = '0';
				ans++;
			} else {
				int rear_pos = rear_min.second;
				seq[rear_pos] = '9';
				ans++;
			}
		} else {//뒤가 큰 경우
			data front_min = min_front();
			data rear_max = max_rear();
			int front_increment = 9 - front_min.first;
			int rear_increment = rear_max.first;
			if (front_increment > rear_increment) {
				int front_pos = front_min.second;
				seq[front_pos] = '9';
				ans++;
			} else {
				int rear_pos = rear_max.second;
				seq[rear_pos] = '0';
				ans++;
			}
		}
	}
	
}