#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverse(const string &input)
{
 string temp(input);
 reverse(temp.begin(), temp.end());
 return temp;
}

int main() {
	string row("");
	int d;
	int n=5;
	cin >> d;
	for (int i=0; i < n; i++) {
		if (d & 1) {
			row += "#";
		} else {
			row += "-";
		}
		d /= 2;
	}
	
	cout << reverse(row) << endl;
}