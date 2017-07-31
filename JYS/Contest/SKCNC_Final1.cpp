//1번
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<int>> customer, int K) {
    vector<int> answer;
    vector<int> waitlist;
    for(int i = 0; i < customer.size(); i++) {
        //대기 큐에 있을 경우에 대기 큐 처리
        while(K != 0 && waitlist.size() != 0) {
            vector<int>::iterator iterPtr = waitlist.begin();
            answer.push_back(*iterPtr);
            waitlist.erase(iterPtr);
            K--;
        }        
        //예약
        if(customer[i][1] == 1) {
            if(K != 0) {
                answer.push_back(customer[i][0]);
                K--;
            } else {
                waitlist.push_back(customer[i][0]);
            }
        } 
        //취소
        else {
            //방 취소
            if(answer.size() != 0) {
                vector<int>::iterator iterAns = answer.begin();
                for(iterAns; iterAns < answer.end(); iterAns++) {
                    if(customer[i][0] == *iterAns) {
                        answer.erase(iterAns);
                        K++;
                    }
                }
            }
            //예약 취소
            if(waitlist.size() != 0) {
                vector<int>::iterator iterP = waitlist.begin();
                for(iterP; iterP < waitlist.end(); iterP++) {
                    if(customer[i][0] == *iterP) {
                        waitlist.erase(iterP);
                    }
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}