#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e5 + 6;

ll dis[INF];
vector <ll> Graph[INF];
queue <ll> q;
vector <vector <ll>> cm;
vector <ll> cur_con_comp;

bool vis[INF];

void BFS(ll a) {
    dis[a] = 1;
    q.push(a);
    vis[a]= true;
    cur_con_comp.push_back(a);
    while(!q.empty()) {
        ll parent = q.front();
        q.pop();
        for(auto child : Graph[parent]) {
            if(vis[child] == false) {
                dis[child] = dis[parent] + 1;
                vis[child] = true;
                cur_con_comp.push_back(child);
                q.push(child);
            }
        }
    }
}

void Strangelove(){
    ll n , m;
    cin >> n >> m;
    memset(dis , 0 , sizeof(m));
    for(ll i = 0; i < m; i++) {
       ll u , v;
       cin >> u >> v;
       Graph[u].push_back(v);
       Graph[v].push_back(u);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
         if(vis[i] == false) {
             cur_con_comp.clear();
             BFS(i);
             cm.push_back(cur_con_comp);
             ans++;
         }
    }
    cout <<"The Connected components existing in this Graph:"<<" ";
    cout << ans <<"\n";
    cout <<"Vertex :" <<"\n";
    for(auto u : cm) {
       for(auto vertex : u) {
         cout << vertex <<" ";
       }
       cout <<"\n";
    }
    /*
    You also print this
    for(ll i = 0; i < cm.size(); i++) {
        for(ll j = 0; j < cm[i].size(); i++) {
            cout << cm[i][j] <<" ";
        }
        cout <<"\n";
    }*/
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}
