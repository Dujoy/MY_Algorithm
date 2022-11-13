#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 40001;

vector <ll> G[INF];
bool vis[INF] , Node[INF];
ll cnt , cnt1 , ans;

void DFS(ll a , ll col) {
    vis[a] = true;
    cnt++;
    if(col == 1) cnt1++;
    ll temp;
    if(col == 1) temp = 2;
    else temp = 1;
    for(auto u : G[a]) {
        if(vis[u] == false) {
            DFS(u , temp);
        }
    }
}

void Reset() {
   for(ll i = 0; i < INF; i++) {
       G[i].clear();
       vis[i] = 0;
       Node[i] = 0;
   }
}

void Strangelove(){
   ll n;
   cin >> n;
   Reset();
   for(ll i = 0; i < n; i++) {
       ll u , v;
       cin >> u >> v;
       G[u].push_back(v);
       G[v].push_back(u);
       Node[u] = 1;
       Node[v] = 1;
   }
   ans = 0;
   for(ll i = 1; i <= INF; i++) {
        if(vis[i] == false && Node[i] == 1) {
             cnt = 0 , cnt1 = 0;
             DFS(i , 1);
             ans = max(cnt1 , cnt - cnt1);
        }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   int t;
   cin >> t;
   ll tc = 0;
   while(t--) {
     Strangelove();
     tc++;
     cout <<"Case" <<" " << tc <<":"<<" "<< ans <<"\n";
   }
   return 0;
}
