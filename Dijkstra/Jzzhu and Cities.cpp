#include<bits/stdc++.h>
using namespace std;
using ll = long  long;
const int Maxn = 1e5 + 123;
const ll infLL = 9000000000000000000;

vector <pair<pair<ll , ll> , ll>> adj[Maxn];
priority_queue <pair<ll , ll> , vector<pair<ll , ll>>, greater<pair<ll , ll>>> pq;
ll dist[Maxn];
ll train[Maxn];

void Dijkstra(ll source , ll n) {
    for(int i = 0; i <= n; i++) dist[i] = infLL;
    dist[source] = 0;
    train[source] = 0;
    pq.push({0 , source});
    while(!pq.empty()) {
        ll u = pq.top().second;
        ll Cur_Dist = pq.top().first;
        pq.pop();
        if (dist[u] < Cur_Dist) continue;
        for(auto p : adj[u]) {
            ll v = p.first.first;
            ll w = p.first.second;
            ll type = p.second;
            if(Cur_Dist + w < dist[v]) {
                dist[v] = Cur_Dist + w;
                train[v] = type;
                pq.push({dist[v] , v});
            }
            else if(Cur_Dist + w == dist[v] && (train[v] == 1 && type == 0)) {
                dist[v] = Cur_Dist + w;
                train[v] = type;
            }
        }
    }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ll n , m , k;
   cin >> n >> m >> k;
   for(ll i = 1; i <= m; i++) {
       ll u , v , w;
       cin >> u >> v >> w;
       adj[u].push_back({{v , w} , 0});
       adj[v].push_back({{u , w} , 0});
   }
   for(ll i = 1; i <= k; i++) {
      ll u , w;
      cin >> u >> w;
      adj[1].push_back({{u , w} , 1});
      adj[u].push_back({{1 , w} , 1});
   }
   Dijkstra(1 , n);
   ll ans = 0;
   for(ll i = 1; i <= n; i++) ans += train[i];
   cout << k - ans <<"\n";
   return 0;
}
