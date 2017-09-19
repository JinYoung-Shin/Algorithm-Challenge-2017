
#include <string>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    // make string lower
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    // make pair
    vector<string> vec1;
    vector<string> vec2;
    for(int i=0; i<str1.size()-1; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z' && str1[i+1] >= 'a' && str1[i+1] <= 'z') {
            string tmp = str1.substr(i,2);
            vec1.push_back(tmp);
        }
        else    continue;
    }
    for(int i=0; i<str2.size()-1; i++) {
        if(str2[i] >= 'a' && str2[i] <= 'z' && str2[i+1] >= 'a' && str2[i+1] <= 'z') {
            string tmp = str2.substr(i,2);
            vec2.push_back(tmp);
        }
        else    continue;
    }
    // calc
    int size1 = vec1.size();
    int size2 = vec2.size();
    int count = 0;
    for(int i=0; i<size1; i++) {
        for(int j=0; j<vec2.size(); j++) {
            if(vec1[i] == vec2[j]) {
                count++;
                vec2.erase(vec2.begin()+j);
                break;
            }
        }
    }
    // sol
    double sol;
    if(size1==0 && size2==0)  sol = 1.0;
    else
        sol = (double)count / (double)(size1+size2-count);
    answer = (int)(65536 * sol);

    return answer;
}