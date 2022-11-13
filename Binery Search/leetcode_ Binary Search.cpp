#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/* [💭] [💡] [🎈] */

void solve() {
   ll n;
   cin >> n;
   vector <ll> v(n) , a;
   for(ll i = 0; i < n; i++) cin >> v[i];
   ll elm = 0;
   for(ll i = 0; i < n; i++) {
       while(v[i + 1] == v[i]) {
           i++;
       }
       a.push_back(v[i]);
   }
   for(auto u : a) cout << u <<" ";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   solve();
   return 0;
}

