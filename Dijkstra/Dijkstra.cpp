#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 123;
using ll = long  long;
const ll infLL = 9000000000000000000;

vector <pair<ll , ll>> adj[Maxn];
ll dist[Maxn];

void Dijkstra(ll source , ll n) {
    for(int i = 0; i <= n; i++) dist[i] = infLL;
    dist[source] = 0;
    priority_queue <pair<ll , ll> , vector<pair<ll , ll>>, greater<pair<ll , ll>>> pq;
    pq.push({0 , source});
    while(!pq.empty()) {
        ll u = pq.top().second;
        ll Cur_Dist = pq.top().first;
        pq.pop();
        if (dist[u] < Cur_Dist) continue;
        for(auto p : adj[u]) {
            ll v = p.first;
            ll w = p.second;
            if(Cur_Dist + w < dist[v]) {
                dist[v] = Cur_Dist + w;
                pq.push({dist[v] , v});
            }
        }
    }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ll n , m;
   cin >> n >> m;
   for(int i = 1; i <= m; i++) {
       int u , v , w;
       cin >> u >> v >> w;
       adj[u].push_back({v , w});
       adj[v].push_back({u , w});
   }
   Dijkstra(1 , n);
   for(ll i = 1; i <= n; i++) cout << dist[i] <<" ";
   return 0;
}
