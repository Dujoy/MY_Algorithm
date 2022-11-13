#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll getsum (ll a) {
   return ((a * (a + 1)) / 2);
}

void Strangelove() {
   ll n;
   cin >> n;
   ll l = 1 , r = 1e5 , ans = -1;
   while(l <= r) {
      ll mid = (l + r) >> 1;
      if(getsum(mid) == n) {
         ans = mid;
         break;
      }
      else if(getsum(mid) < n) l = mid + 1;
      else r = mid - 1;
   }
   if(ans < 0) cout <<"NAI\n";
   else cout << ans <<"\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin >> t;
   while(t--) {
     Strangelove();
   }
   return 0;
}

