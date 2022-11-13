#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    ll x;
    cin >> x;
    ll ans = -1 ,  l = 0 , r = n - 1;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(v[mid] == x) {
            ans = mid;
            if(mid > 0) {
                if(v[mid] == v[mid - 1]) {
                    r = mid - 1;
                }
                else break;
            }
            else break;
        }
        else if(v[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    if(ans == -1) cout <<"-1" <<" "<<"-1\n";
    else {
       ll ans1 = -1 , l = 0 , r = n - 1;
       while(l <= r) {
           ll mid = (l + r) / 2;
           if(v[mid] == x) {
               ans1 = mid;
               if(mid < n - 1) {
                   if(v[mid] == v[mid + 1]) {
                       l = mid + 1;
                   }
                   else break;
               }
               else break;
           }
           else if(v[mid] < x) l = mid + 1;
           else r = mid - 1;
       }
       cout << ans <<" "<< ans1 <<"\n";
    }
    return 0;
}

