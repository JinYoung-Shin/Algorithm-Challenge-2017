#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int pointer = 0;
        
    int num[4];
    int times[4];
    int prize[4] = {1, 1, 1, 0};
    
    for(int i = 0 ; i < 3; i++) {    
        num[i] = dartResult[pointer] - 48;
        pointer++;
        if(dartResult[pointer] == 48) {// 숫자 10인 경우, 아니면 1자리 숫자다. 
            num[i] = 10;
            pointer++;
        }
        
        // S, D, T
        if(dartResult[pointer] == 'S') {
            times[i] = 1;
        } else if(dartResult[pointer] == 'D') {
            times[i] = 2;
        } else {
            times[i] = 3;            
        }
        pointer++;
        
        // * or #
        if(dartResult[pointer] == '*') {
            if(i == 0){
                prize[i] *= 2;
            } else {
                prize[i-1] *= 2;
                prize[i] *= 2;
            }
            pointer++;
        } else if(dartResult[pointer] == '#') {
            prize[i] *= -1;
            pointer++;
        }
    }
    
    for(int i = 0; i < 3; i++) {
        answer += pow(num[i], times[i]) * prize[i];
    }
    
    return answer;
}