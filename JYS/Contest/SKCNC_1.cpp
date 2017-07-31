#include <string>
using namespace std;

int solution(string N) {
    int answer = 0;
    int sub = 0;
    
    int arr[10] = {0};
    for(int i = 0; i < N.length(); i++) {
        int val = N[i] - 48;
        arr[val]++;
    }
    
    // for(int i = 0; i < 10; i++) {
    //     cout << arr[i];
    // }
    
    for(int i = 0; i < 10; i++) {
        answer += (arr[i] / 2);
        if(arr[i] % 2 != 0) sub++;
    }
    // ans
    if(sub == 0) {
        answer = answer * 2;
    } else {
        answer = answer * 2 + 1;
    }
    return answer;
}