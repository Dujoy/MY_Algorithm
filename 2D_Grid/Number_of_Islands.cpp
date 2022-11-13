#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Maxn = 2e5 + 8;

int dx[] = {1 , 0 , -1,  0};
int dy[] = {0 , 1 ,  0, -1};

ll v[3001][3001];
ll vis[4][4];
queue <pair<ll , ll>> q;

bool is_valid(ll xx , ll yy) {
   return (xx >= 0 && xx < 4 && yy >= 0 && yy < 4);
}

void Bfs(ll a , ll b) {
    q.push({a , b});
    vis[a][b] = 1;
    while(!q.empty()) {
        pair <ll , ll> p = q.front();
        ll x = p.first , y = p.second;
        q.pop();
        for(ll i = 0; i < 4; i++) {
            ll next_x = x + dx[i];
            ll next_y = y + dy[i];
            if(!is_valid(next_x , next_y) || v[next_x][next_y] == 0) continue;
            if(!vis[next_x][next_y] && v[next_x][next_y] == 1) {
                q.push({next_x , next_y});
                vis[next_x][next_y] = 1;
            }
        }
    }
}

void Reset() {
   for(ll i = 0; i < 4; i++) {
      for(ll j = 0; j < 4; j++) {
          vis[i][j] = 0;
      }
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n , m;
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    Reset();
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(!vis[i][j] && v[i][j] == 1) {
                ans++;
                Bfs(i , j);
            }
        }
    }
    cout << ans <<"\n";
    return 0;
}
