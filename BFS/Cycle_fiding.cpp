#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e5 + 6;

bool vis[INF];
vector <ll> Graph[INF];
queue <ll> q;
map <ll , ll> path;
vector <ll> Cycle_print;

bool BFS(ll a) {
    vis[a] = true;
    q.push(a);
    path[a] = a;
    while(!q.empty()) {
        ll parent = q.front();
        q.pop();
        for(auto child : Graph[parent]) {
            if(vis[child] == false) {
                vis[child] = true;
                path[child] = parent;
                q.push(child);
            }
            else {
                if(path[parent] != child) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Strangelove(){
    ll m , n;
    cin >> m >> n;
    for(ll i = 0; i < n; i++) {
       ll u , v;
       cin >> u >> v;
       Graph[u].push_back(v);
       Graph[v].push_back(u);
    }
    ll ans = 0;
    for(ll i = 1; i <= m; i++) {
        if(vis[i] == false) {
           if(BFS(i)) ans++;
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

