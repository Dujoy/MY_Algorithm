#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e5 + 6;

vector <ll> Graph[INF];
bool vis[INF];
queue <ll> q;
bool ok;

void BFS(ll a) {
    q.push(a);
    vis[a] = true;
    while(!q.empty()) {
        ll parent = q.front();
        q.pop();
        if(Graph[parent].size() != 2) ok = false;
        for(ll i = 0; i < Graph[parent].size(); i++) {
            ll child = Graph[parent][i];
            if(vis[child] == false) {
                vis[child] = true;
                q.push(child);
            }
        }
    }
}


void Strangelove(){
    ll n , m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
       ll u , v;
       cin >> u >> v;
       u-- , v--;
       Graph[u].push_back(v);
       Graph[v].push_back(u);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
         if(vis[i] == false) {
             ok = true;
             BFS(i);
             if(ok) ans++;
         }
    }
    cout << ans <<"\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}

