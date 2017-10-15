#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> temp;
    int ans;
    int flag = 0;
    
    int wsize = words.size();
    char match;
    
    for(int i = 0; i < wsize; i++) {
        temp.push_back(words[i]);
        int strsize = words[i].size();
        if(i != 0) {
            if(match != words[i][0]) {
                ans = i + 1;
                break;
            }
            
            for(int j = 0; j < i; j++) {
                // cout<< temp[i] << ' ';
                // cout<< temp[j] << endl;
                if(temp[i] == temp[j]) {
                    ans = i + 1;
                    cout << ans;
                    flag = 1;
                    break;
                }
            }
            if(flag != 0) break;
        }
        match = words[i][strsize-1];
        if(i >= wsize - 1) {
            answer.push_back( 0 );
            answer.push_back( 0 );
        }
    }
    
    if(answer.size() == 0) {
        answer.push_back(n - (ans%n));
        if(ans % n == 0) answer.push_back((ans / n));
        else answer.push_back((ans / n) + 1);
    }
    return answer;
}
