#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;

char v[1111][1111];
bool vis[1111][1111];
ll n , m , ans;

int dx[] = {1, -1,  0, 0};
int dy[] = {0,  0, 1, -1};

void dfs(ll x , ll y) {
    vis[x][y] = true;
    for(ll i = 0; i < 4; i++) {
        ll next_x = x + dx[i];
        ll next_y = y + dy[i];
        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && vis[next_x][next_y] == false && v[next_x][next_y] != '#') {
            dfs(next_x , next_y);
        }
    }
}

void Strangelove(){
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(vis[i][j] == false && v[i][j] != '#') {
                dfs(i , j);
                ans++;
            }
        }
    }
    cout << ans <<"\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}
