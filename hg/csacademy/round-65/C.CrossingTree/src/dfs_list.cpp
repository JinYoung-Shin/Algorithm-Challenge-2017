#include <bits/stdc++.h>

using namespace std;

vector<set<int> > tree; // tree adjacency list
vector<int> dist; //distance for find diameter of tree, -1 is not visited
list<int> path;
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
bool dfs2(int pos, int goal, list<int>& path) {
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
      list<int> tmp;
      list<int> final_path;
      for(set<int>::iterator it = direct.begin(); it != direct.end(); it++) {
          int next = *it;
          if (chk[next]) continue;
        //   tmp.clear();
        tmp = new list<int>;

          if (dfs2(next, goal, tmp)) { // if there exist on [next] direction
        //   printf("dfs2(%d, %d) is final_path!!\n", next, goal);
            // for (size_t i=0; i < tmp.size(); i++) {
            //     final_path.push_back(tmp[i]); //it will be final_path which will be added finally
            // }
            final_path.merge(tmp);
          } else { // if there don't exist goal on [next] direction
            //   for (size_t i=0; i < tmp.size(); i++) {
            //       path.push_back(tmp[i]);  // path will be attached here
            //     //   printf("push_back - 2 (%d)\n", tmp[i]);
            //   }
            path.merge(tmp);
              path.push_back(pos); //and current position will be tailed.
            //   printf("push_back - 3 (%d)\n", pos);
          }
          

      }
      if (final_path.size() != 0) {
        //   for (size_t i=0; i < final_path.size(); i++) {
        //       path.push_back(final_path[i]);
        //     //   printf("push_back - 4 (%d)\n", final_path[i]);
        //   }
        path.merge(final_path);
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
        // printf("dist[%d]=%d\n", i, dist[i]);
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
        // printf("dist[%d]=%d\n", i, dist[i]);
    }
   
    int diameter = dist[v];
    int path_length = (n-1)*2 - diameter;
    //diamter = length (u, v)
    // printf("u=%d\n", u);
    // printf("v=%d\n", v);
    
    cout << path_length << endl;
    // path.reserve(path_length);
    // path.push_back(u);
    dfs2(u, v, path);
    // for (size_t i=0; i < path.size();  i++) {
    //     cout << path[i] << ' ';
    // }
    for (auto it : path) {
        cout << it << ' ';
    }
    cout << endl;
    
    //dump
    // for (int i=1; i <= n; i++) {
    //     printf("visited[%d]=%c\n", i, chk[i] ? 'O' : 'X');
    // }
    return 0;
}