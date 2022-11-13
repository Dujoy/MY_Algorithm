#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Maxn = 2e5 + 10;

map <ll , ll> par;
bool vis[Maxn];
vector <ll> G[Maxn];
ll distace[Maxn];
queue <ll> q;

void BFS(ll a) {
    vis[a] = true;
    q.push(a);
    while(!q.empty()) {
        ll v = q.front();
        q.pop();
        for(auto u : G[v]) {
            if(vis[u] == false) {
                vis[u] = true;
                distace[u] = distace[v] + 1;
                q.push(u);
            }
        }
    }
}

void Strangelove() {
    ll n , m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        G[i].clear();
        distace[i] = 0;
    }
    for(ll i = 0; i < m; i++) {
        ll u , v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    BFS(1);
    cout << distace[n] <<"\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin >> t;
   while(t--) {
      Strangelove();
   }
   return 0;
}
