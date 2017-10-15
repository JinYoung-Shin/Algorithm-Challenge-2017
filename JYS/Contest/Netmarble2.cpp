/*
카탈란 수,
수가 주어지만 괄호 짝을 맞춰 출력하는 문제
*/

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

vector<string> answer = {};
char arr[30];

void gwalho(int stat, int open, int close) {
    if(open == 0 && close == 0) {
        answer.push_back(arr);
        return;
    }
    
    if(open > 0) {
        arr[stat] = '(';
        gwalho(stat+1, open-1, close+1);
    }
    if(close > 0) {
        arr[stat] = ')';
        gwalho(stat+1, open, close-1);
    }
}

vector<string> solution(int N)
{
    gwalho(0, N, 0);
    return answer;
}