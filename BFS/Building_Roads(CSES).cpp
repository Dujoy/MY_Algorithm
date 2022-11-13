#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e5 + 6;

ll dis[INF];
vector <ll> Graph[INF];
queue <ll> q;
vector <vector <ll>> cm;
vector <ll> cur_con_comp;

bool vis[INF];

void BFS(ll a) {
    dis[a] = 1;
    q.push(a);
    vis[a]= true;
    cur_con_comp.push_back(a);
    while(!q.empty()) {
        ll parent = q.front();
        q.pop();
        for(auto child : Graph[parent]) {
            if(vis[child] == false) {
                dis[child] = dis[parent] + 1;
                vis[child] = true;
                q.push(child);
            }
        }
    }
}

void Strangelove(){
    ll n , m;
    cin >> n >> m;
    memset(dis , 0 , sizeof(m));
    for(ll i = 0; i < m; i++) {
       ll u , v;
       cin >> u >> v;
       Graph[u].push_back(v);
       Graph[v].push_back(u);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
         if(vis[i] == false) {
             BFS(i);
             ans++;
         }
    }
    cout << ans - 1 <<"\n";
    reverse(cur_con_comp.begin() , cur_con_comp.end());
    cur_con_comp.pop_back();
    sort(cur_con_comp.begin(), cur_con_comp.end());
    for(auto u : cur_con_comp) cout << u - 1 <<" "<< u <<"\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}
