#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct bus {
    int hour, min, avail, in;
};

bus b[11];

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    answer = "00:00";
    int my_h = 9;
    int my_m = 0;
    // make bus
    for(int i=0; i<n; i++) {
        b[i].hour = my_h;
        b[i].min = my_m;
        b[i].avail = m;
        b[i].in = 0;
        my_m += t;
        if(my_m >= 60) {
            my_h++
            my_m -= 60;
        }
    }
    // take bus
    sort(timetable.begin(), timetable.end());
    int size = timetable.size();
    for(int i=0; i<size; i++) {
        int hh = timetable[i].substr(0,2);
        int mm = timetable[i].substr(3,2);
        for(int j=0; j<size; j++) {
            if(hh <= b[j].hour ) {
                
            }
            
        }
    }
    
    return answer;
}
