#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Maxn = 30001;

vector <ll> Graph[10001] , Costn[10001];
ll dis[Maxn];
bool vis[Maxn];
queue <ll> q;

ll BFS(ll a) {
    vis[a] = true;
    q.push(a);
    ll maximum_val = 0 , maximum_node = a;
    while(!q.empty()) {
        ll parent = q.front();
        q.pop();
        for(ll i = 0; i < Graph[parent].size(); i++) {
            ll child = Graph[parent][i];
            if(vis[child] == false) {
                vis[child] = true;
                dis[child] = dis[parent] + Costn[parent][i];
                q.push(child);
                if(dis[child] > maximum_val) {
                    maximum_val = dis[child];
                    maximum_node = child;
                }
            }
        }
    }
    return maximum_node;
}



int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ll n;
   cin >> n;
   for(ll i = 0; i < n - 1; i++) {
       ll u , v , x;
       cin >> u >> v >> x;
       Graph[u].push_back(v);
       Graph[v].push_back(u);
       Costn[u].push_back(x);
       Costn[v].push_back(x);
   }
   ll ans = BFS(0);
   ans = BFS(ans);
   cout << dis[ans] <<"\n";
   return 0;
}
