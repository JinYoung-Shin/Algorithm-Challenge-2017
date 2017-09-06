#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef struct _vec {
	int a[5];
} vec;

int dot(vec& lhs, vec& rhs) {
	int ret = 0;
	for (int i=0; i < 5; i++) {
		ret += lhs.a[i] * rhs.a[i];
	}
	return ret;
}
vec minux(vec& lhs, vec& rhs) {
	vec ret;
	for (int i=0; i < 5; i++) {
		ret.a[i] = rhs.a[i] - lhs.a[i];
	}
	return ret;
}

vec points[1001];

int main() {
	vector<int> answers;
	int n; // num of points
	
	cin >> n;
	for (int i=1; i <= n; i++) {
		cin >> points[i].a[0];
		cin >> points[i].a[1];
		cin >> points[i].a[2];
		cin >> points[i].a[3];
		cin >> points[i].a[4];
	}
	
	for (int i=1; i <= n; i++) {
		bool is_good = true;
		auto& vec_a = points[i];
		for (int j=1; j <= n;j++) {
			if (i==j) continue;
			auto& vec_b = points[j];
			for (int k=1; k <= n; k++) {
				if (i==k) continue;
				if (j==k) continue;
				auto& vec_c = points[k];
				vec vec_ab = minux(vec_b ,vec_a);
				vec vec_ac = minux(vec_c ,vec_a);
				if (dot(vec_ab, vec_ac) > 0) {
					is_good = false;
					goto judge;
				}
			}
		}
		judge:
		if (is_good) {
			answers.push_back(i);
		}
	}

	//dump answer
	int ans_size = answers.size();
	cout << ans_size << endl;
	for (int i=0; i < ans_size; i++) {
		cout << answers[i] << endl;
	}
}