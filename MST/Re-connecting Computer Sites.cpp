#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector <pair<int , pair<int ,int>>> p;
int parent[10000001];

int Find(int a) {
    if(a == parent[a]) return a;
    return(parent[a] = Find(parent[a]));
}

void Union(int u, int v){
    int p = Find(u);
    int q = Find(v);
    if (p != q) parent[q] = p;
}

int main() {
    int n , x , y , c , ox = 0;
    while(scanf("%d",&n) == 1) {
        p.clear();
        if(ox != 0) cout <<"\n";
        ox = 1;
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        int old_cost = 0 , new_cost = 0;
        for(int i = 1; i <= n - 1; i++) {
            cin >> x >> y >> c;
            old_cost += c;
            p.push_back({c , {x , y}});
        }
        int m;
        cin >> m;
        for(int i = 1; i <= m; i++) {
            cin >> x >> y >> c;
            p.push_back({c , {x , y}});
        }
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++) cin >> x >> y >> c;
        sort(p.begin() , p.end());
        for(int i = 0; i < n + m - 1; i++) {
            int u = Find(p[i].second.first);
            int v = Find(p[i].second.second);
            if(u != v) {
                new_cost += p[i].first;
                Union(u , v);
            }
        }
        printf("%d\n%d\n" , old_cost , new_cost);
    }
    return 0;
}

