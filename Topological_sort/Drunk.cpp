#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e5 + 8;

vector <vector<ll> > Graph(10011);
vector <ll> vis(10011 , 0);
bool ok = false;

void DFS(ll a) {
    vis[a] = 1;
    if(vis[a] == 0) {
        ok = true;
        return;
    }
    for(auto u : Graph[a]) {
        if(vis[u] == 0) {
            vis[u] = true;
            DFS(u);
        }
        else if(vis[u] == 1) {
            ok = true;
            return;
        }
    }
    vis[a] = 2;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin >> t;
   ll cas = 1;
   while(t--) {
      ll n;
      cin >> n;
      ll col = 0;
      for (ll i = 0; i < 10011; i++){
          Graph[i].clear();
          vis[i] = 0;
      }
      map <string , ll> mp;
      for(ll i = 0; i < n; i++) {
        string u , v;
        cin >> u >> v;
        if (mp.find(u) == mp.end()) mp[u] = col++;
        if (mp.find(v) == mp.end()) mp[v] = col++;
        Graph[mp[u]].push_back(mp[v]);
      }
      ok = false;
      for(ll i = 0; i < col; i++){
         if(vis[i] == 0) {
            DFS(i);
         }
      }
      if(!ok) cout<<"Case "<< cas++ <<": Yes"<<endl;
      else cout<<"Case "<< cas++ <<": No"<<endl;
   }
   return 0;
}
