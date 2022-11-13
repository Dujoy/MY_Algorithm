#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Mx = 30001;

vector <int> g[Mx] , c[Mx];
bool vis[Mx];
int dis[Mx];

int bfs(int source) {
   queue <int> Q;
   vis[source] = true;
   dis[source] = 0;
   Q.push(source);
   ll mx = 0;
   int xt = source;
   while(!Q.empty()) {
      int node = Q.front();
      Q.pop();
      for(int i = 0; i < g[node].size(); i++) {
         int next = g[node][i];
         if(vis[next] == false) {
            vis[next] = true;
            dis[next] = dis[node] + c[node][i];
            Q.push(next);
            if(dis[next] > mx) {
                cout << next <<"\n";
                xt = next;
                mx = dis[next];
            }
         }
      }
   }
   return xt;
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin >> t;
   int y = 1;
   while(t--) {
       int n;
       cin >> n;
       for(int i = 0; i <= n; i++) {
           g[i].clear();
           c[i].clear();
           vis[i] = 0;
           dis[i] = 0;
       }
       for(int i = 1; i < n; i++) {
           int v , u , x;
           cin >> v >> u >> x;
           g[v].push_back(u);
           g[u].push_back(v);
           c[v].push_back(x);
           c[u].push_back(x);
       }
       int tto = bfs(0);
       for(int i = 0; i <= n; i++) {
           vis[i] = 0;
           dis[i] = 0;
       }
       tto = bfs(tto);
       printf("Case %d: %d\n", y++ , dis[tto]);
   }
   return 0;
}
