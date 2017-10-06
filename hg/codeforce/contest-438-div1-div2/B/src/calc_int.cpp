#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, char> pic;

vector<pic> arr;

int main() {
	int h, m, s, t1, t2;
	arr.reserve(5);
	cin >> h >> m >> s >> t1 >> t2;
	
	int h_dir = h * 3600 + 60 *m + s;
	int m_dir = m * 720 + s * 12;
	int s_dir = s * 720;
	
	int t1_dir = t1 * 3600;
	int t2_dir = t2 * 3600;
	
	h_dir %= 43200;
	m_dir %= 43200;
	s_dir %= 43200;
	
	arr.push_back(pic(h_dir, 'h'));
	arr.push_back(pic(m_dir, 'm'));
	arr.push_back(pic(s_dir, 's'));
	arr.push_back(pic(t1_dir, '1'));
	arr.push_back(pic(t2_dir, '1'));
	
	sort(arr.begin(), arr.end());
	for (int i=0; i < 5; i++) {
		if (arr[i].second == arr[(i+1)%5].second) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}