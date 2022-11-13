#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e5 + 6;

ll dis[INF];
vector <ll> Graph[INF];
queue <ll> q;
map <ll , ll> path;

void BFS(ll a) {
    dis[a] = 1;
    q.push(a);
    path[a] = -1;
    while(!q.empty()) {
        ll parent = q.front();
        q.pop();
        for(auto child : Graph[parent]) {
            if(dis[child] == 0) {
                dis[child] = dis[parent] + 1;
                path[child] = parent;
                q.push(child);
            }
        }
    }
}

void Strangelove(){
    ll n , m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
       ll u , v;
       cin >> u >> v;
       Graph[u].push_back(v);
       Graph[v].push_back(u);
    }
    BFS(1);
    vector <pair<ll , ll>> v;
    while(path[n] != 0) {
       v.push_back({path[n] , n});
       n = path[n];
    }
    reverse(v.begin() , v.end());
    cout <<"The shortest Path is : ";
    for(auto u : v) cout << u.second <<" ";
    cout <<"\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}

