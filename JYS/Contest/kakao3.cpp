#include <string>
#include <vector>
#include <deque>
#include <cstdio>
#include <cstring>
#include <locale>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> Que;
    for(vector<string>::iterator citer = cities.begin(); citer < cities.end(); citer++) {
        for(int i = 0; i < (*citer).length(); i++) {
            (*citer)[i] = tolower((*citer)[i]);
        }
    }
    for(vector<string>::iterator citer = cities.begin(); citer < cities.end(); citer++) { // lower / upper 처리
        int counter = 0;
        if(cacheSize == 0) {
            answer = cities.size() * 5;
            break;
        }
        if(Que.size() < cacheSize) { // 아직 큐 안채워짐
            if(Que.empty()) {
                    answer += 5;
                    Que.push_front(*citer);
                    continue;
            }
            for(deque<string>::iterator qiter = Que.begin(); qiter < Que.end(); qiter++) {
                if(*qiter == *citer){ // hit
                    answer++;
                    break;
                }
                counter++;
                if(counter == Que.size()) { //miss
                    Que.push_front(*citer);
                    answer += 5;
                }
            }
        } else { // 큐 채워짐
            for(deque<string>::iterator qiter = Que.begin(); qiter < Que.end(); qiter++) {
                if(*qiter == *citer){ // hit
                    answer++;
                    break;
                }
                counter++;
                if( Que.size() < cacheSize || counter == cacheSize) { //miss
                    Que.pop_back();
                    Que.push_front(*citer);
                    answer += 5;
                }
            }
        }
    }
    
    return answer;
}