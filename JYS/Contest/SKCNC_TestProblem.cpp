#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
  //vector<vector<int> >의 값은 다음과 같이 읽어올 수 있습니다.
    // cout << v[0][0] << " ";
    vector<int> ans;
    for(int i = 0; i < 2; i++) { // i=0 -> x값 / i=1 -> y값
        if(v[0][i] == v[1][i]) {
            ans.push_back(v[2][i]);
        } else if(v[0][i] == v[2][i]) {
            ans.push_back(v[1][i]);
        } else {
            ans.push_back(v[0][i]); 
        }
    }
    return ans;
}