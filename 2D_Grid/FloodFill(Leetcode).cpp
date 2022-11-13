#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dx[] = {0,  0, -1, 1};
ll dy[] = {-1, 1,  0, 0};

ll n , m , val;
ll first[20][20];
bool vis[100][100];

bool ok = false;

void dfs(ll r , ll c , ll grid[20][20] , ll color , int previous) {
    if (r < 0 || r == n || c < 0 || c == m || vis[r][c] == true || grid[r][c] != previous) return;
    grid[r][c] = color;
    vis[r][c] = true;
    for(ll i = 0; i < 4; i++) {
        ll x = dx[i] + r;
        ll y = dy[i] + c;
        if(x >= 0 && x < n && y >= 0 && y < m) {
            dfs(x , y , grid , color , previous);
        }
    }
}


void Strangelove(){
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) cin >> first[i][j];
    }
    ll row , col;
    cin >> row >> col;
    int color1;
    cin >> color1;
    memset(vis , false , sizeof(vis));
    dfs(row , col , first , color1 , first[row][col]);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cout << first[i][j] <<" ";
        }
        cout <<"\n";
    }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   Strangelove();
   return 0;
}

