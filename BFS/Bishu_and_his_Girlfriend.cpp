#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mx = 10001;

vector <int> g[Mx] ;
bool vis[Mx];
ll dis[Mx];
queue <ll> Q;
ll mi = 10003;

void BFS(ll source) {
    vis[source] = true;
    Q.push(source);
    dis[source] = 0;
    while(!Q.empty()) {
         ll parent = Q.front();
         Q.pop();
         for(auto child : g[parent]) {
             if(vis[child] == false) {
                 vis[child] = true;
                 dis[child] = dis[parent] + 1;
                 Q.push(parent);
             }
         }
    }
}

void Reset() {
    for(ll i = 0; i <= 10001; i++) {
        dis[i] = INT_MAX;
        vis[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0; i < n - 1; i++) {
         ll a , b;
         cin >> a >> b;
         g[a].push_back(b);
         g[b].push_back(a);
    }
    Reset();
    BFS(1);
    ll number_of_girls;
    cin >> number_of_girls;
    vector <ll> v;
    while(number_of_girls--) {
        ll girls;
        cin >> girls;
        v.push_back(girls);
    }
    ll ans = 0;
    for(ll i = 0; i < v.size(); i++) {
        ll dif = dis[v[i]];
        if(mi > dif) {
            mi = dif;
            ans = v[i];
        }
        else continue;
    }
    cout << ans <<"\n";
    return 0;
}
