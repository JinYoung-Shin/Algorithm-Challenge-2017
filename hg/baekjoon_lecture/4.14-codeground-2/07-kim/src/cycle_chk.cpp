#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

vector<vector<int> > adj; //adjacent list
vector<bool> visited;

// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.
bool isCyclicUtil(int v, int parent)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < adj[v].size(); ++i)
    {
		int current = adj[v][i];
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[current])
        {
           if (isCyclicUtil(current, v))
              return true;
        }
 
        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (current != parent) {
			// printf("Found! - (i:%d) (parent:%d)\n", current, parent);
           return true;
		}
    }
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
bool isCyclic(int N)
{

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int u = 1; u <= N; u++)
        if (!visited[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u, -1))
             return true;
    return false;
}

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	   C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        int n, l;
		cin >> n >> l;
		
		// printf("(n=%d\tl=%d)\n", n, l);
		adj.clear();
		visited.clear();
		
        adj.reserve(n+1);
		visited.resize(n+1, false);
		for (int i=0; i < l; i++) {
			int a,b;
			cin >> a >> b;
			// printf("<%d, %d>\n", a,b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
        
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		cout << (isCyclic(n) ? 0 : 1) << endl;
        
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}