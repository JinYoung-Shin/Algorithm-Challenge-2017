#include <vector>
#include <iostream>

using namespace std;

void dump_vector(vector<int> input) {
	cout << "size:" << input.size() << endl;
	for (int a=0; a < input.size(); a++) {
		cout << "at " << a << ":" << input.at(a) << endl;
	}
}

int main() {
	int c,n,l;
	std::cout.unsetf ( std::ios::floatfield );                // floatfield not set
  std::cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
	cout.precision(10);
	// freopen("input.txt", "r", stdin);
	cin >> c;
	// cout << "c:" << c << endl;
	
	for (int i=0; i < c; i++) {
		cin >> n >> l;
		vector<int> nlist;
		double min;
		
		// cout << i << " 번째" << endl;
		// cout << "n: " << n << " / l: " << l << endl;
		nlist.reserve(n);
		for (int j=0; j < n; j++) {
			int temp;
			cin >> temp;
			nlist.push_back(temp);
		}
		// dump_vector(nlist);
		
		vector<int> s;
		s.push_back(0);
		for (int j=0;j < n; j++) {
			s.push_back(s.at(j) + nlist.at(j));
		}
		 // dump_vector(s);
		//min = (double)s.at(l) / (double)l;
		min = 9999999999;
		
		for (int start = 0; start <= n - l; start++) {
			for (int end = start + l; end <= n; end++) {
				//cout << "(" << end << "," << start << ")" << endl;
				double current = double(s.at(end) - s.at(start)) / (double)(end - start);
				if (current < min) {
					min = current;
				}
			}
		}
		cout << min << endl;
	}
}