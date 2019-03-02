#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc=1; tc <= t; tc++) {
        int n;
        cin >> n;
        unordered_map<string, string> start, end;
        list<string> seq;
        
        
        string a, b;
        cin >> a >> b;
        seq.push_back(a);
        seq.push_back(b);
        
        for (int i=1; i < n; i++) {
            string src, dst;
            cin >> src >> dst;
            start[src] = dst;
            end[dst] = src;
        }
        
        while(start.find(b) != start.end() or end.find(a) != end.end()) {
            if (start.find(b) != start.end()) {
                string next = start[b];
                seq.push_back(next);
                start.erase(b);
                end.erase(next);
                b = next;
                
            }
            if (end.find(a) != end.end()) {
                string prev = end[a];
                seq.push_front(prev);
                end.erase(a);
                start.erase(prev);
                a = prev;
                
            }
        }
        
        cout << "Case #" << tc << ": ";
        string previous = "";
        for (auto it : seq) {
            if (previous != "") {
                cout << previous << '-' << it << ' ';
            }
            // cout << it << ' ';
            previous = it;
        }
        cout << '\n';
        
        start.clear();
        end.clear();
        seq.clear();
    }
	return 0;
}

