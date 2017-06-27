#include <iostream>

using namespace std;

int main() {
	int c, v0, v1, a, l;
	int current_page = 0;
	int iteration = 0;
	cin >> c >> v0 >> v1 >> a >> l;

	while(true) {
		int increment = v0 + iteration * a;
		if (increment > v1) increment = v1;
		iteration++;
		current_page += increment;
		if (current_page >= c) break;
		current_page -= l;
	}
	cout << iteration << endl;
}