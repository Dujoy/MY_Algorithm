#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map <string , vector <string> > adj;
map <string , ll > lev;
queue <string> q;
map <string , string> par;

void BFS(string s) {
    lev.clear();
    lev[s] = 1;
    q.push(s);
    while(!q.empty()) {
        string u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(lev[v] == 0) {
               lev[v] = lev[u] + 1;
               par[v] = u;
               q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    adj.clear();
    par.clear();
    for(ll i = 0; i < n; i++) {
        string u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s , t;
    cin >> s >> t;
    string st = t;
    BFS(s);
    vector <pair<string , string>> ans;
    cout <<"\n";
    while(!par[t].empty()) {
        ans.push_back({par[t] , t});
        t = par[t];
    }
    ans.push_back({s , s});
    reverse(ans.begin() , ans.end());
    cout << s <<" "<< "to" <<" "<< st <<" ";
    cout <<"Shortest path is:" ;
    for(auto u : ans) {
        cout << u.second <<" ";
    }
    return 0;
}
