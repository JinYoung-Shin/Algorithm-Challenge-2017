#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, S;
vector<int> arr;
vector<bool> flag;
int count;
void dump() {
	cout << "{";
	for(int i=0;i<N;i++) {
		if (flag[i]) {
			cout << " " << arr[i];
		}
	}
	cout << " }" << endl;
}
void chk() {
	int sum = 0;
	for (int i=0;i<N;i++) {
		if (flag[i]) {
			sum += arr[i];
		}
	}
	if (sum == S) {
		count++;
	}
}
void dfs(int n) {
	if (n == N) {
		// dump();
		chk();
		return;
	}
	flag[n] = false;
	dfs(n+1);
	flag[n] = true;
	dfs(n+1);
}
int main() {
	cin >> N >> S;
	
	arr.reserve(N);
	flag.resize(N, false);
	
	for (int i=0;i<N;i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	
	dfs(0);
	if (S == 0) {
		count--;
	}
	cout << count << endl;
}