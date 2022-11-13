#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1, 0, -1, 1, 0, -1, 1, -1};

char c[101][101];
bool vis[101][101];
ll n , m;

void Bfs(ll x , ll y) {
    vis[x][y] = true;
    queue <pair<ll , ll>> q;
    q.push({x , y});
    while(!q.empty()) {
        pair <ll , ll> p = q.front();
        ll x = p.first , y = p.second;
        q.pop();
        for(ll i = 0; i < 8; i++) {
           ll next_x = x + dx[i];
           ll next_y = y + dy[i];
           if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && c[next_x][next_y] == '@' && vis[next_x][next_y] == false) {
               vis[next_x][next_y] = true;
               q.push({next_x , next_y});
           }
        }
    }
}


void Strangelove(){
    cin >> n >> m;
    while(n != 0) {
      memset(vis, false , sizeof(vis));
      for(ll i = 0; i < n; i++) {
         for(ll j = 0; j < m; j++) {
            cin >> c[i][j];
         }
      }
      ll ans = 0;
      for(ll i =0; i < n; i++) {
         for(ll j = 0; j < m; j++) {
           if(c[i][j] == '@' && vis[i][j] == false) {
               ans++;
               Bfs(i , j);
           }
         }
      }
      cout << ans <<"\n";
      cin >> n >> m;
    }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}
