#include <iostream>

using namespace std;

double ABS(double x) {
	return x*x;
}

int main() {
	int n, a;
	double k, theta;
	int ans = 3;
	double error = 9999999;
	
	cin >> n >> a;
	k = 180 - (((double)360)/n);
	theta = (((double)180)/n);
	
	double candidate = k;
	error = ABS(candidate - a);
	for (int v3 = 3; v3 <= n; v3++) {
		double cur_err = ABS(candidate - a);
		if (cur_err <= error) {
			ans = v3;
			error = cur_err;
		}
		candidate -= theta;
	}
	cout << "1 2 " << ans << endl;
}