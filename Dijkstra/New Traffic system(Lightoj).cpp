#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1e4 + 123;
using ll = long  long;
const ll infLL = 1000000000000000000;

vector <vector <ll>> adj[Maxn];
ll dist[12][Maxn];

void dijkstra(ll source , ll n , ll d) {
    for(ll i = 0; i <= d; i++) {
        for(ll j = 0; j < n; j++) {
            dist[i][j] = infLL;
        }
    }
    priority_queue<vector <ll>, vector <vector<ll>> , greater<vector<ll>>> pq;
    dist[0][source] = 0;
    pq.push({0 , 0 , source});
    while(!pq.empty()) {
        ll CurD = pq.top()[0];
        ll cnt = pq.top()[1];
        ll u = pq.top()[2];
        pq.pop();
        if(dist[cnt][u] < CurD) continue;
        for(auto e : adj[u]) {
            ll v = e[0];
            ll w = e[1];
            ll type = e[2];
            if (cnt + type <= d && dist[cnt][u] + w < dist[cnt+type][v] ) {
               dist[cnt+type][v] = dist[cnt][u] + w;
               pq.push ({dist[cnt+type][v] , cnt+type , v});
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
      ll n , m , k , d;
      cin >> n >> m >> k >> d;
      for(ll i = 0; i < n; i++) adj[i].clear();
      for(ll i = 0; i < m; i++) {
         int u , v , w;
         cin >> u >> v >> w;
         adj[u].push_back({v , w , 0});
      }
      for(ll i = 0; i < k; i++) {
         int u , v , w;
         cin >> u >> v >> w;
         adj[u].push_back({v , w , 1});
      }
      dijkstra(0 , n , d);
      ll ans = infLL;
      for(ll i = 0; i <= d; i++) ans = min(ans , dist[i][n - 1]);
      if(ans == infLL) cout <<"Case" <<" "<< tc << ":"<<" "<< "Impossible" <<"\n";
      else cout <<"Case" <<" "<< tc << ":"<<" "<< ans <<"\n";
   }
   return 0;
}
