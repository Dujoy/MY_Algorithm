#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 123;
using ll = long  long;
const ll infLL = 9000000000000000000;

vector <pair<ll , ll>> adj[Maxn];
ll dist[Maxn];
ll par[Maxn];

void Dijkstra(ll source , ll n) {
    for(ll i = 1; i <= n; i++) dist[i] = infLL;
    priority_queue <pair<ll , ll> , vector<pair<ll , ll>>, greater<pair<ll , ll>>> pq;
    dist[source] = 0;
    pq.push({0 , source});
    while(!pq.empty()) {
        ll parent_cost = pq.top().first;
        ll parent_location = pq.top().second;
        pq.pop();
        if(parent_cost > dist[parent_location]) continue;
        for(auto u : adj[parent_location]) {
            ll child_cost = u.second;
            ll child_location = u.first;
            if(child_cost + parent_cost < dist[child_location]) {
                dist[child_location] = child_cost + parent_cost;
                par[child_location] = parent_location;
                pq.push({dist[child_location] , child_location});
            }
        }
    }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ll n , m;
   cin >> n >> m;
   vector <ll> shortest_path;
   for(ll i = 1; i <= m; i++) {
       int u , v , w;
       cin >> u >> v >> w;
       adj[u].push_back({v , w});
       adj[v].push_back({u , w});
   }
   Dijkstra(1 , n);
   if(dist[n] == infLL) {
       cout <<"-1\n";
       exit(0);
   }
   ll path = n;
   shortest_path.push_back(n);
   while(par[path] != 0) {
       shortest_path.push_back(par[path]);
       path = par[path];
   }
   reverse(shortest_path.begin() , shortest_path.end());
   for(auto u : shortest_path) cout << u <<" ";
   cout <<"\n";
   return 0;
}
