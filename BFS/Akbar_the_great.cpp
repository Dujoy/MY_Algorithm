#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Maxn = 2e5 + 7;

ll n , a , b;
vector <vector <ll>> Graph;
vector <ll> vis;
vector <ll> power;
queue <ll> Q;
bool ok = true;

void BFS(ll node) {
   Q.push(node);
   vis[node] = node;
   while(!Q.empty()) {
      ll cur = Q.front();
      Q.pop();
      if(power[cur] == 0) continue;
      for(auto u : Graph[cur]) {
          if(vis[u] == 0) {
             vis[u] = node;
             power[u] = power[cur] - 1;
             Q.push(u);
          }
          else if(vis[u] != vis[cur]) ok = false;
      }
   }
}

void Reset() {
    ok = true;
    vis = vector <ll> (n + 1 , 0);
    power = vector <ll> (n + 1 , -1);
    Graph = vector <vector <ll>> (n + 1);
    for(ll i = 0; i < a; i++) {
        Graph[i].clear();
    }
}

void Strangelove() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    Reset();
    for(ll i = 0; i < a; i++) {
        ll u , v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    for(ll i = 0; i < b; i++) {
        ll node , value;
        cin >> node >> value;
        if(power[node] != -1) ok = false;
        else {
            power[node] = value;
            BFS(node);
        }
    }
    for(ll i = 1; i <= n; i++) {
        if(vis[i] == 0) {
          ok = false;
        }
    }
    if(ok) cout <<"Yes\n";
    else cout <<"No\n";
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
