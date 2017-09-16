#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int str2min(string t) {
	const char* ct = t.c_str();
	int h, m;
	sscanf(ct, "%d:%d", &h, &m);
	
	return h*60 + m;
}
string min2str(int min) {
	int h = min/60;
	int m = min%60;
	char buf[64];
	snprintf(buf, sizeof(buf), "%02d:%02d", h, m);
	string ret = buf;
	return ret;
}
static int initial_bus_time;
static int final_bus_time;
static int total_capacity;
static vector<int> arrival_time;
static int num_crew;

bool is_ok(int n, int t, int m, int my) {
	int taken_crew = 0; //다음에 탑승할 크루 번호
	for (int i=0; i < n; i++) {
		int bus_time = initial_bus_time + i * t;
		//////
		int taken_num = 0;//이번 버스에 탄 사람 수
		while (taken_num < m && taken_crew < num_crew+1) {
			if (my <= bus_time && (taken_crew >= arrival_time.size() ||my < arrival_time[taken_crew])) {
				return true;
			} else if (arrival_time[taken_crew] <= bus_time) {
				taken_crew++;
				taken_num++;
				// printf("%s에 %d번 크루가 탑승(%d)\n", min2str(bus_time).c_str(), taken_crew, taken_num);
			} else {
				break;
			}
		}
	}
	return false;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
	// int initial_bus_time = 540; //09:00
	// int final_bus_time = initial_bus_time + (n-1) * t; //막차시간
	// int total_capacity = n * m;
	// int num_crew = timetable.size();
	// vector<int> arrival_time;
	initial_bus_time = 540; //09:00
	final_bus_time = initial_bus_time + (n-1) * t; //막차시간
	total_capacity = n * m;
	num_crew = timetable.size();
	arrival_time.reserve(num_crew);
	for (int i=0; i < num_crew; i++) {
		arrival_time.push_back(str2min(timetable[i]));
	}
	sort(arrival_time.begin(), arrival_time.end());
	
	
	for (int i = final_bus_time; i >= 0; i--) {
		if (is_ok(n, t, m, i)) {
			return min2str(i);
		}
	}

    return answer;
}