#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++) {
        int j = n-1;
        string str = "";
        while(j >= 0) {
            if( (((arr1[i] & (1 << j)) == 0) && ((arr2[i] & (1 << j)) == 0))) {
                str += " ";
            }
            else {
                str += "#";
            }
            j--;
        }
        answer.push_back(str);
    }
            
    return answer;
}