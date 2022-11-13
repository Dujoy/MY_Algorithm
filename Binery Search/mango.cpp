#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/* [💭] [💡] [🎈] */

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    ll lo = 0 , hi = n - 1 , ans = -1;
    while(lo <= hi) {
        ll mid = lo + (lo + hi) / 2;
        if((mid == 0 or v[mid - 1] < v[mid]) and (mid == n - 1 or v[mid + 1] < v[mid])){
            ans = mid;
            break;
        }
        if(mid > 0 and v[mid - 1] > v[mid]) hi = mid - 1;
        else if(mid < n - 1 and v[mid] < v[mid + 1]) lo = mid + 1;
    }
    cout << ans <<"\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ll t;
   cin >> t;
   while(t--) {
     solve();
   }
   return 0;
}
