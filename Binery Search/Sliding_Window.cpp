#include<bits/stdc++.h>
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
    ll sum = 0 , j = 0 , aa = 0;
    bool ok = false;
    ll mi = 2E9;
    while(j < n) {
        sum += v[j];
        if(sum >= x) {
            mi = min(mi , j - aa + 1);
            ok = true;
            while(sum >= x) {
                sum -= v[aa];
                aa++;
                if(sum >= x) {
                   mi = min(mi , j - aa + 1);
                }
                else continue;
            }
        }
        j++;
    }
    if(ok) cout << mi <<"\n";
    else cout <<"0\n";
    return 0;
}
