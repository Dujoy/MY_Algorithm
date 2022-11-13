#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Maxn = 1e5 + 7;

vector <ll> Gp[Maxn];
bool vis[50];
vector <ll> color(50 , -1);
queue <ll> Q;

bool bfs(ll node) {
    vis[node] = true;
    color[node] = 1;
    Q.push(node);
    while(!Q.empty()) {
        ll parent = Q.front();
        Q.pop();
        for(ll i = 0; i < Gp[parent].size(); i++) {
            ll child = Gp[parent][i];
            if(color[child] == color[parent]) return false;
            if(vis[child] == false && color[child] == -1) {
                vis[child] = true;
                color[child] = 1 - color[parent];
                Q.push(child);
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n , m;
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        ll a , b;
        cin >> a >> b;
        Gp[a].push_back(b);
        Gp[b].push_back(a);
    }
    if(bfs(1)) cout <<"YES it's a Bipartite Graph\n";
    else cout <<"No it's not a Bipartite Graph\n";
    return 0;
}
