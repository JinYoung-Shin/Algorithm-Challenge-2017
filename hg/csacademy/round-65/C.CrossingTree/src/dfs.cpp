#include <bits/stdc++.h>

using namespace std;

vector<set<int> > tree; // tree adjacency list
vector<int> dist; //distance for find diameter of tree, -1 is not visited
vector<int> path;
vector<bool> chk; //visited
void dfs(int t) {
    for (set<int>::iterator it = tree[t].begin(); it != tree[t].end(); it++) {
        int next = *it;
        if (dist[next] == -1) {
            dist[next] = dist[t] + 1;
            dfs(next);
        }
    }    
}
bool dfs2(int pos, int goal, vector<int>& path) {
    // printf("-------dfs2(%d, %d)-------\n", pos, goal);
    chk[pos] = true;
    path.push_back(pos);
    
    // printf("push_back -1 (%d)\n", pos);
    
    auto& direct = tree[pos];
    int can_go = 0;
    for (set<int>::iterator i = direct.begin(); i != direct.end(); i++) {
        if (chk[*i] == false) can_go++;
    }
    if (pos == goal) {
        return true;
    }
    // if (direct.size() == 0) {
    if (can_go == 0) {
        return false;
    // } else if (direct.size() == 1) {
    } else if (can_go == 1) {
        int next;
       for (set<int>::iterator it = direct.begin(); it != direct.end(); it++) {
           if (chk[*it] == false) {
               next = *it;
               break;
           }
       }
        
       if (dfs2(next, goal, path)) {
           return true;
       }
       path.push_back(pos);
       return false;
//   } else if (direct.size() >= 2) {
    } else if (can_go >= 2) {
      vector<int> tmp;
      vector<int> final_path;
      for(set<int>::iterator it = direct.begin(); it != direct.end(); it++) {
          int next = *it;
          if (chk[next]) continue;
          tmp.clear();

          if (dfs2(next, goal, tmp)) { // if there exist on [next] direction
            for (size_t i=0; i < tmp.size(); i++) {
                final_path.push_back(tmp[i]); //it will be final_path which will be added finally
            }
          } else { // if there don't exist goal on [next] direction
              for (size_t i=0; i < tmp.size(); i++) {
                  path.push_back(tmp[i]);  // path will be attached here
              }
              path.push_back(pos); //and current position will be tailed.
          }
          

      }
      if (final_path.size() != 0) {
          for (size_t i=0; i < final_path.size(); i++) {
              path.push_back(final_path[i]);
          }
          return true;
      } else {
          return false;
      }
   }
   return false;
}
int main() {
    int n;
    cin >> n;
    tree.resize(n+1);
    for (int i=0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].insert(b);
        tree[b].insert(a);
    }
    dist.resize(n+1, -1);
    chk.resize(n+1, false);
    int t = 1; // random point
    dist[t] = 0;
    dfs(t);
    
    int max_val = 0;
    int u = t;
    //distance from t=1 dump
    for (int i=1; i <= n; i++) {
        if (max_val < dist[i]) {
            max_val = dist[i];
            u = i; //most far point from t
        }
    }
    
    dist.clear();
    dist.resize(n+1, -1);
    dist[u] = 0;
    dfs(u);
    
    max_val = 0;
    int v = u;
    for (int i=1; i <= n; i++) {
        if (max_val < dist[i]) {
            max_val = dist[i];
            v = i; //most far point from u
        }
    }
   
    int diameter = dist[v];
    int path_length = (n-1)*2 - diameter;
    //diamter = length (u, v)
    
    cout << path_length << endl;
    path.reserve(path_length);
    dfs2(u, v, path);
    for (size_t i=0; i < path.size();  i++) {
        cout << path[i] << ' ';
    }
    cout << endl;
    
    return 0;
}