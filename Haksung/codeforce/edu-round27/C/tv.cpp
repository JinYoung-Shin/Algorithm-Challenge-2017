#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// refer to Hangil's code.
// change type int to double.
typedef pair<double, int> Data; 

int main() {
	int n;
	scanf("%d", &n);
	int size = 2*n;
	vector<Data> vec;
	vec.reserve(size);

	for(int i=0; i<n; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		Data tmp;
		
		tmp.first = start;
		tmp.second = 1;
		vec.push_back(tmp);

		tmp.first = end + 0.5;
		tmp.second = -1;
		vec.push_back(tmp);
	}
	
	sort(vec.begin(), vec.end());

	int count = 0;
	for(int i=0; i<size; i++) {
		count += vec[i].second;
		if(count > 2) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
}
