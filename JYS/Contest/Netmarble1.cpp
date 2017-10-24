#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> s) {
    int answer = 0;

    int size = s.size();
    vector<int> visited;
    visited.resize(size);
    fill(visited.begin(), visited.end(), 0);
        
    for(int i = 0; i < size; i++) {
        if(visited[i] == 1) continue;
        
        if(s[i] == 4) {
            visited[i] = 1;
            continue;
        }
        
        for(int j = i+1; j < size; j++) {
            if(s[i] + s[j] == 4) {
                answer++;
                visited[i] = 1;
                visited[j] = 1;
                break;
            }
            if(s[i] + s[j] > 4) {
                if(j >= size - 1) {
                    visited[i] = 1;
                    break;
                }
                continue;
            }
            else {
                s[i] += s[j];
                visited[j] = 1;
                answer++;
                if(j >= size - 1) {
                    visited[i] = 1;
                    break;
                }
            }
            
        }
        
    }
    
    answer = size - answer;
    return answer;
}