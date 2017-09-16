#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int size = dartResult.size();
    int num[3];
    int stage = 0, i = 0;
    while(stage < 3) {
        if(dartResult[i] == '1' && dartResult[i+1] == '0') {
            num[stage] = 10;
            i++;            
        }
        else
            num[stage] = dartResult[i] - '0';
        i++;
        if(dartResult[i] == 'D')
            num[stage] *= num[stage];
        else if(dartResult[i] == 'T')
            num[stage] = num[stage] * num[stage] *num[stage];
        i++;
        if(dartResult[i] == '*') {
            if(stage == 0)
                num[0] *= 2;
            else {
                num[stage-1] *= 2;
                num[stage] *= 2;
            }
            i++;
        }
        else if(dartResult[i] == '#') {
            num[stage] *= -1;
            i++;
        }
        stage++;
    }
    answer = num[0] + num[1] + num[2];
    return answer;
}