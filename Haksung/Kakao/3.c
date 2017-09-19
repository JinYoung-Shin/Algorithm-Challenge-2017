#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> cache;

int visit_cache(string str) {
    int size = cache.size();
    for(int i=0; i<size; i++) {
        if(str == cache[i])
            return i;
    }
    return -1;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int num;
    int c_size = cities.size();
    // calc
    for(int i=0; i<c_size; i++) {
        if(cacheSize == 0)  {
            answer = c_size * 5;
            break;
        }
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        num = visit_cache(cities[i]);
        // hit
        if(num != -1) {
            if(num != cache.size()) {
                for(int i=num; i<cache.size()-1; i++)
                    cache[i] = cache[i+1];
                cache[cache.size()-1] = cities[i];
            } 
            answer++;
        }
        // miss
        else {
            if(cache.size() < cacheSize)
                cache.push_back(cities[i]);
            // LRU
            else {
                cache.erase(cache.begin());
                cache.push_back(cities[i]);
            }
            answer += 5;
        } 
    } 
    
    return answer;
}