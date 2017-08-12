#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define MAX 100001

int n;
bool chk[MAX];
vector<int> adj[MAX]; // adj[A][B] -> A도시에서 갈 수 있는 B번째 길.
// int num_path;
// long long len_sum;
double answer;
int trace[MAX];
void dfs(int cur, long long len, double probability) {
	trace[len] = cur;
	bool more_path = false;
	int num_possible_path = 0;
	for (int i=0; i < adj[cur].size(); i++) {
		int next_city = adj[cur][i];
		if (!chk[next_city])
			num_possible_path++;
	}
	for (int i=0; i < adj[cur].size(); i++) {
		int next_city = adj[cur][i];
		if (!chk[next_city]) {
			more_path = true;
			chk[next_city] = true;
			dfs(next_city, len+1, probability / num_possible_path);
			chk[next_city] = false;
		}
	}
	
	//dump trace
	if (len > 0 && more_path == false) {
		answer += len * probability;
		// cout << "len=" << len << " probability=" << probability << endl;
		// for (int i=0; i <= len; i++) {
		// 	cout << trace[i] << ' ';		
		// }
		// cout << endl;
		
		// num_path++;
		// len_sum += len;
	}
	// if (len > 0 && more_path == false) {
	// }
}

int main() {
	cin >> n;
	for (int i=1; i < n; i++) {
		int src, dst;
		cin >> src >> dst;
		adj[src].push_back(dst);
		adj[dst].push_back(src);
	}
	//1번도시 방문함
	chk[1] = true;
	dfs(1, 0, (double)1);
	
	printf("%.14lf\n", answer);
	// printf("%.14lf\n", ((double)len_sum)/((double)num_path));

}