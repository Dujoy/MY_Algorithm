#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e5 + 8;

vector <vector<ll> > Graph(10011);
vector <ll> vis(10011 , 0);
bool ok = false;

bool DFS(ll a) {
    if(vis[a] == 1) return false;
    vis[a] = 1;
    for(auto u : Graph[a]) {
        if(vis[u] == 0) {
            if(!DFS(u)) return false;
        }
        else if(vis[u] == 1) {
            return false;
        }
    }
    vis[a] = 2;
    return true;
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
      map <string,ll> mp;
      for(ll i = 0; i < n; i++) {
        string u , v;
        cin >> u >> v;
        if (mp.find(u) == mp.end()) mp[u] = col++;
        if (mp.find(v) == mp.end()) mp[v] = col++;
        Graph[mp[u]].push_back(mp[v]);
      }
      bool ok = false;
      for(ll i = 0; i < col; i++){
         if(vis[i] == 0) {
             if(!DFS(i)) {
                 ok = true;
                 break;
             }
         }
      }
      if(!ok) cout<<"Case "<< cas++ <<": Yes"<<endl;
      else cout<<"Case "<< cas++ <<": No"<<endl;
   }
   return 0;
}
