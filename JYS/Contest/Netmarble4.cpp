#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int l, vector<int> v) {
    int answer = 0;
    vector<bool> visited;
    visited.resize(l+1);
    fill(visited.begin(), visited.end(), false);
    
    int flag = 0;
    int d = l / v.size();
    int dd = d;
    
    // cout << d;
    
    while(true) {
        for(int i = 0; i < v.size(); i++) {
            flag = 1;
            visited[v[i]] = true;
            for(int j = 1; j <= dd; j++) {
                if(v[i] - j < 0 || visited[v[i]-j] == true) {
                    // 비교
                    visited[v[i]+j] = true;
                    continue;
                }
                if(v[i] + j > l || visited[v[i]+j] == true){
                    // 비교 한번 더
                    visited[v[i]-j] = true;
                    continue;
                }
                visited[v[i]+j] = true;
                visited[v[i]-j] = true;
            }
        }
        for(int t = 0; t <= l+1; t++) {
            cout << visited[t] << " ";
        }
        cout << endl;
        for(int i = 0; i <= l+1; i++) {
            if(visited[i] == false) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            answer = dd;
            break;
        }
        dd++;
    }

    return answer;
}