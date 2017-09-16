#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, int> MyPairType;
struct CompareSecond
{
    bool operator()(const MyPairType& left, const MyPairType& right) const
    {
        return left.second < right.second;
    }
};
char easytolower(char in) {
	if (in <= 'Z' && in >= 'A') {
		return in - ('Z'-'z');
	}
	return in;
}

string getMinKey(map<std::string, int> mymap) 
{
  pair<string, int> min 
      = *min_element(mymap.begin(), mymap.end(), CompareSecond());
  return min.first; 
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
	map<string, int> cache;
	int len = cities.size();
	
	for (int i=0; i < len; i++) {
		string str = cities[i];
		transform(str.begin(), str.end(), str.begin(), easytolower);
		// cout << "processing: " << str << endl;
		if (cache.find(str) == cache.end()) { //cache miss
			answer += 5;
			// cout << "cache miss ";
			if (cacheSize <= 0) continue;
			if (cacheSize > cache.size()) { //empty cache block exist
				cache[str] = i;
				// cout << "slot Ok" << endl;
			} else{ // need to select victim
				string victim = getMinKey(cache);
				cache.erase(victim);
				cache[str] = i;
				// cout << "no slot. victim = " << victim << endl;
			}
		} else { // cache hit
			answer++;
			cache[str] = i;
			// cout << " cache hit" << endl;
		}
	}
    return answer;
}
