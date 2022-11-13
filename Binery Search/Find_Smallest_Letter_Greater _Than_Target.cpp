#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector <char> c(n);
    for(ll i = 0; i < n; i++) cin >> c[i];
    char a;
    cin >> a;
    ll l = 0 , r = n - 1;
    if(c[r] == a) {
        cout << a <<"\n";
        exit(0);
    }
    char ans;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(c[mid] > a) {
            r = mid - 1;
        }
        else if(c[mid] < a) {
            l = mid + 1;
        }
        else l = mid + 1;
    }
    cout << c[l] <<"\n";
    return 0;
}
