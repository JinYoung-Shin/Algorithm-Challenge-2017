#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int count = 0;
    string temp = "";
    
    vector<string> ar1;
    vector<string> ar2;
    
    // string 소문자화, 깎는거부터
    for(int i = 0; i < str1.length(); i++) {
        str1[i] = tolower(str1[i]);
    }
    for(int i = 0; i < str2.length(); i++) {
        str2[i] = tolower(str2[i]);
    }
    
    for(int i = 0 ; i < str1.length() - 1; i++) {
        if((str1[i] >= 97 && str1[i] <= 122) && (str1[i+1] >= 97 && str1[i+1] <= 122))
        {
            temp += str1[i];
            temp += str1[i+1];
            ar1.push_back(temp);
            temp = "";
        }
    }
    count = 0;
    for(int i = 0 ; i < str2.length() - 1; i++) {
        if((str2[i] >= 97 && str2[i] <= 122) && (str2[i+1] >= 97 && str2[i+1] <= 122))
        {
            temp += str2[i];
            temp += str2[i+1];
            ar2.push_back(temp);
            temp = "";
        }
    }
    
    // 합집합, 교집합 구하기(다중 처리 안됨 ...)
    vector<string> sum;
    sum.resize(ar1.size() + ar2.size());
    auto itr1 = set_union(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), sum.begin());
    sum.erase(itr1, sum.end());
    
    vector<string> com;
    com.resize(ar1.size() + ar2.size());
    auto itr2 = set_intersection(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), com.begin());
    com.erase(itr2, com.end());
    
    int csize = com.size();
    int ssize = sum.size();
    
    if(ssize == 0) {
        answer = 65536;
    } else {
        answer = ((float)csize/(float)ssize) * 65536;
    }
    return answer;
}
