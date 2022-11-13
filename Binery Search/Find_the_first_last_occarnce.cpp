#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/* [💭] [💡] [🎈] */

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    ll aa;
    cin >> aa;
    ll lo = 0 , hi = n - 1 , ans = -1 , ano_ans = -1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(v[mid] == aa) {
            ans = mid;
            hi = mid - 1;
        }
        else if(v[mid] > lo) lo = mid + 1;
        else hi = mid - 1;
    }
    lo = 0 , hi = n - 1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(v[mid] == aa) {
            ano_ans = mid;
            lo = mid + 1;
        }
        else if(v[mid] > lo) lo = mid + 1;
        else hi = mid - 1;
    }
    if(ans > -1 && ano_ans > -1) cout << ans <<" "<< ano_ans <<"\n";
    else cout <<"-1"<<" "<<"-1\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   solve();
   return 0;
}


