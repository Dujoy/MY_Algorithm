#include<bits/stdc++.h>
using namespace std;
const int Maxn = 800;
using ll = long  long;
const ll infLL = 9000000000000000000;

vector <pair<ll , ll>> adj[Maxn];
ll dist[Maxn];

void Dijkstra(ll source , ll n) {
    for(ll i = 0; i < n; i++) dist[i] = infLL;
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
            ll mx_cost = max(Cur_Dist , w);
            if(mx_cost < dist[v]) {
                dist[v] = mx_cost;
                pq.push({dist[v] , v});
            }
        }
    }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin >> t;
   for(int tc = 1; tc <= t; tc++) {
        ll n , m;
        cin >> n >> m;
        for(ll i = 0; i < n; i++) adj[i].clear();
        for(ll i = 1; i <= m; i++) {
           ll u , v , w;
           cin >> u >> v >> w;
           adj[u].push_back({v , w});
           adj[v].push_back({u , w});
        }
        ll T;
        cin >> T;
        Dijkstra(T , n);
        cout << "Case " << tc << ":\n";
        for(ll i = 0; i < n; i++) {
            cout << i <<" ";
            if(dist[i] == infLL) cout << "Impossible\n";
            else cout << dist[i] <<"\n";
        }
   }
   return 0;
}

