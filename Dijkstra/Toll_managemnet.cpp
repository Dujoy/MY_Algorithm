#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 123;
using ll = long  long;
const ll infLL = 1000000000000000000;

vector <pair<ll , ll>> adj[3][Maxn];
ll dist[3][Maxn];

struct information {
    ll u , v , w;
};

void Dijkstra(ll source , ll n , ll type) {
    for(ll i = 1; i <= n; i++) dist[type][i] = infLL;
    dist[type][source] = 0;
    priority_queue<pair<ll , ll>, vector <pair<ll ,ll>>, greater<pair<ll , ll>>> pq;
    pq.push({0  , source});
    while(!pq.empty()) {
        ll u = pq.top().second;
        ll curD = pq.top().first;
        pq.pop();
        if(dist[type][u] < curD) continue;
        for(auto e : adj[type][u]) {
            ll v = e.first;
            ll w = e.second;
            if(curD + w < dist[type][v]) {
                dist[type][v] = curD + w;
                pq.push({dist[type][v] , v});
            }
        }
    }

}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin >> t;
   for(ll tc = 1; tc <= t; tc++){
      ll n , m , s , t , p;
      cin >> n >> m >> s >> t >> p;
      for(ll i = 1; i <= n; i++) {
         adj[0][i].clear();
         adj[1][i].clear();
      }
      vector <information> edges;
      for(ll i= 0; i < m; i++) {
         ll u , v , w;
         cin >> u >> v >> w;
         adj[0][u].push_back({v , w});
         adj[1][v].push_back({u , w});
         edges.push_back({u , v , w});
      }
      Dijkstra(s,  n , 0);
      Dijkstra(t , n , 1);
      ll ans = -1;
      for(auto e : edges) {
         ll u = e.u;
         ll v = e.v;
         ll w = e.w;
         ll cost = dist[0][u] + w + dist[1][v];
         if(cost <= p) ans = max(ans , w);
      }
      cout <<"Case" <<" "<< tc << ":"<<" "<< ans <<"\n";
   }
   return 0;
}
