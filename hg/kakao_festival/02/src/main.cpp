#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > city_map_data;
int solution(int m, int n, vector<vector<int>> city_map);
int main() {
	int num_cases = 2;
	int m[] = {3, 3};
	int n[] = {3, 6};
	vector<city_map_data> city_maps;
	vector<vector<int> > city_map1({
		vector<int>( { 0, 0, 0 }),
		vector<int>( { 0, 0, 0 }),
		vector<int>( { 0, 0, 0 })
	});
	vector<vector<int> > city_map2({
		vector<int>( { 0, 2, 0, 0, 0, 2 }),
		vector<int>( { 0, 0, 2, 0, 1, 0 }),
		vector<int>( { 1, 0, 0, 2, 2, 0 })
	});
	city_maps.push_back(city_map1);
	city_maps.push_back(city_map2);
	for (int Case = 0; Case < num_cases; Case++) {
		int answer = solution(m[Case], n[Case], city_maps[Case]);
		cout << answer << endl;
		
	}
		
}