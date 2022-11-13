#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/* [💭] [💡] [🎈] */

vector <int> g[7]; /// adj[i] is a vector, which stores
bool vis[100]; /// To check if i'th node is visited or not.
vector <vector <ll>> cc;
vector <ll> cur_con_comp;

ll ans = 0;

void DFS(ll start) {
    vis[start] = 1;
    cur_con_comp.push_back(start);
    for(auto u : g[start]) {
        if(vis[u] == false) {
            DFS(u);
        }
    }
}


void Strangelove() {
   ll nodes , edges;
   cin >> nodes >> edges;
   for(ll i = 0; i < edges; i++) {
       ll u , v;
       cin >> u >> v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   for(ll i = 1; i <= nodes; i++) {
       if(vis[i] == false) {
           cur_con_comp.clear();
           DFS(i);
           cc.push_back(cur_con_comp);
           ans++;
       }
   }
   for(auto u : cc) {
      for(auto vertex : u) {
         cout << vertex <<" ";
      }
      cout <<"\n";
   }
   cout << ans <<"\n";
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}

