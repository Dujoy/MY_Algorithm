#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector <pair<ll , pair<ll , ll>>> pq;
map <string , ll> mp;
int parent[10000];

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
        ll n;
        cin >> n;
        mp.clear();
        pq.clear();
        string a , b;
        ll cost , number_of_city = 1;
        ll nn = n;
        while(n--) {
            cin >> a >> b >> cost;
            if(mp[a] == 0) {
                mp[a] = number_of_city;
                number_of_city++;
            }
            if(mp[b] == 0) {
                mp[b] = number_of_city;
                number_of_city++;
            }
            pq.push_back({cost ,{mp[a] , mp[b]}});
        }
        sort(pq.begin() , pq.end());
        for(int i = 1; i <= number_of_city; i++) parent[i] = i;
        ll total_cost = 0 , not_cyc = 0;
        for(ll i = 0; i < pq.size(); i++) {
            ll u = Find(pq[i].second.first);
            ll v = Find(pq[i].second.second);
            if(u != v) {
                //cout << u <<" "<< v <<" "<< pq[i].first <<"\n";
                Union(u , v);
                total_cost += pq[i].first;
                not_cyc++;
            }
        }
        if(not_cyc != number_of_city - 2) cout <<"Case" <<" "<< tc << ":"<<" "<< "Impossible" <<"\n";
        else cout <<"Case" <<" "<< tc << ":"<<" "<< total_cost <<"\n";*/
    }
    return 0;
}
