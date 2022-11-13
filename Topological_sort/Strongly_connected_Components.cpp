#include <bits/stdc++.h>
using namespace std;

vector <int> G[100] , Ga[100];
vector <bool> vis;
stack <int> s;
int decit[1009];

void Dfs(int source) {
    decit[source] = 1;
    for(auto u : G[source]) {
        if(decit[u] == 0) {
            Dfs(u);
        }
    }
    s.push(source);
    decit[source] = 2;
}

void Dfs2(int source) {
    decit[source] = 1;
    for(auto u : Ga[source]) {
        if(decit[u] == 0) {
            Dfs2(u);
        }
    }
    decit[source] = 2;
}

void init()
{
    for(int i = 0; i < 1008; i++) {
       G[i].clear();
       Ga[i].clear();
       decit[i]=0;
    }
}

int main() {
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u , v;
        cin >> u >> v;
        G[u].push_back(v);
        Ga[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(decit[i] == 0) {
            Dfs(i);
        }
    }
    memset(decit , 0 , sizeof(decit));
    int components = 0 , x = 0;
    while(!s.empty()){
        x = s.top();
        if(decit[x]==0) {
           components++;
           Dfs2(x);
        }
        s.pop();
    }
    cout << components <<"\n";
    return 0;
}
