#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e5 + 10;

vector <ll> Graph[INF];
vector <ll> ans;
vector <ll> vis(INF , 0);
queue <ll> q;
bool ok = false;

void DFS(ll a) {
    vis[a] = 1;
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
    ans.push_back(a);
}

void Strangelove(){
    ll n , m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
       ll u , v;
       cin >> u >> v;
       Graph[u].push_back(v);
    }
    for(ll i = 1; i <= n; i++){
        if(vis[i] == 0){
           DFS(i);
        }
    }
    reverse(ans.begin() , ans.end());
    if(!ok) for(auto u : ans) cout << u <<" ";
    else cout <<"IMPOSSIBLE\n";
    cout <<"\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}
