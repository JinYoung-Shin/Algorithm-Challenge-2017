#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<n; i++) {
        int tmp = arr1[i] | arr2[i];
        string s_tmp;
        string rev;
        for(int i=0; i<n; i++) {
            rev += (tmp % 2);
            tmp /= 2;
        }

        for(int j=n-1; j>=0; j--) {
            if(rev[j] == 0)
                s_tmp += ' ';
            else
                s_tmp += '#'; 
        }
        answer.push_back(s_tmp);
    }
    return answer;
}