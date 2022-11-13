#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector <pair<ll , pair<ll , ll>>> pq;
map <string , ll> mp;
int parent[1000];

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        pq.clear();
        while(true) {
            int u , v , cost;
            cin >> u >> v >> cost;
            if(u == 0 && v == 0 && cost == 0) break;
            pq.push_back({cost , {u , v}});
        }
        for(int i = 0; i < 1000; i++) parent[i] = i;
        sort(pq.begin() , pq.end());
        int min_cost = 0;
        for(int i = 0; i < pq.size(); i++) {
            int uu = Find(pq[i].second.first);
            int vv = Find(pq[i].second.second);
            if(uu != vv) {
                Union(uu , vv);
                min_cost +=pq[i].first;
            }
        }
        for(int i = 0; i < 1000; i++) parent[i] = i;
        sort(pq.rbegin() , pq.rend());
        int max_cost = 0;
        for(int i = 0; i < pq.size(); i++) {
            int uu = Find(pq[i].second.first);
            int vv = Find(pq[i].second.second);
            if(uu != vv) {
                Union(uu , vv);
                max_cost += pq[i].first;
            }
        }
        max_cost +=  min_cost;
        if(max_cost % 2 == 0) cout <<"Case" <<" "<< tc << ":"<<" "<< max_cost / 2 <<"\n";
        else cout <<"Case" <<" "<< tc << ":"<<" "<< max_cost <<"/"<< 2 <<"\n";
    }
    return 0;
}
