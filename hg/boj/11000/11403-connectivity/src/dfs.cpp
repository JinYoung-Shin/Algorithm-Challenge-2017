#include <bits/stdc++.h>
using namespace std;

bool mat[100][100];

bool visited[100];
int n;
void dfs(int start) {
    for (int i=0; i < n; i++) {
        if (i == start) continue;
        if (visited[i]) continue;
        if (mat[start][i]) {
            visited[i] = true;
            dfs(i);    
        }
    }
}
void check(int start) {
    memset(visited, 0, n);
    dfs(start);
}

int main() {
    
    cin >> n;
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    
    for (int i=0; i < n; i++) {
        check(i);
        for (int j=0; j < n;j++) {
            cout << visited[j] << ' ';
        }
        cout << '\n';
    }
}